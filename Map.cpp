#include <vcl.h>
#include <vcl\iniFiles.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <math.h>
#include <windows.h>
#include <stdio.h >
#include "Map.h"
#define min(a, b)	(((a) < (b)) ? (a) : (b))
#define max(a, b)	(((a) > (b)) ? (a) : (b))

//---------------------------------------------------------------------------
class TMap
{
	private:
		int Width, Height;
		TPoint begin, end;
		TPoint focus_b, focus_e, focus_bp, focus_ep;

		typedef struct
		{
			AnsiString name, hint;
			int id;
			char type;
			char hp;
			//int , power, type_fire, radius, dist, sleep;
			Graphics::TBitmap *bmp;
			TSpeedButton *sb;
		} TObjectM;
		TObjectM *Object;

		#pragma pack(push,1)
		typedef struct
		{
			int id;
			char hp;
			TPoint begin, end;
		}TCell;
		#pragma pack(pop)

		TCell **Cell;
	//---------------------
	public:
		AnsiString FileName;
		TSpeedButton *SpeedButtons;
		TObjectM *ResCur;
		bool Change;
		TColor LineColor;

		TMap(TForm *form, TToolBar *tool, TSpeedButton *sb);
		~TMap(void);
		//---------------------
		void Create(int width, int height);
		void Open(AnsiString file);
		void Import(AnsiString file);
		void Save();
		void SaveAs(AnsiString file);
		bool saveAsText(AnsiString file);
		//---------------------
		void Paint(Graphics::TBitmap *buf);
		void Scroll(int dx, int dy);
		int Get_Width() {return Width;}
		int Get_Height() {return Height;}
		//---------------------
		TPoint PtC(int x, int y);
		TPoint CtP(int x, int y);
		TPoint PtC(TPoint p) {return PtC(p.x, p.y);}
		TPoint CtP(TPoint p) {return CtP(p.x, p.y);}
		//---------------------
		void SetC();
		//---------------------
		void Focus(int cell_x, int cell_y, bool mouse, bool pencil);
		void Focus(TPoint cell_p, bool mouse, bool pencil) {Focus(cell_p.x, cell_p.y, mouse, pencil);}
		//---------------------
		void __fastcall SpeedButtonsClick(TObject *Sender);
};
//---------------------------------------------------------------------------
TMap::TMap (TForm *form, TToolBar *tool, TSpeedButton *sb)
{
	Height = Width = 0;
	begin.x = 0;
	begin.y = 0;
	focus_b = focus_e = end = begin;
	ResCur = NULL;
	LineColor = clSilver;

	TIniFile *ini;
	ini = new TIniFile(ChangeFileExt("Resource\\Object", ".ini" ) );
	TMemo *l = new TMemo(form->Handle);
	ini->ReadSections(l->Lines);
	Object = new TObjectM[l->Lines->Count];

	for (int i = 0; i < l->Lines->Count; i++)
	{
		int id = StrToInt(ini->ReadString (l->Lines->Strings[i], "id", ""));
		Object[id].name = l->Lines->Strings[i];
		Object[id].id = id;
		Object[id].hint = ini->ReadString (Object[id].name, "hint", "");
		Object[id].type = StrToInt(ini->ReadString (Object[id].name, "type", ""));
		Object[id].bmp = new Graphics::TBitmap;
		//Object[id].bmp->LoadFromResourceName((int)HInstance, BMP + Object[id].name);
		Object[id].bmp->LoadFromResourceName((int)HInstance, "BMP_"+IntToStr(i+1));
		Object[id].hp = ini->ReadString (Object[id].name, "hp", "")[1];
		//Object[id].type = ini->ReadString (Object[id].name, "type", "")[1];
		//Object[id].power = StrToInt(ini->ReadString (Object[id].name, "power", ""));
		//Object[id].type_fire = StrToInt(ini->ReadString (Object[id].name, "type_fire", ""));
		//Object[id].radius = StrToInt(ini->ReadString (Object[id].name, "radius", ""));
		//Object[id].dist = StrToInt(ini->ReadString (Object[id].name, "dist", ""));
		//Object[id].sleep = StrToInt(ini->ReadString (Object[id].name, "sleep", ""));

		Object[id].sb = new TSpeedButton(tool);
		Object[id].sb->Name = SB + Object[id].name;
		Object[id].sb->Left = i * 23 + 57;
		Object[id].sb->Tag = id;
		Object[id].sb->GroupIndex = 13;
		Object[id].sb->Transparent = false;
		Object[id].sb->OnClick = SpeedButtonsClick;
		Object[id].sb->Flat = true;
		Object[id].sb->Hint = Object[id].hint;
		Object[id].sb->ShowHint = true;
		Object[id].sb->Cursor = crHandPoint;
		//Object[id].sb->gl
		//Object[id].sb->Glyph->LoadFromResourceName((int)HInstance, BMP + Object[id].name + IC);
		Object[id].sb->Glyph->LoadFromResourceName((int)HInstance, "BMP_"+IntToStr(i+1));
			Object[id].sb->Glyph->Transparent = false;
			Object[id].sb->Glyph->TransparentColor=clBlack;
		Object[id].sb->Parent = tool;
	}

	 //*/ /*
	 /*Object = new TObjectM[8];
	 //Tiles = new Graphics::TBitmap [9];
	 for (int i=0;i<8;i++)
	 {
			Object[i].bmp = new Graphics::TBitmap;
			Object[i].bmp->LoadFromResourceName((int)HInstance, "BMP_"+IntToStr(i+1));
			//Tiles[i].LoadFromResourceName((int)HInstance, "BMP_"+IntToStr(i+1));
	 }			 */

	//delete ini;
}
//---------------------------------------------------------------------------
TMap::~TMap ()
{
	for (int i = 0; i < Width; i++) delete[]Cell[i];
	delete[]Cell;
}
//---------------------------------------------------------------------------
void TMap::Create(int width, int height)
{
	if (Width != 0 && Height != 0)
	{
		for (int i = 0; i < Width; i++) delete[]Cell[i];
		delete[]Cell;
	}

	Width = width;
	Height = height;
	Cell = new TCell*[Width];
	for(int i = 0; i < Width; i++)
	{
		Cell[i] = new TCell[Height];
		for(int j = 0; j < Height; j++) Cell[i][j].id = 0;
	}
	begin.x = 0;
	begin.y = 0;
	end.x = Width * CELL_SIZE;
	end.y = Height * CELL_SIZE;

	FileName = EMPTY;								 
	Change = true;
}
//---------------------------------------------------------------------------
void TMap::Save()
{
	if (Change && FileName != EMPTY)
	{
		HANDLE fh = CreateFile(TEXT(FileName.c_str()), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

		DWORD dw=0;

		TCell tmp;
		tmp.id = 0;
		tmp.hp = 0;
		tmp.begin.x = Width;
		tmp.begin.y = Height;
		tmp.end.x = 0;
		tmp.end.y = 0;
		WriteFile(fh,&tmp,sizeof tmp,&dw,NULL);
		for (int i = 0; i < Width; i++)
			for (int j = 0; j < Height; j++)
				WriteFile(fh,&Cell[i][j],sizeof Cell[i][j],&dw,NULL);

		CloseHandle(fh);
		Change = false;
	}
}
//---------------------------------------------------------------------------
bool TMap::saveAsText(AnsiString file)	 //Функция сохраняет список в текстовый файл
{
	 FILE *fp = fopen (file.c_str(), "w");
	if (!fp)
	{
		printf ( "Cannot create text file");
		return false;
	}
	 fprintf(fp, "%d\n", Width);
	 fprintf(fp, "%d\n", Height);
	 for (int i = 0; i < Height; i++)
	 {
			for (int j = 0; j < Width; j++)
				 fprintf(fp, "%c", Cell[j][i].hp);
				//WriteFile(fh,&Cell[i][j],sizeof Cell[i][j],&dw,NULL);
			fprintf(fp, "\n");
	 }
	fclose(fp);
	return true;
}
//---------------------------------------------------------------------------
void TMap::Open(AnsiString file)
{
	if (FileExists(file))
	{
		HANDLE fh = CreateFile(TEXT(file.c_str()), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		DWORD dw=0;

		TCell tmp;
		ReadFile(fh,&tmp,sizeof tmp,&dw,NULL);
		Create(tmp.begin.x, tmp.begin.y);

		for (int i = 0; i < Width; i++)
			for (int j = 0; j < Height; j++)
				ReadFile(fh,&Cell[i][j],sizeof Cell[i][j],&dw,NULL);

		CloseHandle(fh);
		Change = false;
		FileName = file;
	}
}
//---------------------------------------------------------------------------
void TMap::Import(AnsiString file)
{
	if (FileExists(file))
	{
		FILE *fp = fopen (file.c_str(), "r");
	if (!fp)
	{
		printf ( "Cannot open text file");
		return;
	}
		//HANDLE fh = CreateFile(TEXT(file.c_str()), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		int w,h;
		fscanf(fp, "%d\n", &w);
		fscanf(fp, "%d\n", &h);
	 Create(w, h);
	 for (int i = 0; i < Height; i++)
	 {
			for (int j = 0; j < Width; j++)
				 fscanf(fp, "%c", &Cell[j][i].hp);
				 //fprintf(fp, "%c", Cell[j][i].hp);
			fscanf(fp, "\n");
	 }

	 Change = false;
		FileName = file;
	fclose(fp);
	 } 
	return ;
}
//---------------------------------------------------------------------------
void TMap::SaveAs(AnsiString file)
{
	FileName = file;
	Change = true;
	Save();
}
//---------------------------------------------------------------------------
void TMap::Paint(Graphics::TBitmap *buf)
{					 
	buf->Canvas->FillRect(Rect(0,0,buf->Width,buf->Height));
	buf->Canvas->Pen->Color = LineColor;//
	int x, y, n = max(Width, Height) + 1;
	for (int i = 0; i < n; i++)
	{
		if(i <= Width)
		{
			x = (i * CELL_SIZE) + begin.x;
			if (x >= 0)
			{
				buf->Canvas->MoveTo(x, 0);
				buf->Canvas->LineTo(x, min(end.y, buf->Height));
			}
		}
		if(i <= Height)
		{
			y = (i * CELL_SIZE) + begin.y;
			if (y >= 0)
			{
				buf->Canvas->MoveTo(0, y);
				buf->Canvas->LineTo(min(end.x, buf->Width), y);
			}
		}
	}
	//----------------
	TPoint tmp_end = PtC(end.x, end.y), tmp_buf = PtC(buf->Width + CELL_SIZE, buf->Height + CELL_SIZE);
	int ni = min(tmp_end.x, tmp_buf.x);
	int mj = min(tmp_end.y, tmp_buf.y);
	for (int i = -begin.x / CELL_SIZE; i < ni; i++)
		for (int j = -begin.y / CELL_SIZE; j < mj; j++)
			if (Cell[i][j].id > -1)	//0
			{
				TPoint p = CtP(i, j);
				buf->Canvas->Draw(p.x, p.y, Object[Cell[i][j].id].bmp);
			}
	//----------------
	buf->Canvas->Pen->Color = clLime;
	buf->Canvas->Brush->Style = bsClear;
	buf->Canvas->Rectangle(focus_bp.x, focus_bp.y, focus_ep.x, focus_ep.y);
	buf->Canvas->Brush->Style = bsSolid;
	buf->Canvas->Pen->Color = clBlack;
}
//---------------------------------------------------------------------------
void TMap::Scroll(int dx, int dy)
{
	begin.x = -dx;
	begin.y = -dy;
	end.x = Width * CELL_SIZE - dx;
	end.y = Height * CELL_SIZE - dy;
}
//---------------------------------------------------------------------------
TPoint TMap::PtC(int x, int y)
{
	TPoint p;
	p.x = (x - begin.x) / CELL_SIZE;
	p.y = (y - begin.y) / CELL_SIZE;
	return p;
}
//---------------------------------------------------------------------------
TPoint TMap::CtP(int x, int y)
{
	TPoint p;
	p.x = x * CELL_SIZE + begin.x;
	p.y = y * CELL_SIZE + begin.y;
	return p;
}
//---------------------------------------------------------------------------
void TMap::Focus(int cell_x, int cell_y, bool mouse, bool pencil)
{
	TPoint p;
	p.x = cell_x;
	p.y = cell_y;
	if (mouse && !pencil) focus_e = p;
	else focus_b = focus_e = p;

	focus_bp = CtP(focus_b);
	focus_ep = CtP(focus_e);
	if (focus_ep.x >= focus_bp.x) focus_ep.x += CELL_SIZE+1;
	else focus_bp.x += CELL_SIZE+1;
	if (focus_ep.y >= focus_bp.y) focus_ep.y += CELL_SIZE+1;
	else focus_bp.y += CELL_SIZE+1;
}
//---------------------------------------------------------------------------
void __fastcall TMap::SpeedButtonsClick(TObject *Sender)
{
 TSpeedButton *sb = ((TSpeedButton*)(Sender));
	ResCur = &Object[sb->Tag];
}
//---------------------------------------------------------------------------
void TMap::SetC()
{
	if (focus_b.x < Width && focus_e.x < Width && focus_b.y < Height && focus_e.y < Height)
	{
		if (focus_b.x == focus_e.x && focus_b.y == focus_e.y && Cell[focus_b.x][focus_b.y].id != ResCur->id)
		{
			Cell[focus_b.x][focus_b.y].id = ResCur->id;
			Cell[focus_b.x][focus_b.y].hp = ResCur->hp;
			Cell[focus_b.x][focus_b.y].begin = focus_b;
			Cell[focus_b.x][focus_b.y].end = focus_e;
		}
		else
		{
			int n = max(focus_b.x, focus_e.x) + 1;
			int m = max(focus_b.y, focus_e.y) + 1;
			for (int i = min(focus_b.x, focus_e.x); i < n; i++)
				for (int j = min(focus_b.y, focus_e.y); j < m; j++)
				{														 
					Cell[i][j].id = ResCur->id;
					Cell[i][j].hp = ResCur->hp;
					Cell[i][j].begin = focus_b;
					Cell[i][j].end = focus_e;
				}
		}
		Change = true;
	}
}
//---------------------------------------------------------------------------
