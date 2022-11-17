//---------------------------------------------------------------------------

#include <vcl.h>
#include <memory>
#pragma hdrstop

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEditorForm *EditorForm;
//---------------------------------------------------------------------------
__fastcall TEditorForm::TEditorForm(TComponent* Owner)
	: TForm(Owner)
{
	try
	{
		Map.LoadTiles("Tiles\\Tiles.TXT");
  	} catch (...)
	{
		Application->MessageBoxA(L"Unable to open file \"Tiles\\Tiles.TXT\"",L"Location Editor error",MB_ICONERROR);
		Close();
	}
	/*Load Tiles*/
	Out->Canvas->Font->Size = 10;
	Out->Canvas->Pen->Color = clBlack;
	NullTile->Canvas->Brush->Color = clWhite;
	NullTile->Canvas->Pen->Color = clBlack;
	Graphics::TBitmap* Tile = new Graphics::TBitmap;
	//std::auto_ptr<Graphics::TBitmap> Bitmap1(new Graphics::TBitmap());
	UnicodeString File = "Tiles\\X.BMP";
	PTiles->Items->Clear();
	PTiles->Items->Capacity = Map.TilesCount;
	TGrpButtonItem *BI;
	for (int i = 0; i<Map.TilesCount; ++i)
	{
		File[7] = Map.TileIdent[i];
		try
		{
			BI = PTiles->Items->Add();
			BI->Caption = Map.TileName[i];
			BI->Hint = BI->Caption;
			Tile->LoadFromFile(File);
			Tiles->Add(Tile, NULL);
		} catch(...)
		{
			NullTile->Canvas->FillRect(Rect(0,0,TILESIZE,TILESIZE));
			NullTile->Canvas->TextOutA(2,-2,Map.TileIdent[i]);
			//Memo1->Lines->Add(File);
			Tiles->Add(NullTile->Picture->Bitmap, NULL);
		}
		BI->ImageIndex = i;
	}
	delete Tile;
	////////////
	Map.UndefindedId = Map.GetLocationIndex('0');
	SelTile = 0;
	Painting = false;
	RangeSelect = false;
	CellBtn->Down = true;
	Out->GridLineWidth = 0;
	DrawGrid = false;
	FileOpen->Dialog->InitialDir = GetCurrentDir();
	FileSaveAs->Dialog->InitialDir = GetCurrentDir();
	SavePicture1->Dialog->InitialDir = GetCurrentDir();
	FileOpen->Dialog->InitialDir = "Locations\\";
	FileSaveAs->Dialog->InitialDir = "Locations";
	CategoryPanelGroup1->CollapseAll();
	PanelTile->Expand();
	Brush = bTile;
	Saved = 0;
	//PanelTile->Height = CategoryPanelGroup1->Height - 58;
	CursorMode = bSet;
	PrewTile = 0;
	SelTile = 0;
	RangeState << gdFixed;
	TestDraw = false;
	NTilesNamesClick(NULL);
	ARPower->Color = Map.GetAnomallyColor(ARPower->Value);
	SelAnom = ARPower->Value;
	SelRad = ARPower->Value;
	SelTrig = 0;
	Ready(false);
	Out->Canvas->Brush->Style = bsClear;
	PanelTile->Height = PanelTile->Height - 4; //Убирает общий скроллбар панелей
	//CategoryPanelGroup1->Align = alLeft;
	//AnomNumbChange(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TEditorForm::FileNewExecute(TObject *Sender)
{
		if(CreateForm->ShowModal() == mrOk)
	{
   	TestDraw = false;
		Map.Create(CreateForm->W->Value, CreateForm->H->Value);
		Out->ColCount = Map.Width;
		Out->RowCount = Map.Height;
		Ready(true);
		Out->Repaint();
	}
	EditorForm->Caption = "Stalker Location Editor";
	StatusBar->Panels->Items[STMAX]->Text = IntToStr(Map.Width)+"x"+IntToStr(Map.Height);
	Saved = 0;
}
//---------------------------------------------------------------------------
void __fastcall TEditorForm::FileSaveExecute(TObject *Sender)
{
	if (Saved == 'O')	{			Map.Save(FileOpen->Dialog->FileName);	}
	else if (Saved == 'S')	{	Map.Save(FileSaveAs->Dialog->FileName);	}
	else    	FileSaveAs->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TEditorForm::FileOpenAccept(TObject *Sender)
{
	TestDraw = false;
	Map.Open(FileOpen->Dialog->FileName);
	Out->ColCount = Map.Width;
	Out->RowCount = Map.Height;
	Ready(true);
	Out->Repaint();
	RefreshLocationName(FileOpen->Dialog->FileName);
	StatusBar->Panels->Items[STMAX]->Text = IntToStr(Map.Width)+"x"+IntToStr(Map.Height);
	if (FileOpen->Dialog->Options.Contains(ofReadOnly))
		Saved = 'R';
	else
		Saved = 'O';
}
//---------------------------------------------------------------------------
void __fastcall TEditorForm::FileSaveAsAccept(TObject *Sender)
{
	Map.Save(FileSaveAs->Dialog->FileName);
	EditorForm->Caption = FileSaveAs->Dialog->FileName + "Stalker Location Editor";
	RefreshLocationName(FileSaveAs->Dialog->FileName);
	Saved = 'S';
}
//---------------------------------------------------------------------------
void __fastcall TEditorForm::ARangeSelectExecute(TObject *Sender)
{
	RangeSelect = !RangeSelect;
	if (RangeSelect) //if (Map->Options.Contains(goRangeSelect))
	{
		Out->Options << goRangeSelect; //Добавить true
		Out->Cursor = crDrag;
	}
	else
	{
		Out->Options >> goRangeSelect; //Извлечь false
		Out->Cursor = crDefault;
	}
	CellBtn->Down = !RangeSelect;
	RangeBtn->Down = RangeSelect;
}
//---------------------------------------------------------------------------

