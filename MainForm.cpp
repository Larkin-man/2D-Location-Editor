//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "FormCreate.h"
#include "Map.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#pragma resource "Resource\\Object.res"
TForm_Main *Form_Main;

Graphics::TBitmap *buf;	 //buf Это изображение
TMap *map;

//Конструктор формы
__fastcall TForm_Main::TForm_Main(TComponent* Owner) : TForm(Owner)
{
	 //ListBox1->ItemHeight = 10;
}
//---------------------------------------------------------------------------
//Создание формы
void __fastcall TForm_Main::FormCreate(TObject *Sender)
{
	map = new TMap (Form_Main, ToolBar1, SpeedButton_C);
	buf = new Graphics::TBitmap();
	bufX = Bevel1->Left + 2;
	bufY = Bevel1->Top + 2;
	buf->Width = Bevel1->Width - 5;
	buf->Height = Bevel1->Height - 5;
	Image1->Left = bufX;
	Image1->Top = bufY;
	Image1->Width = buf->Width;
	Image1->Height = buf->Height;
	mkR = mkL = false;
	//BitBtn1->Glyph->Transparent = false;
	//BitBtn1->Glyph->TransparentColor=clCream;
}
//---------------------------------------------------------------------------
//,
void __fastcall TForm_Main::EditScroll(int width, int height)
{
	int tmp = (width * CELL_SIZE - buf->Width) + 1;
	ScrollBar_G->Max = (tmp < 0) ? 0 : tmp;
	tmp = (height * CELL_SIZE - buf->Height) + 1;
	ScrollBar_V->Max = (tmp < 0) ? 0 : tmp;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::BufPaint()
{
	map->Paint(buf);
	Form_Main->Canvas->Draw(bufX, bufY, buf);
}
//---------------------------------------------------------------------------
//Нажатие клавиши в форме
void __fastcall TForm_Main::FormKeyPress(TObject *Sender, char &Key)
{
	//if (Key == 27) N_ExitClick(Sender);
}
//---------------------------------------------------------------------------
//Изменение размера формы
void __fastcall TForm_Main::FormResize(TObject *Sender)
{
	Image1->Left = bufX = Bevel1->Left + 2;
	Image1->Top = bufY = Bevel1->Top + 2;

	buf->Width = Bevel1->Width - 5;
	buf->Height = Bevel1->Height - 5;

	Image1->Width = buf->Width;
	Image1->Height = buf->Height;

	EditScroll(map->Get_Width(), map->Get_Height());
	BufPaint();
}
//---------------------------------------------------------------------------
//Файл - новый
void __fastcall TForm_Main::N_NewClick(TObject *Sender)
{
	Form_Create->mOK = false;
	Form_Create->ShowModal();
	if(Form_Create->mOK)
	{
		map->Create(Form_Create->W, Form_Create->H);
		EditScroll(map->Get_Width(), map->Get_Height());
	}
	BufPaint();
}
//---------------------------------------------------------------------------
//Горизонтальный скролбар
void __fastcall TForm_Main::ScrollBar_VChange(TObject *Sender)
{
	map->Scroll(ScrollBar_G->Position, ScrollBar_V->Position);
	BufPaint();
}
//---------------------------------------------------------------------------
//Нажатие мышки на карте
void __fastcall TForm_Main::Image1MouseDown(TObject *Sender,
			TMouseButton Button, TShiftState Shift, int X, int Y)
{
	if (Button == mbRight)
	{
		stX = X;
		stY = Y;
		stG = ScrollBar_G->Position;
		stV = ScrollBar_V->Position;
		mkR = true;
		Image1->Cursor = crHandPoint;
	}
	if (Button == mbLeft) mkL = true;
}
//---------------------------------------------------------------------------
//Движение мышки по карте
void __fastcall TForm_Main::Image1MouseMove(TObject *Sender,
			TShiftState Shift, int X, int Y)
{
	if (mkR)
	{
		ScrollBar_G->Position += (stX - X);
		ScrollBar_V->Position += (stY - Y);
		stX = X;
		stY = Y;
	}
	TPoint p = map->PtC(X, Y);
	StatusBar1->Panels->Items[0]->Text = IntToStr((int)p.x) + "	" + IntToStr((int)p.y);
	StatusBar1->Panels->Items[1]->Text = IntToStr(X) + "	" + IntToStr(Y);
	map->Focus(p, mkL, SpeedButton_C->Down);
	//if (SpeedButton_C->Down && mkL && map->ResCur)
	if (SpeedButton_C->Down && mkL && map->ResCur)
			map->SetC();
	BufPaint();
}
//---------------------------------------------------------------------------
//Отпускание мыши
void __fastcall TForm_Main::Image1MouseUp(TObject *Sender,
			TMouseButton Button, TShiftState Shift, int X, int Y)
{
	if (Button == mbRight)
	{
		mkR = false;
		Image1->Cursor = crDefault;
	}
	if (Button == mbLeft) mkL = false;
	BufPaint();
}
//---------------------------------------------------------------------------
//Кнопка с курсором областью
void __fastcall TForm_Main::SpeedButton_CClick(TObject *Sender)
{
	//TSpeedButton *sb = ((TSpeedButton*)(Sender));
	//map->ResCur = NULL;
}
//---------------------------------------------------------------------------
//Клик по карте
void __fastcall TForm_Main::Image1Click(TObject *Sender)
{
	if (map->ResCur)
			map->SetC();
	BufPaint();
}
//---------------------------------------------------------------------------
//Файл - сохранить
void __fastcall TForm_Main::N_SaveClick(TObject *Sender)
{
	if (map->FileName != EMPTY) map->Save();
	else N_SaveAsClick(Sender);
}
//---------------------------------------------------------------------------
//Файл - открыть
void __fastcall TForm_Main::N_OpenClick(TObject *Sender)
{
	if (OpenDialog1->Execute())
	{
		map->Open(OpenDialog1->FileName);
		EditScroll(map->Get_Width(), map->Get_Height());
	}
}
//---------------------------------------------------------------------------
//Файл - сохранить как
void __fastcall TForm_Main::N_SaveAsClick(TObject *Sender)
{
	if (SaveDialog1->Execute()) map->SaveAs(SaveDialog1->FileName);
}
//---------------------------------------------------------------------------
//Вид - цвет линий
void __fastcall TForm_Main::N3Click(TObject *Sender)
{
	 if ( ColorDialog1->Execute() == ID_OK)
	 {
			map->LineColor = ColorDialog1->Color;
	 }
}
//---------------------------------------------------------------------------
/*/Отрисовка листбокса
//ToolBar1->Buttons[Index]->im
	 ListBox1->Canvas->FillRect(Rect);
	 //ImageList1->Draw()
	 ImageList1->Draw(ListBox1->Canvas, Rect.Left + 5,
			Rect.Top, Index, true);
	 ListBox1->Canvas->TextOut(Rect.Left + 20, Rect.Top,
			ListBox1->Items->Strings[Index]);	*/
void __fastcall TForm_Main::NExportClick(TObject *Sender)
{
	 if (SaveDialog1->Execute()) map->saveAsText(SaveDialog1->FileName);	 
}
//---------------------------------------------------------------------------

void __fastcall TForm_Main::NImportClick(TObject *Sender)
{
	 if (OpenDialog1->Execute())
	{
		map->Import(OpenDialog1->FileName);
		EditScroll(map->Get_Width(), map->Get_Height());
	}
}
//---------------------------------------------------------------------------

