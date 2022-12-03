//---------------------------------------------------------------------------
#include <vcl.h>
#include <memory>
#include <math.h>
#pragma hdrstop
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEditorForm *EditorForm;
//---------------------------------------------------------------------------
__fastcall TEditorForm::TEditorForm(TComponent* Owner) : TForm(Owner)
{
	ImagesSquareLen = 10;
	try
	{
		Map.LoadTiles("Tiles\\TILES.txt");
  	} catch (...)
	{
		Application->MessageBoxA(L"Unable to open file \"Tiles\\TILES.txt\"",L"Location Editor error",MB_ICONERROR);
		Close();
	}
	//DrawAnomallyBtn->Down = false;
	ARRandom->Tag = 1; //Чтобы не было Editchange запуска
	/*Load Tiles*/
	//Out->Canvas->Font->Size = TILESIZE;   это зачем было??
	Tiles->SetSize(TILESIZE,TILESIZE);
	//Out->DefaultColWidth = TILESIZE;
	//Out->DefaultRowHeight = TILESIZE;
	Out->Canvas->Pen->Color = clBlack;
	In = new Graphics::TBitmap;
	In->SetSize(TILESIZE,TILESIZE);
	Graphics::TBitmap* Tile = new Graphics::TBitmap;
	Graphics::TBitmap* CurrBtn = new Graphics::TBitmap;
	CurrBtn->SetSize(TileBtns->Width,TileBtns->Height);
	Graphics::TBitmap* UnknownTile = NULL;
	String File = "Tiles\\0123.BMP";
	String NameT;
	PTiles->Items->BeginUpdate();
	PTiles->Items->Clear();
	PTiles->Items->Capacity = Map.TilesCount;
	TGrpButtonItem *BI;
	int nBtn = 0;
	int Btns = TILESIZE / TileBtns->Width;
	for (int i = 0; i < Map.TilesCount; ++i)
	{
		NameT = Map.Idents[i];
		File[7] = NameT[1];
		File[8] = NameT[2];
		File[9] = NameT[3];
		File[10] = NameT[4];
		try
		{
      	Tile->LoadFromFile(File);
			Tiles->Add(Tile, NULL);
		} catch(...)
		{
			NullTile->Canvas->FillRect(Rect(0,0,ImagesSquareLen,ImagesSquareLen));
			NullTile->Canvas->TextOutA(2,-2,Map.TileIdent[i]);
			//Memo1->Lines->Add(File);
			Tiles->Add(NullTile->Picture->Bitmap, NULL);
		}
		catch(...)
		{
			if (UnknownTile == NULL)
			{
				UnknownTile = new Graphics::TBitmap;
				UnknownTile->SetSize(TILESIZE,TILESIZE);
			}
			UnknownTile->Canvas->FillRect(Rect(0,0,TILESIZE,TILESIZE));
			UnknownTile->Canvas->Font->Height = TILESIZE/2;
			UnknownTile->Canvas->TextOutA(0,0,Map.Idents[i]);
			Tiles->Add(UnknownTile, NULL);
		}
		if (Map.Variants[i] == 0)
		{
			BI = PTiles->Items->Add();
			//Отрисовка иконки
			CurrBtn->Canvas->StretchDraw(CurrBtn->Canvas->ClipRect, Tile);
			/*int ix=0,iy=0;
			for (int bx = 0; bx < TILESIZE; bx+=Btns, ix++)
				for (int by = 0, iy = 0; by < TILESIZE; by+=Btns, iy++)
					CurrBtn->Canvas->Pixels[ix][iy] = Tile->Canvas->Pixels[bx][by]; //*/
			TileBtns->Add(CurrBtn, NULL);
			BI->ImageIndex = nBtn;
			//----
			Map.Buttons[nBtn] = i;
			BI->Caption = Map.TileName[i];//+IntToStr(Map.Buttons[nBtn]);
			nBtn++;
			if (Map.Variants[i+1] == 0)
				Map.Variants[i] = i;
			else
				Map.Variants[i] = i+1;

		}
		else
			if (Map.Variants[i+1] == 0)
				Map.Variants[i] = Map.Buttons[nBtn-1];  //перв
			else
				Map.Variants[i] = i+1;  //i+1
	}
	PTiles->Items->EndUpdate();
	delete Tile;
	//Создать нонтайл
	CreateNoneTile();
	//--------
	//Map.UndefindedId = Map.GetLocationIndex('0');
	SelTile = 0;
	Painting = false;
	DrawAnom = false;
	RangeSelect = false;
	CellBtn->Down = true;
	//Out->GridLineWidth = 0;
	DrawGrid = false;
	FileOpen->Dialog->InitialDir = GetCurrentDir();
	FileSaveAs->Dialog->InitialDir = GetCurrentDir();
	SavePictureDialog1->InitialDir = GetCurrentDir();
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
	ARPowerE->Color = Map.GetAnomallyColor(ARPower->Position);
	SelAnom = ARPower->Position;
	SelRad = ARPower->Position;
	SelTrig = 0;
	Ready(false);
	Out->Canvas->Brush->Style = bsClear;
	PanelTile->Height = PanelTile->Height - 4; //Убирает общий скроллбар панелей
	//CategoryPanelGroup1->Align = alLeft;
	//AnomNumbChange(NULL);
	FDraws = 0;
	DrawTile = true;
	Map.DebugOpenTrig = openTRIG->Checked;
	CurrTile = new Graphics::TBitmap;//std::auto_ptr<Graphics::TBitmap> bm(new Graphics::TBitmap()); // для этого нужно #include <memory>
	CurrTile->SetSize(TILESIZE, TILESIZE);
	SelSprite = -1;
	Scaler->Position = 8;
	delete UnknownTile;
	//Спрайт
	Sprite = new Graphics::TBitmap;//new TImage(Out);
	//Sprite->Parent = Out;	Sprite->Visible = false;
	Sprite->Transparent = true;
	//Sprite->Stretch = true;
	//Sprite->OnMouseMove = BitBtn1MouseMove;
	//SelSprite = 0;
	//ShowMessage(sizeof(FDraws));
	Store = new Graphics::TBitmap;
	RX = 1;//Для
	nSprites = 0;
	MapMoving = false;
	NeedPopup = false;
}
//---------------------------------------------------------------------------
//НОВЫЙ
void __fastcall TEditorForm::FileNewExecute(TObject *Sender)
{                 	
	if(CreateForm->ShowModal() == mrOk)
	{
		TestDraw = false;
		Map.Create(CreateForm->W->Position, CreateForm->H->Position);
		Ready(true);
		nSprites = 0;
	}
	EditorForm->Caption = "Stalker Location Editor";
	StatusBar->Panels->Items[STMAX]->Text = IntToStr(Map.Width)+"x"+IntToStr(Map.Height);
	Saved = 0;
}
//---------------------------------------------------------------------------
//Сохранить
void __fastcall TEditorForm::FileSaveExecute(TObject *Sender)
{
	if (Saved == 'O')	{			Map.Save(FileOpen->Dialog->FileName);	}
	else if (Saved == 'S')	{	Map.Save(FileSaveAs->Dialog->FileName);	}
	else    	FileSaveAs->Execute();
}
//---------------------------------------------------------------------------
//Открыть
void __fastcall TEditorForm::FileOpenAccept(TObject *Sender)
{
	if (Map.SpritesCount == 0)
		loadspritesClick(Sender);
	TestDraw = false;
	Map.Open(FileOpen->Dialog->FileName);
	Ready(true);
	RefreshLocationName(FileOpen->Dialog->FileName);
	StatusBar->Panels->Items[STMAX]->Text = IntToStr(Map.Width)+"x"+IntToStr(Map.Height);
	if (FileOpen->Dialog->Options.Contains(ofReadOnly))
		Saved = 'R';
	else
		Saved = 'O';
}
//---------------------------------------------------------------------------
//Сохранить Как
void __fastcall TEditorForm::FileSaveAsAccept(TObject *Sender)
{
	Map.Save(FileSaveAs->Dialog->FileName);
	EditorForm->Caption = FileSaveAs->Dialog->FileName + "Stalker Location Editor";
	RefreshLocationName(FileSaveAs->Dialog->FileName);
	Saved = 'S';
}
//---------------------------------------------------------------------------
//ToolBar: Переключение выбора (одиночный-множественный)
void __fastcall TEditorForm::ARangeSelectExecute(TObject *Sender)
{
	//RangeSelect = !RangeSelect;
	if (CellBtn->Down)
	{
		RangeBtn->Down = true;
		//CellBtn->Down = false;
	} else
	if (RangeBtn->Down) //if (Map->Options.Contains(goRangeSelect))
	{
		//RangeBtn->Down = false;
		CellBtn->Down = true;
	} else
	if (RulerBtn->Down || MovedBtn->Down) //if (Map->Options.Contains(goRangeSelect))
	{
		//RulerBtn->Down = false;
		//if (Out->Options.Contains(goRangeSelect))
		//	RangeBtn->Down = true;
		//else
		//	CellBtn->Down = true;
	}
	RangeBtnClick(Sender);
	//CellBtn->Down = !RangeSelect;
	//RangeBtn->Down = RangeSelect;
}
//---------------------------------------------------------------------------
//Переключение вида кнопок тайлов
void __fastcall TEditorForm::NTilesNamesClick(TObject *Sender)
{
	NTilesNames->Checked = !NTilesNames->Checked;
	if (NTilesNames->Checked)
   {
		PTiles->ButtonOptions << gboFullSize;
		PTiles->ButtonOptions << gboShowCaptions;
		for (int i = 0; i < PTiles->Items->Count; ++i)
		{
			//PTiles->Items->Items[i]->Hint = "(?)";
			PTiles->Items->Items[i]->Hint = Map.Idents[Map.Buttons[i]];
		}
	} else
	{
		PTiles->ButtonOptions >> gboFullSize;
		PTiles->ButtonOptions >> gboShowCaptions;
		for (int i = 0; i < PTiles->Items->Count; ++i)
			PTiles->Items->Items[i]->Hint = Map.TileName[Map.Buttons[i]] +PTiles->Items->Items[i]->Hint;
		PTiles->Height = Map.TilesCount*Tiles->Height/5;
	}
	PTiles->Repaint();
}
//---------------------------------------------------------------------------
//ToolBar: Отображение сетки
void __fastcall TEditorForm::ADrawGridExecute(TObject *Sender)
{
	DrawGrid = !DrawGrid;
	OutRepaint();
	Log->Lines->Add(CellSize);
	Log->Lines->Add(VisibleRowCount);
	Log->Lines->Add(VisibleColCount);
	//DrawGridBtn->Down = DrawGrid;
}
//---------------------------------------------------------------------------
//Нажати кнопки тайла
void __fastcall TEditorForm::PTilesButtonClicked(TObject *Sender, int Index)
{
	PrewTile = SelTile;
	NPrewTile->Caption = "Тайл: "+Map.TileName[PrewTile]; //PTiles->Items->Items[PrewTile]->Caption;
	SelTile = Map.Buttons[Index];
	StatusBar->Panels->Items[STTILE]->Text = PTiles->Items->Items[Index]->Caption;
}
//--------------------------------------------------------------------
//Раскрытие панели Тайлов
void __fastcall TEditorForm::PanelTileExpand(TObject *Sender)
{
	PanelAR->Collapse();
	PanelTriggers->Collapse();
	PanelSprites->Collapse();
	PanelTile->Height = CategoryPanelGroup1->Height - PANELSCHOP;
	Brush = bTile;
	PTiles->Width ++; PTiles->Width ++; //Это спасает об бага размера
}
//---------------------------------------------------------------------------
//Раскрытие панели Аномалий\Радиации
void __fastcall TEditorForm::PanelARExpand(TObject *Sender)
{
	PanelTile->Collapse();
	PanelTriggers->Collapse();
	PanelSprites->Collapse();
	PanelAR->Height = CategoryPanelGroup1->Height - PANELSCHOP;
	Brush = bAR;
	PanelAR->Width ++; PanelAR->Width ++; //Это спасает об бага размера
}
//---------------------------------------------------------------------------
//Раскрытие панели Триггеров
void __fastcall TEditorForm::PanelTriggersExpand(TObject *Sender)
{
	PanelTile->Collapse();
	PanelAR->Collapse();
	PanelSprites->Collapse();
	PanelTriggers->Height = CategoryPanelGroup1->Height - PANELSCHOP;
	Brush = bTrig;
	PanelTriggers->Width ++; PanelTriggers->Width ++; //Это спасает об бага размера
}
//---------------------------------------------------------------------------
//ToolBar: Рисовать Аномалии
void __fastcall TEditorForm::ADrawAnomallyExecute(TObject *Sender)
{
	TestDraw = false;
	DrawAnom = !DrawAnom;
	DrawAnomallyBtn->Down = DrawAnom;
	OutRepaint();
	TGridDrawState State;
	State << gdSelected;//gdFixed;
	/*for (int i = 0; i < Map.Width; ++i)
		for (int j = 0; j < Map.Height; ++j)
			if (Map.Cell[i][j].Anomally != 0)
			{
				TRect Rect = Out->CellRect(i,j);
				OutDrawCell(Sender, 1, 1, Rect, State);
			}  */
	//Out->Refresh();
}
//---------------------------------------------------------------------------
//ToolBar: Рисовать Радиацию
void __fastcall TEditorForm::ADrawRadiationExecute(TObject *Sender)
{
	DrawRad = !DrawRad;
	DrawRadiationBtn->Down = DrawRad;
	DrawTile = false;
	Out->Refresh();
	DrawTile = true;
}
//---------------------------------------------------------------------------
//О: безопасно
void __fastcall TEditorForm::AR0Click(TObject *Sender)
{
	if (AR->ItemIndex == 0)
		SelAnom = 0;
	else
		SelRad = 0;
}
//---------------------------------------------------------------------------
//О: Опасно 100
void __fastcall TEditorForm::AR100Click(TObject *Sender)
{
	if (AR->ItemIndex == 0)
		SelAnom = 100;
	else
		SelRad = 100;
}
//---------------------------------------------------------------------------
//О: Случайная
void __fastcall TEditorForm::ARRandomClick(TObject *Sender)
{
	if (AR->ItemIndex == 0)
	{
		SelAnom = ARPower->Position;
		ARPowerE->Color = ColorAnom;// Map.GetAnomallyColor(SelAnom);
	}
	else
	{
		SelRad = ARPower->Position;
		ARPowerE->Color = ColorRad; //Map.GetRadiationColor(SelRad);
   }
}
//---------------------------------------------------------------------------
//Тип заполнения - SET
void __fastcall TEditorForm::ACursorSetExecute(TObject *Sender)
{
	CursorMode = bSet;
	CursorModeChange();
}
//---------------------------------------------------------------------------
//Тип заполнения - ADD
void __fastcall TEditorForm::ACursorAddExecute(TObject *Sender)
{
	CursorMode = bAdd;
	CursorModeChange();
}
//---------------------------------------------------------------------------
//Тип заполнения - DEC
void __fastcall TEditorForm::ACursorDecExecute(TObject *Sender)
{
	CursorMode = bRem;
	CursorModeChange();
}
//---------------------------------------------------------------------------
//PopupMenu - Предыдущий тайл
void __fastcall TEditorForm::NPrewTileClick(TObject *Sender)
{
	StatusBar->Panels->Items[STTILE]->Text = NPrewTile->Caption;
	NPrewTile->Caption = "Тайл: "+Map.TileName[SelTile]; //PTiles->Items->Items[PrewTile]->Caption;
	int t = SelTile;
	SelTile = PrewTile;
   PrewTile = t;
}
//---------------------------------------------------------------------------
//Запуск - Debug
void __fastcall TEditorForm::NDebugClick(TObject *Sender)
{
	DebugPanel->Visible = !DebugPanel->Visible;
	NDebug->Checked = DebugPanel->Visible;
}
//---------------------------------------------------------------------------
//Запуск - разместить аномалии
void __fastcall TEditorForm::NTestAnomClick(TObject *Sender)
{
	Map.AnomallyRun();
	TestDraw = true;
	OutRepaint();
	DrawAnom = false;
	DrawAnomallyBtn->Down = false;
}
//---------------------------------------------------------------------------
//Запуск - информация о локации
void __fastcall TEditorForm::NInfoClick(TObject *Sender)
{
	int Pl = Map.Width * Map.Height;
	int Wei = Map.Width * METERS;
	int Hei = Map.Height * METERS;
	double AnSr = 0, RadSr = 0;
	int nStoy = 0;
	int nSprites = 0;
	for (int i = 0; i < Map.Height; ++i)
		for (int j = 0; j < Map.Width; ++j)
		{
			AnSr += Map.Cell[j][i].Anomally;
			RadSr += Map.Cell[j][i].Radiation;
			if ((Map.Cell[j][i].Triggger == 1)||(Map.Cell[j][i].Triggger == 2))
				nStoy++;
			nSprites += Map.Cell[j][i].Sprites.size();
		}
	AnSr /= (double) Pl;
	RadSr /= (double) Pl;
	String Info = "Размеры: "+IntToStr(Map.Width)+"X"+IntToStr(Map.Height)+" кв.\n"
		+IntToStr(Wei)+"X"+IntToStr(Hei)+" метров.\n";
	Info += "Площадь="+IntToStr(Pl)+" кв.\n"+IntToStr(Wei*Hei)+" метров кв.\n"
		+"Средняя аномальность="+FloatToStrF(AnSr, ffGeneral, 5, 5)+"%.\n";
	Info += "Средняя радиоактивность="+FloatToStrF(RadSr, ffGeneral, 5, 5)+"%.\n"
		+"Точек респавна="+IntToStr(nStoy)+".";
	Info += "\nСпрайтов="+IntToStr(nSprites)+".";
	MessageBox(Application->Handle,Info.c_str(),"Информация о локации",MB_OK);
}
//---------------------------------------------------------------------------
//Отмена
void __fastcall TEditorForm::AUndoExecute(TObject *Sender)
{
	if (Brush == bTile)
	{
		for (int i = 0; i < UndoCurr; ++i)
		{
			SelTile = Undo[i].Cell->Image;
			Undo[i].Cell->Image = Undo[i].Tile;
			//Undo[i].Cell->Ident = Map.Idents[Undo[i].Tile];
			//strncpy(Undo[i].Cell->Ident, Map.Idents[Undo[i].Tile], SYMBCOUNT);
			Undo[i].Tile = SelTile;
		}
		Out->Refresh();
	}
}
//---------------------------------------------------------------------------
//File - Экспорт карты
void __fastcall TEditorForm::NExportClick(TObject *Sender)
{
	if (Saved == 'S')
		SavePictureDialog1->FileName = FileSaveAs->Dialog->FileName.SubString(1,FileSaveAs->Dialog->FileName.Pos('.')-1)+".bmp";
	else
		SavePictureDialog1->FileName =   FileOpen->Dialog->FileName.SubString(1,FileOpen->Dialog->FileName.Pos('.')-1)+".bmp";
	if (SavePictureDialog1->Execute() == ID_OK)
	{
		Graphics::TBitmap *mp = new Graphics::TBitmap;
		mp->Height = Map.Height * TILESIZE;
		mp->Width = Map.Width * TILESIZE;
		/*mp->Canvas->CopyRect(Rect(0,0,mp->Width* TILESIZE,mp->Height* TILESIZE),
			Out->Canvas,		  Rect(0,0,mp->Width* TILESIZE,mp->Height* TILESIZE));     */
		for (int i = 0; i < Map.Width; ++i)
			for (int j = 0; j < Map.Height; ++j)
			{
				Tiles->Draw(mp->Canvas, i*TILESIZE,	j*TILESIZE, Map.Cell[i][j].Image, true);
				if (Map.Cell[i][j].Sprites.size() > 0)
					for (std::vector<TMap::TSprite>::iterator el = Map.Cell[i][j].Sprites.begin(); el != Map.Cell[i][j].Sprites.end(); ++el)
						mp->Canvas->Draw(i * TILESIZE + el->x
						,j * TILESIZE + el->y
						,Map.Sprites[el->Index]->Graphic);		//*/
			}
		mp->SaveToFile(SavePictureDialog1->FileName);
		delete mp;
	}
}
//---------------------------------------------------------------------------
//Нажатие клавиши мышки (Начало редактирования)
void __fastcall TEditorForm::OutMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (GetCellOf(X,Y) == false) //Получаем координаты ячейки
		return;// ShowMessage("Баг нет карты!");
	if (Button == mbLeft)
	{
		if (PanelSprites->Collapsed == false) //Открыты спрайты
		{
			//Log->Lines->Add("XY "+IntToStr(X)+","+IntToStr(Y));
//			X %= (Out->DefaultColWidth+Out->GridLineWidth);
//			Y %= (Out->DefaultRowHeight+Out->GridLineWidth);
			//Log->Lines->Add("1past "+IntToStr(X)+","+IntToStr(Y)+","+IntToStr(Sprite->Width)+","+IntToStr(Sprite->Height));
//			X = (float)X * TILESIZE / Out->DefaultColWidth;
//			Y = (float)Y * TILESIZE / Out->DefaultRowHeight;
			//Log->Lines->Add("2past "+IntToStr(X)+","+IntToStr(Y)+","+IntToStr(Sprite->Width)+","+IntToStr(Sprite->Height));
         X = (float)X * TILESIZE / CellSize;
				Y = (float)Y * TILESIZE / CellSize;
				X += ScrollWi->Position * TILESIZE;
				Y += ScrollHe->Position * TILESIZE;
			if (SelSprite >= 0)
			{

				X -= Map.Sprites[SelSprite]->Width ; //это хдесь потомучто есть удаление
				Y -= Map.Sprites[SelSprite]->Height;
				//Log->Lines->Add("el "+IntToStr(X)+","+IntToStr(Y)+","+IntToStr(Sprite->Width)+","+IntToStr(Sprite->Height));
				//Map.Cell[CellX][CellY].Sprites.push_back(TMap::TSprite(SelSprite,X,Y));
				Map.SpritesList.push_back(TMap::TSprite(SelSprite,X,Y));
				//Log->Lines->Add(">"+IntToStr(CellX)+IntToStr(CellX)+":"+IntToStr(X)+IntToStr(Y));
				RX = -300;
			}
			else //удаление спрайта
			{
				std::vector<TMap::TSprite>::iterator el,lishn=Map.SpritesList.end();
				for (el = Map.SpritesList.begin(); el != Map.SpritesList.end(); ++el)
					if (X>=el->x&&Y>=el->y&&X<=el->x+Map.Sprites[el->Index]->Width&&Y<=el->y+Map.Sprites[el->Index]->Height)
						lishn = el;
				if (lishn != Map.SpritesList.end())
				{
					if (MovedBtn->Down)
					{
						SetSprite(lishn->Index);
						CellBtn->Down = true;
						RangeBtnClick(Sender);
					}
					OutRepaint();
//					if (lishn->y < 0 && CellY > 0)
//						OutDrawCell(Sender, CellX, CellY-1,
//							TRect(Out->CellRect(CellX,CellY-1)), RangeState);
//					if (lishn->x < 0 && CellX > 0)
//						OutDrawCell(Sender, CellX-1, CellY,
//							TRect(Out->CellRect(CellX-1,CellY)), RangeState);
					Map.SpritesList.erase(lishn);
				}
			}
			return;
		}   //*/

		if (CellBtn->Down || RangeBtn->Down)
		{
			Painting = true; //TODO:Paint suda
			SetCell(CellX, CellY);
		} else
		if (MovedBtn->Down)
		{      //TODO:DDD

      }
		UndoCurr = 0;
		//if ( (Brush == bAR)&&(DrawAnom == false) )
		//ADrawAnomallyExecute(NULL);
		//DrawAnomallyBtn->Click();
	} else
	if (Button == mbMiddle)
	{
		//Log->Text = PTiles->ItemIndex;//=-1всегда
		if (Map.Cell[CellX][CellY].Image == Map.Variants[Map.Cell[CellX][CellY].Image])
			return;
		Map.Cell[CellX][CellY].Image = Map.Variants[Map.Cell[CellX][CellY].Image];
		if (Map.Cell[CellX][CellY].Image >= Map.TilesCount)
			Map.Cell[CellX][CellY].Image = 0;
		//Tiles->GetBitmap(Map.Cell[CellX][CellY].Image, CurrTile); // тут получаешь нужное изображение по индексу из ImageList-а
		Tiles->Draw(Out->Canvas, SelX*TILESIZE, SelY*TILESIZE, Map.Cell[CellX][CellY].Image);
Out->Refresh();
		//TCanvas *cv = static_cast<TDrawGrid*>(Sender)->Canvas;
		//TRect rc = Out->CellRect(X,Y); Tiles->Draw(Out->Canvas, rc.Left, rc.Top, Map.Cell[X][Y].Image); //в исходном размере
//		Out->Canvas->StretchDraw(Out->CellRect(X,Y), CurrTile);
		StatusBar->Panels->Items[STTILE]->Text = Map.file->Strings[Map.Cell[CellX][CellY].Image];
	} else
	if (Button == mbRight)
	{
		SelectedTile = Map.Cell[CellX][CellY].Image;
		NCurrTile->Caption = "Тайл: "+Map.TileName[SelectedTile]; //PTiles->Items->Items[SelectedTile]->Caption;
		MoveX = SelX;
		MoveY = SelY;
		MapMoving = true;
		Out->Cursor = crSizeAll;
		NeedPopup = true;
	}
}
//---------------------------------------------------------------------------
//Движение мышки над полем
void __fastcall TEditorForm::OutMouseMove(TObject *Sender, TShiftState Shift,
			 int X, int Y)
{
	if (GetCellOf(X,Y) == false)
	{
		StatusBar->Panels->Items[STX]->Text = "X";
		StatusBar->Panels->Items[STY]->Text = "Y";
		StatusBar->Panels->Items[SR]->Text = "R";
		StatusBar->Panels->Items[SA]->Text = "A";
		StatusBar->Panels->Items[STTILE]->Text = "";
		return;
   }
	if (MapMoving)
	{
		int mx=SelX, my=SelY;
		if (mx >= 0 && my >= 0)
			if (MoveX != mx || MoveY != my)
			{
				if (mx < MoveX && ScrollWi->Position+VisibleColCount < Map.Width)
					{ ScrollWi->Position++; MoveX = mx+1; }
				else if (mx > MoveX && ScrollWi->Position > 0)
						{ ScrollWi->Position--; MoveX = mx-1; }
				if (my < MoveY&& ScrollHe->Position+VisibleRowCount < Map.Height)
					{ ScrollHe->Position++; MoveY = my+1; }
				else if (my > MoveY && ScrollHe->Position > 0)
						{ ScrollHe->Position--; MoveY = my-1; }
				//Log->Lines->Add(IntToStr(mx)+" "+IntToStr(my));
				MoveX = mx;
				MoveY = my;
				NeedPopup = false;
			}
   }
	if (PanelSprites->Collapsed == false && SelSprite >= 0)
	{
////		Sprite->SetBounds(X-Sprite->Width,Y-Sprite->Height,Sprite->Width,Sprite->Height);
		int w = Sprite->Width;
		int h = Sprite->Height;
		X = X*TILESIZE/CellSize;
		Y = Y*TILESIZE/CellSize;
		//Восстанавливаем
		if (RX > -300) //Это клик
		Out->Canvas->CopyRect(TRect(RX,RY,RX+w,RY+h)
			,Store->Canvas
			,TRect(0,0,w,h));
		//Сохраняем
		Store->Canvas->CopyRect(TRect(0,0,w,h)  //куда
			,Out->Canvas                         //откуда
			,TRect(X-w,Y-h,X,Y));                //откуда
		//Рисуем новое
		//Log->Lines->Add("refr"+IntToStr(X)+","+IntToStr(Y)+" "+IntToStr(X-w)+","+IntToStr(Y-h));
		//Out->Canvas->Draw(X-w,Y-h,Sprite);
		Out->Canvas->Draw(X-w,Y-h,Sprite);
		//Out->Refresh();
		RX = X-w;
		RY = Y-h;
		return;
	}
	if (RulerBtn->Down)
	{
		int dx = Ruler.x > X ? Ruler.x - X : X - Ruler.x;
		int dy = Ruler.y > Y ? Ruler.y - Y : Y - Ruler.y;
		int dist = sqrt(dx*dx + dy*dy);
		double metr = dist / PixelOnMeter;
		StatusBar->Panels->Items[STTILE]->Text = FloatToStrF(metr, ffGeneral, 7, 2)+" метров.";//IntToStr(dx)+" "+IntToStr(dy);
	}
	X = CellX; Y = CellY;

		StatusBar->Panels->Items[STX]->Text = "X="+IntToStr(X);
		StatusBar->Panels->Items[STY]->Text = "Y="+IntToStr(Y);
		StatusBar->Panels->Items[SR]->Text = "R="+IntToStr(Map.Cell[X][Y].Radiation);
		StatusBar->Panels->Items[SA]->Text = "A="+IntToStr(Map.Cell[X][Y].Anomally);
		if (RulerBtn->Down == false)
			if (Map.Cell[X][Y].Image != Map.UndefindedId)
				StatusBar->Panels->Items[STTILE]->Text = Map.file->Strings[Map.Cell[X][Y].Image];
			else
				StatusBar->Panels->Items[STTILE]->Text = Map.Cell[X][Y].Ident;
 	if (Painting)
	{
		//if (X != ACol || Y != ARow) //Я хз, но это реально какой то баг не мой
			//Log->Lines->Add("??"+IntToStr(ACol)+" "+IntToStr(ARow)+":"+IntToStr(SelTile));//Я хз, но это реально какой то баг не мой
		//	return;
		if (CBTilesLog->Checked)
			Log->Lines->Add("Cell"+IntToStr(CellX)+" "+IntToStr(CellY));
		SetCell(X, Y);
	}
}
//---------------------------------------------------------------------------
//РЕДАКТИРОВАНИЕ ЯЧЕЙКИ
void __fastcall TEditorForm::OutPaint(TObject *Sender)
{
	/*String ff = IntToStr(ACol)+","+IntToStr(ARow);;
	if (State.Contains(gdSelected))		ff += " Sel";
	if (State.Contains(gdFocused))		ff += " Foc";
	if (State.Contains(gdFixed))		ff += " Fix";
	Log->Lines->Add(ff); //*/
	if (Map.Cell == NULL)
		return;
	Draws++;
	//Out->Canvas->StretchDraw(Out->Canvas->ClipRect, In);
	//if (DrawTile)
	//Out->Canvas->
	//TGraphic *ggg;
	//Graphics::TBitmap* Image1;
	//Tiles->GetBitmap(1, Image1);
//	Tiles->GetBitmap(Map.Cell[ACol][ARow].Image, CurrTile); // тут получаешь нужное изображение по индексу из ImageList-а
	//TCanvas *cv = static_cast<TDrawGrid*>(Sender)->Canvas;
//	Out->Canvas->StretchDraw(Rect, CurrTile);
															 //*/
	//Tiles->Draw(Out->Canvas, Rect.Left, Rect.Top, Map.Cell[ACol][ARow].Image, true);
	if (DrawRad)
	{
//		if (Map.Cell[ACol][ARow].Radiation > 0)
//		{
//			Out->Canvas->Pen->Color = Map.Cell[ACol][ARow].ColorRad;
//			Out->Canvas->MoveTo(Rect.Left, Rect.Top);
//			Out->Canvas->LineTo(Rect.Right-1, Rect.Top);
//			Out->Canvas->LineTo(Rect.Right-1, Rect.Bottom-1);
//			Out->Canvas->LineTo(Rect.Left, Rect.Bottom-1);
//			Out->Canvas->LineTo(Rect.Left, Rect.Top);
//		}
	}
	if (TestDraw)
	{
//		if (Map.Cell[ACol][ARow].AnomTest)
		{
			Out->Canvas->Brush->Style = bsClear;
			Out->Canvas->Pen->Color = clRed;
//			Out->Canvas->Ellipse(Rect.Left, Rect.Top, Rect.Right, Rect.Bottom);
			Out->Canvas->Brush->Style = bsSolid;
      }
	} else
	if (DrawAnom)
	{
//		if (Map.Cell[ACol][ARow].Anomally > 0)
		{
			Out->Canvas->Brush->Style = bsClear;
//			Out->Canvas->Pen->Color = Map.Cell[ACol][ARow].ColorAnom;
 //			Out->Canvas->Ellipse(Rect.Left, Rect.Top, Rect.Right, Rect.Bottom);
			Out->Canvas->Brush->Style = bsSolid;
		}
	}
	if (DrawTrig)
	{
//		if (Map.Cell[ACol][ARow].Triggger > 0)
		{
			//Out->Canvas->Brush->
//			TriggersIm->Draw(Out->Canvas, Rect.Left,	Rect.Top, Map.Cell[ACol][ARow].Triggger, true);
		}
	}
	/*Log->Lines->Add(IntToStr(ACol)+" "+IntToStr(ARow)+":");
	if (State.Contains(gdSelected)  )
		Log->Lines->Add("gdSelected");
	if (State.Contains(gdFocused  )  )
		Log->Lines->Add("gdFocused");
	if (State.Contains(gdFixed    )  )
		Log->Lines->Add("gdFixed");     */
}
//---------------------------------------------------------------------------
//ОТПУСКАНИЕ  МЫШИ /не клик потому что клик не сработает если лив
void __fastcall TEditorForm::OutMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (Painting)
	{
		Painting = false;
		if (PanelSprites->Collapsed == false)	return;
		if (RangeBtn->Down)
		{
//			for (int i = Out->Selection.Left; i < Out->Selection.Right+1; ++i)
//				for (int j = Out->Selection.Top; j < Out->Selection.Bottom+1; ++j)
//				{
//					SetCell(i, j);
//					if (CBTilesLog->Checked)
//						Log->Lines->Add("klikSel"+IntToStr(i)+" "+IntToStr(j)+":"+IntToStr(SelTile));
//
//					Out->OnDrawCell(Sender,i,j,Out->CellRect(i, j), RangeState);
//				}
		}
	}
	if (RulerBtn->Down)
	{          //MousePos
		//TGridCoord ff = Out->MouseCoord()
		GetCursorPos(&Ruler);
		Ruler = Out->ScreenToClient(Ruler);
		//Log->Lines->Add(Ruler.x);  Log->Lines->Add(Ruler.y);
		ButtonsImages->Draw(Out->Canvas, Ruler.x, Ruler.y-15, 19);
	} else
	if (MovedBtn->Down)
	{
		if (PanelSprites->Collapsed == false)	return;
		GetCursorPos(&Ruler);
		Ruler = Out->ScreenToClient(Ruler);
		int x,y;
		GetCell();//(Ruler.x,Ruler.y,x,y);
		if (Map.Cell[x][y].Image == Map.Cell[MoveX][MoveY].Image)
			return;
		int tempi = Map.Cell[x][y].Image;
		Map.Cell[x][y].Image = Map.Cell[MoveX][MoveY].Image;
		Map.Cell[MoveX][MoveY].Image = tempi;
		if (CBTilesLog->Checked)
			Log->Lines->Add("MoveSel"+IntToStr(x)+" "+IntToStr(y)+":"+IntToStr(SelTile));

//		tileid temp;
//		strncpy(temp, Map.Cell[x][y].Ident, SYMBCOUNT);
//		strncpy(Map.Cell[x][y].Ident, Map.Cell[MoveX][MoveY].Ident, SYMBCOUNT);
//		strncpy(Map.Cell[MoveX][MoveY].Ident, temp, SYMBCOUNT);
//		Out->OnDrawCell(Sender,x,y,Out->CellRect(x, y), RangeState);
//		Out->OnDrawCell(Sender,MoveX,MoveY,Out->CellRect(MoveX, MoveY), RangeState);
	}
	if	(Button == mbRight)
	{
   	MapMoving = false;
		if (NeedPopup) //а это можно в онклик
		{
			GetCellOf(X,Y);//(X,Y,X,Y);
			if (CellX >= 0&&CellY >= 0)
				PopupMenuOut->Popup(X,Y);
		}
		Out->Cursor = crDefault;
	}
}
//---------------------------------------------------------------------------
//Потеря фокуса полем
void __fastcall TEditorForm::OutMouseLeave(TObject *Sender)
{
	if (PanelTile->Collapsed == false)
		PTiles->SetFocus();
	StatusBar->Panels->Items[STX]->Text = "X";
	StatusBar->Panels->Items[STY]->Text = "Y";
	StatusBar->Panels->Items[SR]->Text = "R";
	StatusBar->Panels->Items[SA]->Text = "A";
	StatusBar->Panels->Items[STTILE]->Text = "";
	//Log->Lines->Add(IntToStr(RX)+IntToStr(RY));
	if (SelSprite >= 0)
		if (RX > 0 && RY > 0)
			Out->Canvas->Draw(RX,RY,Store); //Для перевыбора спрайта
	MapMoving = false;
	NeedPopup = false;
}
//---------------------------------------------------------------------------
//Обновить заголовок окна
void TEditorForm::RefreshLocationName(String FileName)
{
	for (int i=FileName.Length(); i>1; --i)
		if (FileName[i] == '\\')
		{
			FileName = FileName.SubString(i+1, FileName.Length());
			break;
		}
	EditorForm->Caption = FileName.SubString(1, FileName.Length()-4) + " - Stalker Location Editor";
}
//---------------------------------------------------------------------------
//Запись ячейки SetCell
inline void TEditorForm::SetCell(int Col, int Row)
{
	if (Brush == bTile)
	{
		if (UndoCurr < UNDOTILELIMIT)
		{
			Undo[UndoCurr].Cell = &Map.Cell[Col][Row];
			Undo[UndoCurr].Tile = Map.Cell[Col][Row].Image;
			UndoCurr++;
		}
		Map.Cell[Col][Row].Image = SelTile;
		if (Map.Cell[Col][Row].Variant >= TILEVARIA)
			Map.Cell[Col][Row].Variant = 0;
		Tiles->Draw(Out->Canvas, SelX*TILESIZE, SelY*TILESIZE, Map.Cell[Col][Row].Image);
		Out->Refresh();
	} else
	if (Brush == bAR)
	{
		if (AR->ItemIndex == 0)
		{
			if ( (CursorMode == bSet)||(ARRandom->Checked == false) )
			{
				Map.Cell[Col][Row].Anomally = SelAnom;
				Map.Cell[Col][Row].ColorAnom = ColorAnom;
			} else
			{
				Map.Cell[Col][Row].SetAnomally(GetResultCursorPower(Map.Cell[Col][Row].Anomally, SelAnom));//   Anomally =
				//Map.Cell[Col][Row].ColorAnom = Map.GetAnomallyColor(Map.Cell[Col][Row].Anomally);
			}
		} else
		{
      	if ((CursorMode == bSet)||(ARRandom->Checked == false))
			{
				Map.Cell[Col][Row].Radiation = SelRad;
				Map.Cell[Col][Row].ColorRad = ColorRad;
			} else
			{
				Map.Cell[Col][Row].SetRadiation(GetResultCursorPower(Map.Cell[Col][Row].Radiation, SelRad));
			}
		}
	} else
	if (Brush == bTrig)
	{
		Map.Cell[Col][Row].Triggger = SelTrig;
	}
}
//---------------------------------------------------------------------------
//Посчитать результирующую силу радиац аном
int TEditorForm::GetResultCursorPower(int Curr, int New)
{
	if (CursorMode == bSet)
	{
		return New;
	} else
	if (CursorMode == bAdd)
	{
		Curr += New;
		if (Curr > 100)
			return 100;
		return Curr;
	} else
	if (CursorMode == bRem)
	{
		Curr -= New;
		if (Curr < 0)
			return 0;
		return Curr;
	}
	return New;
}
//---------------------------------------------------------------------------
//Ready
void TEditorForm::Ready(bool State)
{
	NInfo->Enabled = State;
	NTestAnom->Enabled = State;
	Out->Enabled = State;
	FileSave->Enabled = State;
	FileSaveAs->Enabled = State;
	NExport->Enabled = State;	//SavePicture1->Enabled = State;
	NReplace->Enabled = State;
	NCopy->Enabled = State;
	ScrollHe->Enabled = State;
	ScrollWi->Enabled = State;
	RX = -300;
	if (State)
	{
		ScrollHe->Max = Map.Height - 1;
		ScrollWi->Max = Map.Width - 1;
		OutRepaint();
	}
}
//---------------------------------------------------------------------------
//аномально <-> радиоактив клик
void __fastcall TEditorForm::ARClick(TObject *Sender)
{
	if (AR->ItemIndex == 0)
		ARPower->Hint = "Вероятность появления аномалии";
	else
		ARPower->Hint = "Сила и вероятность появления радиации";
	ARRandom->Tag = 1;
	ARPowerEChange(Sender);
}
//---------------------------------------------------------------------------
//Правка - Заменить
void __fastcall TEditorForm::NReplaceClick(TObject *Sender)
{
	//wchar_t PrewIdent = Map.TileIdent[PrewTile];
	tileid CurrIdent;
	strncpy(CurrIdent, Map.Idents[SelTile], SYMBCOUNT);
	String ggg = L"Заменить "+Map.TileName[PrewTile]+L" на "+Map.TileName[SelTile]+L"?";
	if (Application->MessageBoxA(ggg.w_str(),L"Замена",MB_YESNO) == ID_YES)
	{
//		for (int c = 0; c < Out->ColCount; ++c)
//			for (int r = 0; r < Out->RowCount; ++r)
//				if (Map.Cell[c][r].Image == PrewTile)
//				{
//					Map.Cell[c][r].Image = SelTile;
//					//Map.Cell[c][r].Ident = CurrIdent;
////					strncpy(Map.Cell[c][r].Ident, CurrIdent, SYMBCOUNT);
//				}
		OutRepaint();
	}
}
//---------------------------------------------------------------------------
//Попуп - Копировать
void __fastcall TEditorForm::NCopyClick(TObject *Sender)
{
	static int cleft=0,ctop=0,cright=0,cdown=0;
	if (PopupMenuOut->Tag <= 1)
	{
		ShowMessage("Копирование в три клика правой кнопкой:\n\
1: Левый верхний угол копируемой области;\n\
2: Правый нижний угол копируемой области;\n\
3: Левый верхний угол вставки.");
		NCopy->Caption = "Копирование 2";
		PopupMenuOut->Tag = 2;
		cleft = StatusBar->Panels->Items[STX]->Text.Delete(1,2).ToInt();
		ctop = StatusBar->Panels->Items[STY]->Text.Delete(1,2).ToInt();
	} else if (PopupMenuOut->Tag == 2)
	{
		NCopy->Caption = "Копирование 3";
		PopupMenuOut->Tag = 3;
		cright = StatusBar->Panels->Items[STX]->Text.Delete(1,2).ToInt();
		cdown = StatusBar->Panels->Items[STY]->Text.Delete(1,2).ToInt();
	}
	else
	{
		NCopy->Caption = "Копирование 1";
		PopupMenuOut->Tag = 1;
		int px = StatusBar->Panels->Items[STX]->Text.Delete(1,2).ToInt() - cleft;
		int py = StatusBar->Panels->Items[STY]->Text.Delete(1,2).ToInt() - ctop;
		for (int X = cleft; X <= cright; ++X)
			for (int Y = ctop; Y <= cdown; ++Y)
			{
				Map.Cell[X+px][Y+py].Image = Map.Cell[X][Y].Image;
				//Map.Cell[X+px][Y+py].Ident = Map.Cell[X][Y].Ident;
//				strncpy(Map.Cell[X+px][Y+py].Ident, Map.Cell[X][Y].Ident, SYMBCOUNT);
			}
			OutRepaint();
   }
}
//---------------------------------------------------------------------------
//ToolBar: Рисовать триггеры
void __fastcall TEditorForm::ADrawTriggersExecute(TObject *Sender)
{
	DrawTrig = !DrawTrig;
	DrawTrigBtn->Down = DrawTrig;
	Out->Refresh();
}
//---------------------------------------------------------------------------
//Выбор триггера
void __fastcall TEditorForm::PTriggersButtonClicked(TObject *Sender, int Index)
{
	if (SelTrig != Index)
   {
		SelTrig = Index;
		if (DrawTrig == false)
		{
      	DrawTrigBtn->Down = true;
			DrawTrig = true;
			OutRepaint();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::openTRIGClick(TObject *Sender)
{
	Map.DebugOpenTrig = openTRIG->Checked;
}
//---------------------------------------------------------------------------
//Изменение аномалии, создание цвета
void __fastcall TEditorForm::ARPowerEChange(TObject *Sender)
{
	if (AR->ItemIndex == 0) //Выбрано Аномальность
	{
		//ARPower->Value = SelAnom;
		ARPowerE->Color = Map.GetAnomallyColor(ARPower->Position);
		if (ARPower->Position > 70)
			ARPowerE->Font->Color = clWhite;
		else
			ARPowerE->Font->Color = clBlack;
		//if (ARPower == AnomNumb)
		//{
			SelAnom = ARPower->Position;
			ARRandom->Checked = true;
			ARPowerE->Color = ColorAnom; //Map.GetAnomallyColor(SelAnom);
		//}
	}
	else //Радиоактивность
	{
		//ARPower->Value = 	SelRad;
		SelRad = ARPower->Position;
		ARPowerE->Color = ColorRad; //TColor(Map.GetRadiationColor(ARPower->Value));
	}

	/*if (ARRandom->Tag == 0)
	{
		if (AR->ItemIndex == 0)
		{
			if (DrawAnom == false)
         {
         	DrawAnomallyBtn->Down = true;
				DrawAnom = true;
				Out->Refresh();
			}
		}
		else
		{
			if (DrawRad == false)
         {
         	DrawRadiationBtn->Down = true;
				DrawRad = true;
				Out->Refresh();
			}
      }
		ARRandom->Checked = true;
	}
	else
		{	ARRandom->Tag = 0; }  */
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::ScalerChange(TObject *Sender)
{
	//if (Scaler->Position == scallercaeb)
	//	return;
	scallercaeb = Scaler->Position;
	static int scroler = TILESIZE / 16; //64
	CellSize = TILESIZE - Scaler->Position*scroler;
//	Out->DefaultColWidth = cell;           c
//	Out->DefaultRowHeight = cell;
	PixelOnMeter = (double)CellSize / METERS;
	if (PanelSprites->Collapsed == false && SelSprite >= 0)
		SetSprite(-1);
   OutPanelResize(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete CurrTile;
	for (int i = 0; i < Map.SpritesCount; ++i)
		delete Sprites[i];
	delete [] Sprites;
	delete Sprite;
	delete Store;
	delete In;
}
//---------------------------------------------------------------------------

void TEditorForm::CreateNoneTile()
{
	Graphics::TBitmap* NoneTile = new Graphics::TBitmap;
	NoneTile->Width = Tiles->Width;
	NoneTile->Height = Tiles->Height;
	NoneTile->Canvas->Brush->Color = clInactiveCaptionText;
	NoneTile->Canvas->Font->Color = clHotLight;
	NoneTile->Canvas->FillRect(TRect(0,0,TILESIZE,TILESIZE));
	NoneTile->Canvas->Font->Height = Tiles->Height;
	NoneTile->Canvas->TextOutA(TILESIZE/3,0,"?");
	NoneTile->Canvas->Brush->Color = clGreen;
	NoneTile->Canvas->FrameRect(TRect(0,0,TILESIZE,TILESIZE));
	Map.UndefindedId = Tiles->Count;
	Tiles->Add(NoneTile, NULL);
	delete NoneTile;
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::ADrawGrid40Execute(TObject *Sender)
{
	Out->Canvas->Pen->Color = clFuchsia;
	int TileZize = TILESIZE - Scaler->Position*64;
	int Tile2 = TileZize*2;
	int g = DrawGrid ? 2 : 0;
//	int W = Out->VisibleColCount*Out->DefaultColWidth+g*Out->VisibleColCount;
//	int H = Out->VisibleRowCount*Out->DefaultRowHeight+g*Out->VisibleRowCount;
//	int st1 = DrawGrid ? Tile2+1 : 0;
//	int st2 = DrawGrid ? TileZize : TileZize;
//	for (int i = Out->LeftCol % 2 == 0 ? st1 : st2; i < W; i+=Tile2+g)
//	{
//		Out->Canvas->MoveTo(i,0);
//		Out->Canvas->LineTo(i,H);
//	}
//	for (int j = Out->TopRow % 2 == 0 ? st1 : st2; j < H; j+=Tile2+g)
//	{
//		Out->Canvas->MoveTo(0,j);
//		Out->Canvas->LineTo(W,j);
//	}
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::NReplaceSelClick(TObject *Sender)
{
	int X = StatusBar->Panels->Items[STX]->Text.SubString(3,StatusBar->Panels->Items[STX]->Text.Length()-2).ToInt();
	int Y = StatusBar->Panels->Items[STY]->Text.SubString(3,StatusBar->Panels->Items[STY]->Text.Length()-2).ToInt();
	tileid SelIdent, ActIdent;
	strncpy(ActIdent, Map.Cell[X][Y].Ident, SYMBCOUNT);
	strncpy(SelIdent, Map.Idents[SelTile], SYMBCOUNT);
	String what;
	if (Map.Cell[X][Y].Image != Map.UndefindedId)
		what = Map.file->Strings[Map.Cell[X][Y].Image];
	else
		what = L"("+String(Map.Cell[X][Y].Ident)+L")=Неизвестный тип тайла";
	what = L"Заменить "+what+L" на "+Map.TileName[SelTile]+L"?";
	if (Application->MessageBoxA(what.w_str(),L"Автозамена",MB_YESNO) == ID_YES)
	{
//		for (int c = 0; c < Out->ColCount; ++c)
//			for (int r = 0; r < Out->RowCount; ++r)
//				if (strncmp(ActIdent, Map.Cell[c][r].Ident, SYMBCOUNT) == 0)
//				{
//					Map.Cell[c][r].Image = SelTile;
//					strncpy(Map.Cell[c][r].Ident, SelIdent, SYMBCOUNT);
//				}
		OutRepaint();
	}
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::RangeBtnClick(TObject *Sender)
{
	if (CellBtn->Down)
	{
//		Out->Options >> goRangeSelect; //Извлечь false
		Out->Cursor = crDefault;
	} else
	if (RangeBtn->Down) //if (Map->Options.Contains(goRangeSelect))
	{
//		Out->Options << goRangeSelect; //Добавить true
		Out->Cursor = crDrag;
	} else
	if (RulerBtn->Down) //if (Map->Options.Contains(goRangeSelect))
	{
		Out->Cursor = crCross;
	} else
	if (MovedBtn->Down)
	{
		Out->Cursor = crHandPoint;
   }
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::NullTileClick(TObject *Sender)
{
	//Log->Lines->Add(PixelOnMeter);
	//PTiles->Items->Items[1]->Caption = "ff";
	//for (int i = 0; i < Map.TilesCount+1; ++i)
	//	Log->Lines->Add(Map.Variants[i]);
	//Log->Lines->Add(Out->VisibleRowCount);
	//Log->Lines->Add(Out->TopRow);
	//if (Sprite->Width <= 11)
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::NCurrTileClick(TObject *Sender)
{
	PTilesButtonClicked(Sender, SelectedTile);
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::MoveToolExecute(TObject *Sender)
{
	if (MovedBtn->Down)
	{
		CellBtn->Down = true;
      Out->Cursor = crDefault;
	}
	else
	{
		MovedBtn->Down = true;
//		Out->Options >> goRangeSelect; //Извлечь false
		Out->Cursor = crHandPoint;
		if (SelSprite > -1)
		{
			//RX = -300;
			Out->Canvas->CopyRect(TRect(RX,RY,RX+Sprite->Width,RY+Sprite->Height)
				,Store->Canvas
				,TRect(0,0,Sprite->Width,Sprite->Height));
			SelSprite = -1;
		}
   }
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::loadspritesClick(TObject *Sender)
{
	Map.LoadSprites("Sprites\\SPRITES.txt");
	Sprites = new TImage*[Map.SpritesCount];
	float const MaxW = 128;
	float const MaxH = 100;
	for (int i = 0; i < Map.SpritesCount; i++)
	{
		Sprites[i] = new TImage(PSprites);
		Sprites[i]->Parent = PSprites;
		Sprites[i]->OnClick = SpritesClick;
		Sprites[i]->Hint = Map.SpriteNames->Values[Map.SpriteNames->Names[i]];
		//Sprites[i]->AutoSize = true; //иначе 105ширина
      Sprites[i]->Transparent = true;
		Sprites[i]->Tag = i;
		if (Map.Sprites[i]->Width <= MaxW&&Map.Sprites[i]->Height <= MaxH)
			Sprites[i]->SetBounds(0,0,Map.Sprites[i]->Width,Map.Sprites[i]->Height);
		else
		{
			Sprites[i]->Stretch = true;
			if (Map.Sprites[i]->Width / MaxW > Map.Sprites[i]->Height / MaxH)
				Sprites[i]->SetBounds(0,0, MaxW, Map.Sprites[i]->Height * MaxW / Map.Sprites[i]->Width);
			else
				Sprites[i]->SetBounds(0,0,Map.Sprites[i]->Width * MaxH / Map.Sprites[i]->Height , MaxH);
		}
		//	Map.Sprites[i].Bitmap->Canvas->StretchDraw()
		//Sprites[i]->Canvas->StretchDraw(TRect(0,0,100,100),Map.Sprites[i].Graphic);
		Sprites[i]->Picture->Assign(Map.Sprites[i]);
		//Map.SpriteSizes[i].x = Sprites[i]->Width;
		//Map.SpriteSizes[i].y = Sprites[i]->Height;
		//strncpy(Idents[i], file->Names[i].c_str(), SYMBCOUNT);
		//Idents[i][SYMBCOUNT] = '\0';
		//Idents[i][0] = file->Names[i][1];
		//Maps.Name[i] = file->Values[i+1];
	}
}
//---------------------------------------------------------------------------
void __fastcall TEditorForm::SpritesClick(TObject *Sender)
{
	TImage* curr = (TImage*)Sender;
	SetSprite(curr->Tag);
	CellBtn->Down = true;
	CellBtn->Click();
}
//---------------------------------------------------------------------------
void __fastcall TEditorForm::PanelSpritesExpand(TObject *Sender)
{
	PanelAR->Collapse();
	PanelTriggers->Collapse();
	PanelTile->Collapse();
	PanelSprites->Height = CategoryPanelGroup1->Height - PANELSCHOP;
	PSprites->Width ++; PSprites->Width ++; //Это спасает об бага размера
	if (Map.SpritesCount == 0)
		loadspritesClick(Sender);
	Painting = false;
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::BitBtn1Click(TObject *Sender)
{
	Log->Lines->Clear();
	for (int i = 0; i < Map.Width; ++i)
		for (int j = 0; j < Map.Height; ++j)
		{
			if (strncmp(Map.Cell[i][j].Ident, Map.Idents[Map.Cell[i][j].Image], SYMBCOUNT) != 0)
			{
				Log->Lines->Add(IntToStr(i)+","+IntToStr(j));
				strncpy(Map.Cell[i][j].Ident, Map.Idents[Map.Cell[i][j].Image], SYMBCOUNT);
			}
		}
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::NAboutClick(TObject *Sender)
{
	Out->Canvas->StretchDraw(TRect(0,64,64,128), Map.Sprites[SelSprite]->Graphic);
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::CBdoublebufClick(TObject *Sender)
{
//	Out->DoubleBuffered = CBdoublebuf->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::StatusBarDblClick(TObject *Sender)
{
	//ScrollBox1->Visible = !ScrollBox1->Visible;
	PanelSprites->Collapse();
	PanelSprites->Expand();
  //	ScrollBox1->Hide();   //	ScrollBox1->Show();	//ScrollBox1->Repaint();
	//PSprites->Hide();//();// = true;//();	//PSprites->Show();	//PSprites->
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::ScrollBox1Resize(TObject *Sender)
{
/*	if (Sprite->Visible)
	{
		PanelSprites->Collapse();
		PanelSprites->Expand();
	}          */
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::DeleteSpriteClick(TObject *Sender)
{
	SelSprite = -1;
	if (RX == 0 && RY == 0)
		Out->Canvas->Draw(0,0,Store); //Для перевыбора спрайта
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::OutKeyPress(TObject *Sender, wchar_t &Key)
{
	if (Key == VK_SPACE)
	{
		Out->Refresh();
   }
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::FormKeyPress(TObject *Sender, wchar_t &Key)
{
	if (Key == VK_SPACE)
	{
		Out->Refresh();
	}	
}
//---------------------------------------------------------------------------
void __fastcall TEditorForm::BitBtn2Click(TObject *Sender)
{
	Log->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::OutMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
	Handled = true;
	//Log->Lines->Add("UP");
	if (ScrollHe->Position > 0)
		ScrollHe->Position--;
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::OutMouseWheelDown(TObject *Sender, TShiftState Shift,
			 TPoint &MousePos, bool &Handled)
{
	Handled = true;
	if (ScrollHe->Position + VisibleRowCount < Map.Height)
		ScrollHe->Position++;
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::Button1Click(TObject *Sender)
{
	Log->Lines->Add("Count="+IntToStr(Tiles->Count));
	Log->Lines->Add(sizeof(*Tiles));
}
//---------------------------------------------------------------------------
void __fastcall TEditorForm::OutPanelResize(TObject *Sender)
{
	Out->Picture->Graphic->SetSize(Out->Width*TILESIZE/CellSize, Out->Height*TILESIZE/CellSize);
	VisibleColCount = Out->Width / CellSize + 1;
	VisibleRowCount = Out->Height / CellSize + 1;
	OutRepaint();
}
//---------------------------------------------------------------------------
void TEditorForm::OutRepaint()
{
	if (Map.Cell == NULL)
		return;
	int Row = VisibleRowCount;// + ScrollV->Position;
	int Col = VisibleColCount;// + ScrollH->Position;
	if (Col > Map.Width - ScrollWi->Position)
	{
		Col = Map.Width - ScrollWi->Position;
		Out->Canvas->Brush->Color = clSkyBlue;
		Out->Canvas->FillRect(TRect(0,0,Out->Picture->Graphic->Width,Out->Picture->Graphic->Height));
	}
	if (Row > Map.Height - ScrollHe->Position)
	{
		Row = Map.Height - ScrollHe->Position;
   	Out->Canvas->Brush->Color = clMoneyGreen;
		Out->Canvas->FillRect(TRect(0,0,Out->Picture->Graphic->Width,Out->Picture->Graphic->Height));
	}
	for (int i = 0; i < Col; ++i)
		for (int j = 0; j < Row; ++j)
			Tiles->Draw(Out->Canvas, i*TILESIZE, j*TILESIZE, Map.Cell[i+ScrollWi->Position][j+ScrollHe->Position].Image);

	//Map.Cell[i+ScrollWi->Position][j+ScrollHe->Position].Sprites
	int ACol = 0+ScrollWi->Position;
	int ARow = 0+ScrollHe->Position;
	int L,T,R,B,IND;
	int ml, mt, mr, mb;
	ml = ScrollWi->Position * TILESIZE;
	mt = ScrollHe->Position * TILESIZE;
	mr = ml + Out->Picture->Graphic->Width;
	mb = mt + Out->Picture->Graphic->Height;
	Log->Lines->Add("m"+IntToStr(mr)+","+IntToStr(mb));
	if (Map.SpritesList.size() > 0)
		for (std::vector<TMap::TSprite>::iterator el = Map.SpritesList.begin(); el != Map.SpritesList.end(); ++el)
		{
			//Log->Clear();
			//Log->Lines->Add("Rect"+IntToStr((int)Rect.Left)+","+IntToStr((int)Rect.top)+","+IntToStr((int)Rect.Width())+","+IntToStr((int)Rect.Height()));
			//Log->Lines->Add("el->"+IntToStr(el->x)+","+IntToStr(el->y));
			IND = el->Index;
			if (el->x < ml || el->y < mt || el->x > mr || el->y > mb)
				continue;
			//L = ceil(double(el->x) * CellSize / TILESIZE);
			//T = ceil(double(el->y) * CellSize / TILESIZE);
			//L += CellSize*ACol;
			//T += CellSize*ARow;//Rect.top;
			//R = Map.Sprites[el->Index]->Width * CellSize / TILESIZE;
			//B = Map.Sprites[el->Index]->Height * CellSize / TILESIZE;
			L = el->x - ml;
			T = el->y - mt;
			Out->Canvas->Draw(L, T, Map.Sprites[el->Index]->Graphic);
			//draw тоже работаетс альфа и стреч
			//Out->Canvas->StretchDraw(TRect(el->x
			//,el->y
			//,el->x+100
			//,el->y+50)
			//,Map.Sprites[IND]->Graphic);
		}

	//for (int i = 0; i < In->Width; i+=TILESIZE)
	//		for (int j = 0; j < In->Height; j+=TILESIZE)
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::ScrollWiChange(TObject *Sender)
{
	//Log->Lines->Add(ScrollPos);
	//Log->Lines->Add(ScrollWi->Position);
	OutRepaint();
	Out->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::ScrollHeChange(TObject *Sender)
{
	//Log->Lines->Add(ScrollPos);
	Log->Lines->Add(ScrollHe->Position);
	OutRepaint();
	Out->Refresh();
}
//---------------------------------------------------------------------------
bool TEditorForm::GetCellOf(int X, int Y)
{
	if (X < 0 || Y < 0 || X >= Out->Width || Y >= Out->Height)
	{
		SelX = SelY = CellX = CellY = -1;
		return false;
	}
	SelX = X / CellSize;
	SelY = Y / CellSize;
	CellX = SelX + ScrollWi->Position;
	CellY = SelY + ScrollHe->Position;
	if (CellX >= Map.Width || CellY >= Map.Height)
	{
		SelX = SelY = CellX = CellY = -1;
		return false;
	}
	return true;
}
//---------------------------------------------------------------------------
bool TEditorForm::GetCell()
{
	tagPOINT mouse;
	GetCursorPos(&mouse);
	mouse = Out->ScreenToClient(mouse);
	return GetCellOf(mouse.x, mouse.y);
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::sprisClick(TObject *Sender)
{
	for (std::vector<TMap::TSprite>::iterator el = Map.SpritesList.begin(); el != Map.SpritesList.end(); ++el)
	{
		Log->Lines->Add(IntToStr(el->Index)+":"+IntToStr(el->x)+" "+IntToStr(el->y));
	}
}
//---------------------------------------------------------------------------
//Переключение вида кнопок тайлов
void __fastcall TEditorForm::NTilesNamesClick(TObject *Sender)
{
	NTilesNames->Checked = !NTilesNames->Checked;
	if (NTilesNames->Checked)
   {
		PTiles->ButtonOptions << gboFullSize;
		PTiles->ButtonOptions << gboShowCaptions;
		for (int i = 0; i < Map.TilesCount; ++i)
		{
			PTiles->Items->Items[i]->Hint = "(?)";
			PTiles->Items->Items[i]->Hint[2] = Map.TileIdent[i];
		}
	} else
	{
		PTiles->ButtonOptions >> gboFullSize;
		PTiles->ButtonOptions >> gboShowCaptions;
		for (int i = 0; i < Map.TilesCount; ++i)
			PTiles->Items->Items[i]->Hint = Map.TileName[i] +PTiles->Items->Items[i]->Hint;
		PTiles->Height = Map.TilesCount*Tiles->Height/5;
	}
	PTiles->Repaint();
}
//---------------------------------------------------------------------------
//ToolBar: Отображение сетки
void __fastcall TEditorForm::ADrawGridExecute(TObject *Sender)
{
	DrawGrid = !DrawGrid;
	//DrawGridBtn->Down = DrawGrid;
	if (DrawGrid)
		Out->GridLineWidth = 1;
	else
		Out->GridLineWidth = 0;
}
//---------------------------------------------------------------------------
//Нажатие любой клавиши
void __fastcall TEditorForm::OutKeyPress(TObject *Sender, wchar_t &Key)
{
	//ListBox1->Items->Add(Key);
	if (Brush == bTile)
	{
		for (int i = 0; i < Map.TilesCount; ++i)
		{
			if (Map.TileIdent[i] == Key)
			{
				SelTile = i;
				StatusBar->Panels->Items[STTILE]->Text = PTiles->Items->Items[SelTile]->Caption;
			}
		}
	}
	else
	{
		if (Key == 'q')
		{
			if (Brush == bAR)	AR0->Checked = true;
			return;
		}
		else if ((Key == 'w')&&(Brush == bAR))
			AR100->Checked = true; //Anom111->OnClick(Sender); }
		else if (Key == 'e')
		{
			if (Brush == bAR)	ARRandom->Checked = true;// AnomRand->OnClick(Sender); }
			return;
		}
	}
}
//---------------------------------------------------------------------------
//Нажатие клавиши мышки (Начало редактирования)
void __fastcall TEditorForm::OutMouseActivate(TObject *Sender, TMouseButton Button,
			 TShiftState Shift, int X, int Y, int HitTest, TMouseActivate &MouseActivate)
{
	if (Button == mbLeft)
	{
		Painting = true;
		UndoCurr = 0;
		//if ( (Brush == bAR)&&(DrawAnom == false) )
		//ADrawAnomallyExecute(NULL);
  		//DrawAnomallyBtn->Click();
	}
	if (Button == mbRight)
	{
		//Memo1->Text = IntToStr(X)+IntToStr(Y);
		Out->MouseToCell(X,Y,X,Y);
		SelectedTile = Map.Cell[X][Y].Image;
		NCurrTile->Caption = "Тайл: "+PTiles->Items->Items[SelectedTile]->Caption;
		//NCurrTile->Caption = IntToStr(X)+" "+IntToStr(Y);
   }
}
//---------------------------------------------------------------------------
 //Нажати кнопки тайла
void __fastcall TEditorForm::PTilesButtonClicked(TObject *Sender, int Index)
{
	PrewTile = SelTile;
	NPrewTile->Caption = "Тайл: "+PTiles->Items->Items[PrewTile]->Caption;
	SelTile = Index;
	StatusBar->Panels->Items[STTILE]->Text = PTiles->Items->Items[Index]->Caption;
}
//---------------------------------------------------------------------------
//Перерисовка ячейки (Запрос)
void __fastcall TEditorForm::OutDrawCell(TObject *Sender, int ACol, int ARow,
			 TRect &Rect, TGridDrawState State)
{
	draws++;
	/*String ff = IntToStr(ACol)+","+IntToStr(ARow);;
	if (State.Contains(gdSelected))		ff += " Sel";
	if (State.Contains(gdFocused))		ff += " Foc";
	if (State.Contains(gdFixed))		ff += " Fix";
	PTiles->Items->Items[0]->Caption = PTiles->Items->Items[1]->Caption;
	PTiles->Items->Items[1]->Caption = PTiles->Items->Items[2]->Caption;
	PTiles->Items->Items[2]->Caption = PTiles->Items->Items[3]->Caption;
	PTiles->Items->Items[3]->Caption = PTiles->Items->Items[4]->Caption;
	PTiles->Items->Items[4]->Caption = ff;   */
	if (Map.Cell == NULL)
		return;
	//if (DrawTile)
		Tiles->Draw(Out->Canvas, Rect.Left,	Rect.Top, Map.Cell[ACol][ARow].Image, true);
	if (DrawRad)
	{
		if (Map.Cell[ACol][ARow].Radiation > 0)
		{
			Out->Canvas->Pen->Color = Map.Cell[ACol][ARow].ColorRad;
			Out->Canvas->MoveTo(Rect.Left, Rect.Top);
			Out->Canvas->LineTo(Rect.Right-1, Rect.Top);
			Out->Canvas->LineTo(Rect.Right-1, Rect.Bottom-1);
			Out->Canvas->LineTo(Rect.Left, Rect.Bottom-1);
			Out->Canvas->LineTo(Rect.Left, Rect.Top);
		}
	}
	if (TestDraw)
	{
		if (Map.Cell[ACol][ARow].AnomTest)
		{
			Out->Canvas->Brush->Style = bsClear;
			Out->Canvas->Pen->Color = clRed;
			Out->Canvas->Ellipse(Rect.Left, Rect.Top, Rect.Right, Rect.Bottom);
			Out->Canvas->Brush->Style = bsSolid;
      }
	} else
	if (DrawAnom)
	{
		if (Map.Cell[ACol][ARow].Anomally > 0)
		{
			Out->Canvas->Brush->Style = bsClear;
			Out->Canvas->Pen->Color = Map.Cell[ACol][ARow].ColorAnom;
			Out->Canvas->Ellipse(Rect.Left, Rect.Top, Rect.Right, Rect.Bottom);
			Out->Canvas->Brush->Style = bsSolid;
		}
	}
	if (DrawTrig)
	{
		if (Map.Cell[ACol][ARow].Triggger > 0)
		{
			//Out->Canvas->Brush->
			TriggersIm->Draw(Out->Canvas, Rect.Left,	Rect.Top, Map.Cell[ACol][ARow].Triggger, true);
		}
	}
	/*Memo1->Lines->Add(IntToStr(ACol)+" "+IntToStr(ARow)+":");
	if (State.Contains(gdSelected)  )
		Memo1->Lines->Add("gdSelected");
	if (State.Contains(gdFocused  )  )
		Memo1->Lines->Add("gdFocused");
	if (State.Contains(gdFixed    )  )
		Memo1->Lines->Add("gdFixed");     */
}
//--------------------------------------------------------------------
//РЕДАКТИРОВАНИЕ ЯЧЕЙКИ
void __fastcall TEditorForm::OutSelectCell(TObject *Sender, int ACol, int ARow,
			 bool &CanSelect)
{
	if (Painting)
	{
		SetCell(ACol, ARow);
	}
}
//--------------------------------------------------------------------
//Окончание выбора ячейки
void __fastcall TEditorForm::OutClick(TObject *Sender)
{
	if (Painting)
	{
		Painting = false;
		if (RangeSelect)
		{
			for (int i = Out->Selection.Left; i < Out->Selection.Right+1; ++i)
				for (int j = Out->Selection.Top; j < Out->Selection.Bottom+1; ++j)
				{
					SetCell(i, j);
					Out->OnDrawCell(Sender,i,j,Out->CellRect(i, j), RangeState);
				}
		}
	}
}
//---------------------------------------------------------------------------
//Движение мышки над полем
void __fastcall TEditorForm::OutMouseMove(TObject *Sender, TShiftState Shift,
			 int X, int Y)
{
	Out->MouseToCell(X,Y,X,Y);
   if ((X >= 0)&&(Y >= 0))
	{
		StatusBar->Panels->Items[STX]->Text = "X="+IntToStr(X);
		StatusBar->Panels->Items[STY]->Text = "Y="+IntToStr(Y);
		StatusBar->Panels->Items[SR]->Text = "R="+IntToStr(Map.Cell[X][Y].Radiation);
		StatusBar->Panels->Items[SA]->Text = "A="+IntToStr(Map.Cell[X][Y].Anomally);
		if (Map.Cell[X][Y].Image != Map.UndefindedId)
			StatusBar->Panels->Items[STTILE]->Text = Map.file->Strings[Map.Cell[X][Y].Image];
		else
			StatusBar->Panels->Items[STTILE]->Text = Map.TileIdent[Map.Cell[X][Y].Image];
	}
	else
	{
		StatusBar->Panels->Items[STX]->Text = "X";
		StatusBar->Panels->Items[STY]->Text = "Y";
		StatusBar->Panels->Items[SR]->Text = "R";
		StatusBar->Panels->Items[SA]->Text = "A";
   }
}
//---------------------------------------------------------------------------
//Потеря фокуса полем
void __fastcall TEditorForm::OutMouseLeave(TObject *Sender)
{
	if (PanelTile->Collapsed == false)
		PTiles->SetFocus();
}
//---------------------------------------------------------------------------
//Обновить заголовок окна
void TEditorForm::RefreshLocationName(String FileName)
{
	for (int i=FileName.Length(); i>1; --i)
		if (FileName[i] == '\\')
		{
			FileName = FileName.SubString(i+1, FileName.Length());
			break;
		}
	EditorForm->Caption = FileName.SubString(1, FileName.Length()-4) + " - Stalker Location Editor";
}
//--------------------------------------------------------------------
//Раскрытие панели Тайлов
void __fastcall TEditorForm::PanelTileExpand(TObject *Sender)
{
	PanelAR->Collapse();
	PanelTriggers->Collapse();
	PanelTile->Height = CategoryPanelGroup1->Height - PANELSCHOP;
	Brush = bTile;
	PTiles->Width ++; PTiles->Width ++; //Это спасает об бага размера
}
//---------------------------------------------------------------------------
//Раскрытие панели Аномалий\Радиации
void __fastcall TEditorForm::PanelARExpand(TObject *Sender)
{
	PanelTile->Collapse();
	PanelTriggers->Collapse();
	PanelAR->Height = CategoryPanelGroup1->Height - PANELSCHOP;
	Brush = bAR;
	PanelAR->Width ++; PanelAR->Width ++; //Это спасает об бага размера
}
//---------------------------------------------------------------------------
//Раскрытие панели Триггеров
void __fastcall TEditorForm::PanelTriggersExpand(TObject *Sender)
{
	PanelTile->Collapse();
	PanelAR->Collapse();
	PanelTriggers->Height = CategoryPanelGroup1->Height - PANELSCHOP;
	Brush = bTrig;
	PanelTriggers->Width ++; PanelTriggers->Width ++; //Это спасает об бага размера
}
//---------------------------------------------------------------------------
//ToolBar: Рисовать Аномалии
void __fastcall TEditorForm::ADrawAnomallyExecute(TObject *Sender)
{
	TestDraw = false;
	DrawAnom = !DrawAnom;
	DrawAnomallyBtn->Down = DrawAnom;
	Out->Repaint();
	TGridDrawState State;
	State << gdSelected;//gdFixed;
	/*for (int i = 0; i < Map.Width; ++i)
		for (int j = 0; j < Map.Height; ++j)
			if (Map.Cell[i][j].Anomally != 0)
			{
				TRect Rect = Out->CellRect(i,j);
				OutDrawCell(Sender, 1, 1, Rect, State);
			}  */
	//Out->Refresh();
}
//---------------------------------------------------------------------------
//ToolBar: Рисовать Радиацию
void __fastcall TEditorForm::ADrawRadiationExecute(TObject *Sender)
{
	DrawRad = !DrawRad;
	DrawRadiationBtn->Down = DrawRad;
	DrawTile = false;
	Out->Refresh();
	DrawTile = true;
}
//---------------------------------------------------------------------------
//О: безопасно
void __fastcall TEditorForm::AR0Click(TObject *Sender)
{
	if (AR->ItemIndex == 0)
		SelAnom = 0;
	else
		SelRad = 0;
}
//---------------------------------------------------------------------------
//О: Опасно 100
void __fastcall TEditorForm::AR100Click(TObject *Sender)
{
	if (AR->ItemIndex == 0)
		SelAnom = 100;
	else
		SelRad = 100;
}
//---------------------------------------------------------------------------
//О: Случайная
void __fastcall TEditorForm::ARRandomClick(TObject *Sender)
{
	if (AR->ItemIndex == 0)
	{
		SelAnom = ARPower->Position;
		ARPowerE->Color = ColorAnom;// Map.GetAnomallyColor(SelAnom);
	}
	else
	{
		SelRad = ARPower->Position;
		ARPowerE->Color = ColorRad; //Map.GetRadiationColor(SelRad);
   }
}
//---------------------------------------------------------------------------
//Тип заполнения - SET
void __fastcall TEditorForm::ACursorSetExecute(TObject *Sender)
{
	CursorMode = bSet;
	CursorModeChange();
}
//---------------------------------------------------------------------------
//Тип заполнения - ADD
void __fastcall TEditorForm::ACursorAddExecute(TObject *Sender)
{
	CursorMode = bAdd;
	CursorModeChange();
}
//---------------------------------------------------------------------------
//Тип заполнения - DEC
void __fastcall TEditorForm::ACursorDecExecute(TObject *Sender)
{
	CursorMode = bRem;
	CursorModeChange();
}
//---------------------------------------------------------------------------
//PopupMenu - Предыдущий тайл
void __fastcall TEditorForm::NPrewTileClick(TObject *Sender)
{
	PTilesButtonClicked(Sender, PrewTile);
}
//---------------------------------------------------------------------------
//Запуск - Debug
void __fastcall TEditorForm::NDebugClick(TObject *Sender)
{
	DebugPanel->Visible =! DebugPanel->Visible;
	NDebug->Checked = DebugPanel->Visible;
}
//---------------------------------------------------------------------------
//Запуск - разместить аномалии
void __fastcall TEditorForm::NTestAnomClick(TObject *Sender)
{
	Map.AnomallyRun();
	TestDraw = true;
	Out->Repaint();
	DrawAnom = false;
	DrawAnomallyBtn->Down = false;
}
//---------------------------------------------------------------------------
//Запуск - информация о локации
void __fastcall TEditorForm::NInfoClick(TObject *Sender)
{
	int Pl = Map.Width * Map.Height;
	int Wei = Map.Width * METERS;
	int Hei = Map.Height * METERS;
	double AnSr = 0, RadSr = 0;
	int nStoy = 0;
	for (int i = 0; i < Map.Height; ++i)
		for (int j = 0; j < Map.Width; ++j)
		{
			AnSr += Map.Cell[j][i].Anomally;
			RadSr += Map.Cell[j][i].Radiation;
			if ((Map.Cell[j][i].Triggger == 1)||(Map.Cell[j][i].Triggger == 2))
				nStoy++;
		}
	AnSr /= (double) Pl;
	RadSr /= (double) Pl;
	AnsiString Info = "Размеры: "+IntToStr(Map.Width)+"X"+IntToStr(Map.Height)+" кв.\n"+
		IntToStr(Wei)+"X"+IntToStr(Hei)+" метров.\n"+
		"Площадь="+IntToStr(Pl)+" кв.\n"+IntToStr(Wei*Hei)+" метров кв.\n"+
		"Средняя аномальность="+FloatToStrF(AnSr, ffGeneral, 5, 5)+"%.\n"+
		"Средняя радиоактивность="+FloatToStrF(RadSr, ffGeneral, 5, 5)+"%.\n"+
		"Точек респавна="+IntToStr(nStoy)+"." ;
	MessageBox(Application->Handle,Info.c_str(),"Информация о локации",MB_OK);
}
//---------------------------------------------------------------------------
//OutKeyDown
void __fastcall TEditorForm::OutKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	//if (Shift.Contains(VK_SHIFT))
	//	ARangeSelectExecute(Sender);
	/*if (Key == 'Н')
		Memo1->Lines->Add('-->Y');
	Memo1->Lines->Add(Key);    */
}
//---------------------------------------------------------------------------
//Отмена
void __fastcall TEditorForm::AUndoExecute(TObject *Sender)
{
	if (Brush == bTile)
	{
		for (int i = 0; i < UndoCurr; ++i)
		{
			SelTile = Undo[i].Cell->Image;
			Undo[i].Cell->Image = Undo[i].Tile;
			Undo[i].Cell->Ident = Map.TileIdent[Undo[i].Tile];
			Undo[i].Tile = SelTile;
		}
		Out->Refresh();
	}
}
//---------------------------------------------------------------------------
//File - Экспорт карты
void __fastcall TEditorForm::NExportClick(TObject *Sender)
{
	if (Saved == 'S')
		SavePicture1->Dialog->FileName = FileSaveAs->Dialog->FileName.SubString(1,FileSaveAs->Dialog->FileName.Pos('.')-1)+".bmp";
	else
		SavePicture1->Dialog->FileName =   FileOpen->Dialog->FileName.SubString(1,FileOpen->Dialog->FileName.Pos('.')-1)+".bmp";
	if (SavePicture1->Dialog->Execute() == ID_OK)
	{
		Graphics::TBitmap *mp = new Graphics::TBitmap;
		mp->Height = Map.Height * ImagesSquareLen;
		mp->Width = Map.Width * ImagesSquareLen;
		/*mp->Canvas->CopyRect(Rect(0,0,mp->Width* TILESIZE,mp->Height* TILESIZE),
			Out->Canvas,		  Rect(0,0,mp->Width* TILESIZE,mp->Height* TILESIZE));     */
		for (int i = 0; i < Map.Width; ++i)
			for (int j = 0; j < Map.Height; ++j)
				Tiles->Draw(mp->Canvas, i*ImagesSquareLen,	j*ImagesSquareLen, Map.Cell[i][j].Image, true);
		mp->SaveToFile(SavePicture1->Dialog->FileName);
		delete mp;
	}
}
//---------------------------------------------------------------------------
//Запись ячейки SetCell
inline void TEditorForm::SetCell(int Col, int Row)
{
	if (Brush == bTile)
	{
		if (UndoCurr < UNDOTILELIMIT)
		{
			Undo[UndoCurr].Cell = &Map.Cell[Col][Row];
			Undo[UndoCurr].Tile = Map.Cell[Col][Row].Image;
			UndoCurr++;
		}
		Map.Cell[Col][Row].Image = SelTile;
		Map.Cell[Col][Row].Ident = Map.TileIdent[SelTile];
	} else
	if (Brush == bAR)
	{
		if (AR->ItemIndex == 0)
		{
			if ( (CursorMode == bSet)||(ARRandom->Checked == false) )
			{
				Map.Cell[Col][Row].Anomally = SelAnom;
				Map.Cell[Col][Row].ColorAnom = ColorAnom;
			} else
			{
				Map.Cell[Col][Row].SetAnomally(GetResultCursorPower(Map.Cell[Col][Row].Anomally, SelAnom));//   Anomally =
				//Map.Cell[Col][Row].ColorAnom = Map.GetAnomallyColor(Map.Cell[Col][Row].Anomally);
			}
		} else
		{
      	if ((CursorMode == bSet)||(ARRandom->Checked == false))
			{
				Map.Cell[Col][Row].Radiation = SelRad;
				Map.Cell[Col][Row].ColorRad = ColorRad;
			} else
			{
				Map.Cell[Col][Row].SetRadiation(GetResultCursorPower(Map.Cell[Col][Row].Radiation, SelRad));
			}
		}
	} else
	if (Brush == bTrig)
	{
		Map.Cell[Col][Row].Triggger = SelTrig;
	}
}
//---------------------------------------------------------------------------
//Посчитать результирующую силу радиац аном
int TEditorForm::GetResultCursorPower(int Curr, int New)
{
	if (CursorMode == bSet)
	{
		return New;
	} else
	if (CursorMode == bAdd)
	{
		Curr += New;
		if (Curr > 100)
			return 100;
		return Curr;
	} else
	if (CursorMode == bRem)
	{
		Curr -= New;
		if (Curr < 0)
			return 0;
		return Curr;
	}
	return New;
}
//---------------------------------------------------------------------------
//Ready
void TEditorForm::Ready(bool State)
{
	NInfo->Enabled = State;
	NTestAnom->Enabled = State;
	Out->Enabled = State;
	FileSave->Enabled = State;
	FileSaveAs->Enabled = State;
	NExport->Enabled = State;	//SavePicture1->Enabled = State;
	NReplace->Enabled = State;
	NCopy->Enabled = State;
}
//---------------------------------------------------------------------------
//аномально <-> радиоактив клик
void __fastcall TEditorForm::ARClick(TObject *Sender)
{
	if (AR->ItemIndex == 0)
		ARPower->Hint = "Вероятность появления аномалии";
	else
		ARPower->Hint = "Сила и вероятность появления радиации";
	ARRandom->Tag = 1;
	ARPowerEChange(Sender);
}
//---------------------------------------------------------------------------
//Правка - Заменить
void __fastcall TEditorForm::NReplaceClick(TObject *Sender)
{
	//wchar_t PrewIdent = Map.TileIdent[PrewTile];
	wchar_t CurrIdent = Map.TileIdent[SelTile];
	String ggg = L"Заменить "+Map.TileName[PrewTile]+L" на "+Map.TileName[SelTile]+L"?";
	if (Application->MessageBoxA(ggg.w_str(),L"Замена",MB_YESNO) == ID_YES)
	{
		for (int c = 0; c < Out->ColCount; ++c)
			for (int r = 0; r < Out->RowCount; ++r)
				if (Map.Cell[c][r].Image == PrewTile)
				{
					Map.Cell[c][r].Image = SelTile;
					Map.Cell[c][r].Ident = CurrIdent;
				}
		Out->Repaint();
	}
}
//---------------------------------------------------------------------------
//Попуп - Копировать
void __fastcall TEditorForm::NCopyClick(TObject *Sender)
{
	static int cleft=0,ctop=0,cright=0,cdown=0;
	if (PopupMenuOut->Tag <= 1)
	{
		ShowMessage("Копирование в три клика правой кнопкой:\n\
1: Левый верхний угол копируемой области;\n\
2: Правый нижний угол копируемой области;\n\
3: Левый верхний угол вставки.");
		NCopy->Caption = "Копирование 2";
		PopupMenuOut->Tag = 2;
		cleft = StatusBar->Panels->Items[STX]->Text.Delete(1,2).ToInt();
		ctop = StatusBar->Panels->Items[STY]->Text.Delete(1,2).ToInt();
	} else if (PopupMenuOut->Tag == 2)
	{
		NCopy->Caption = "Копирование 3";
		PopupMenuOut->Tag = 3;
		cright = StatusBar->Panels->Items[STX]->Text.Delete(1,2).ToInt();
		cdown = StatusBar->Panels->Items[STY]->Text.Delete(1,2).ToInt();
	}
	else
	{
		NCopy->Caption = "Копирование 1";
		PopupMenuOut->Tag = 1;
		int px = StatusBar->Panels->Items[STX]->Text.Delete(1,2).ToInt() - cleft;
		int py = StatusBar->Panels->Items[STY]->Text.Delete(1,2).ToInt() - ctop;
		for (int X = cleft; X <= cright; ++X)
			for (int Y = ctop; Y <= cdown; ++Y)
			{
				Map.Cell[X+px][Y+py].Image = Map.Cell[X][Y].Image;
				Map.Cell[X+px][Y+py].Ident = Map.Cell[X][Y].Ident;
			}
			Out->Repaint();
   }
}
//---------------------------------------------------------------------------
//ToolBar: Рисовать триггеры
void __fastcall TEditorForm::ADrawTriggersExecute(TObject *Sender)
{
	DrawTrig = !DrawTrig;
	DrawTrigBtn->Down = DrawTrig;
	Out->Refresh();
}
//---------------------------------------------------------------------------
//Выбор триггера
void __fastcall TEditorForm::PTriggersButtonClicked(TObject *Sender, int Index)
{
	if (SelTrig != Index)
   {
		SelTrig = Index;
		if (DrawTrig == false)
		{
      	DrawTrigBtn->Down = true;
			DrawTrig = true;
			Out->Repaint();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::openTRIGClick(TObject *Sender)
{
	Map.DebugOpenTrig = openTRIG->Checked;
}
//---------------------------------------------------------------------------
//Изменение аномалии, создание цвета
void __fastcall TEditorForm::ARPowerEChange(TObject *Sender)
{
	if (AR->ItemIndex == 0) //Выбрано Аномальность
	{
		//ARPower->Value = SelAnom;
		ARPowerE->Color = TColor(Map.GetAnomallyColor(ARPower->Position));
		if (ARPower->Position > 70)
			ARPowerE->Font->Color = clWhite;
		else
			ARPowerE->Font->Color = clBlack;
		//if (ARPower == AnomNumb)
		//{
			SelAnom = ARPower->Position;
			ARRandom->Checked = true;
			ARPowerE->Color = ColorAnom; //Map.GetAnomallyColor(SelAnom);
		//}
	}
	else //Радиоактивность
	{
		//ARPower->Value = 	SelRad;
		SelRad = ARPower->Position;
		ARPowerE->Color = ColorRad; //TColor(Map.GetRadiationColor(ARPower->Value));
	}

	/*if (ARRandom->Tag == 0)
	{
		if (AR->ItemIndex == 0)
		{
			if (DrawAnom == false)
         {
         	DrawAnomallyBtn->Down = true;
				DrawAnom = true;
				Out->Refresh();
			}
		}
		else
		{
			if (DrawRad == false)
         {
         	DrawRadiationBtn->Down = true;
				DrawRad = true;
				Out->Refresh();
			}
      }
		ARRandom->Checked = true;
	}
	else
		{	ARRandom->Tag = 0; }  */
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::NCurrTileClick(TObject *Sender)
{
	PTilesButtonClicked(Sender, SelectedTile);
}
//---------------------------------------------------------------------------

void __fastcall TEditorForm::AGrid40Execute(TObject *Sender)
{
	DrawGrid40 = !DrawGrid40;
	Out->Canvas->Pen->Color = clFuchsia;
	int g = DrawGrid ? 2 : 0;
	int W = Out->VisibleColCount*Out->DefaultColWidth+g*Out->VisibleColCount;
	int H = Out->VisibleRowCount*Out->DefaultRowHeight+g*Out->VisibleRowCount;
	int st1 = DrawGrid ? 21 : 0;
	int st2 = DrawGrid ? 10 : 10;
	for (int i = Out->LeftCol % 2 == 0 ? st1 : st2; i < W; i+=20+g)
	{
		Out->Canvas->MoveTo(i,0);
		Out->Canvas->LineTo(i,H);
	}
	for (int j = Out->TopRow % 2 == 0 ? st1 : st2; j < H; j+=20+g)
	{
		Out->Canvas->MoveTo(0,j);
		Out->Canvas->LineTo(W,j);
	}
}
//---------------------------------------------------------------------------


