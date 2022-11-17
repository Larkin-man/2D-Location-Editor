//---------------------------------------------------------------------------

#include <vcl.h>
#include <memory>
#pragma hdrstop

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TEditorForm *EditorForm;
//---------------------------------------------------------------------------
__fastcall TEditorForm::TEditorForm(TComponent* Owner) : TForm(Owner)
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
//НОВЫЙ
//Открыть
//Сохранить
//Сохранить Как
//ToolBar: Переключение выбора (одиночный-множественный)
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
	if (Map.Cell == NULL)
		return;
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
void TEditorForm::RefreshLocationName(UnicodeString FileName)
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
	//DrawAnomallyBtn->Down = DrawAnom;
	Out->Repaint();
}
//---------------------------------------------------------------------------
//ToolBar: Рисовать Радиацию
void __fastcall TEditorForm::ADrawRadiationExecute(TObject *Sender)
{
	DrawRad = !DrawRad;
	//DrawRadiationBtn->Down = DrawRad;
	Out->Refresh();
}
//---------------------------------------------------------------------------
//Изменение аномалии, создание цвета
void __fastcall TEditorForm::ARPowerChange(TObject *Sender)
{
	//TCSpinEdit *sender = ((TCSpinEdit *)Sender);
	/*try
	{  	}
	catch (EConvertError &gre)
	{  		return;   	}    */
	if (AR->ItemIndex == 0)
	{
		//ARPower->Value = SelAnom;
		ARPower->Color = TColor(Map.GetAnomallyColor(ARPower->Value));
		if (ARPower->Value > 70)
			ARPower->Font->Color = clWhite;
		else
			ARPower->Font->Color = clBlack;
		//if (ARPower == AnomNumb)
		//{
			SelAnom = ARPower->Value;
			ARRandom->Checked = true;
			ARPower->Color = ColorAnom; //Map.GetAnomallyColor(SelAnom);
		//}
	}
	else
	{
		//ARPower->Value = 	SelRad;
		SelRad = ARPower->Value;
		ARPower->Color = ColorRad; //TColor(Map.GetRadiationColor(ARPower->Value));
	}
	if (ARRandom->Tag == 0)
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
	} else
	{	ARRandom->Tag = 0; }
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
		SelAnom = ARPower->Value;
		ARPower->Color = ColorAnom;// Map.GetAnomallyColor(SelAnom);
	}
	else
	{
		SelRad = ARPower->Value;
		ARPower->Color = ColorRad; //Map.GetRadiationColor(SelRad);
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
	double AnSr = 0;
	for (int i = 0; i < Map.Height; ++i)
		for (int j = 0; j < Map.Width; ++j)
			AnSr += Map.Cell[j][i].Anomally;
	AnSr /= (double) Pl;
	UnicodeString Info;
	Info = "Площадь="+IntToStr(Pl)+" кв.\n"+
		"Размеры: "+IntToStr(Wei)+"X"+IntToStr(Hei)+" метров.\n"+
		"Средняя аномальность="+FloatToStrF(AnSr, ffGeneral, 5, 5)+"%."
		;
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
		mp->Height = Map.Height * TILESIZE;
		mp->Width = Map.Width * TILESIZE;
		/*mp->Canvas->CopyRect(Rect(0,0,mp->Width* TILESIZE,mp->Height* TILESIZE),
			Out->Canvas,		  Rect(0,0,mp->Width* TILESIZE,mp->Height* TILESIZE));     */
		for (int i = 0; i < Map.Width; ++i)
			for (int j = 0; j < Map.Height; ++j)
				Tiles->Draw(mp->Canvas, i*TILESIZE,	j*TILESIZE, Map.Cell[i][j].Image, true);
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
	ARPowerChange(Sender);
}
//---------------------------------------------------------------------------
//Правка - Заменить
void __fastcall TEditorForm::NReplaceClick(TObject *Sender)
{
	//wchar_t PrewIdent = Map.TileIdent[PrewTile];
	wchar_t CurrIdent = Map.TileIdent[SelTile];
	UnicodeString ggg = L"Заменить "+Map.TileName[PrewTile]+L" на "+Map.TileName[SelTile]+L"?";
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
	if (PopupMenu->Tag == 0)
   {
		ShowMessage("Копирование в три клика правой кнопкой:\n\
			1: Левый верхний угол копируемой области;\n\
			2: Правый нижний угол копируемой области;\n\
			3: Левый верхний угол вставки.");
	}
}
//---------------------------------------------------------------------------
//ToolBar: Рисовать триггеры
void __fastcall TEditorForm::ADrawTriggersExecute(TObject *Sender)
{
	DrawTrig = !DrawTrig;
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



