//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include <StdActns.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <ButtonGroup.hpp>
#include "Map.h"
#include "FormCreate.h"
#include <Buttons.hpp>
#include <ExtActns.hpp>
#include <Graphics.hpp>
#include <pngimage.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>


int const METERS = 40;
const int TILEVARIA = 4;
//MAPS Maps;
TMap Map;
int const STX = 1;
int const STY = 2;
int const STTILE = 5;
int const STMAX = 0;
int const SR = 3;
int const SA = 4;
int const SDRAW = 6;
int const PANELSCHOP = 2 + 30*3;
int const UNDOTILELIMIT = 128;

//---------------------------------------------------------------------------
class TEditorForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *NFile;
	TActionList *ActionList1;
	TFileOpen *FileOpen;
	TFileSaveAs *FileSaveAs;
	TFileExit *FileExit;
	TMenuItem *NOpen1;
	TMenuItem *NSave;
	TMenuItem *NNew;
	TMenuItem *NExit;
	TStatusBar *StatusBar;
	TToolBar *ToolBar1;
	TImageList *ButtonsImages;
	TToolButton *NewBtn;
	TToolButton *OpenBtn;
	TToolButton *SaveBtn;
	TToolButton *ToolButton4;
	TCategoryPanelGroup *CategoryPanelGroup1;
	TCategoryPanel *PanelTile;
	TButtonGroup *PTiles;
	TSplitter *Splitter1;
	TImageList *Tiles;
	TAction *FileNew;
	TCategoryPanel *PanelAR;
	TToolButton *CellBtn;
	TToolButton *RangeBtn;
	TAction *ARangeSelect;
	TToolButton *ToolButton5;
	TToolButton *DrawGridBtn;
	TPopupMenu *PopupMenuTile;
	TMenuItem *NTilesNames;
	TAction *ADrawGrid;
	TAction *FileSave;
	TMenuItem *NSaveAs;
	TRadioButton *AR0;
	TRadioButton *AR100;
	TRadioButton *ARRandom;
	TToolButton *DrawRadiationBtn;
	TToolButton *DrawAnomallyBtn;
	TMenuItem *NEdit;
	TMenuItem *NUndo;
	TAction *ADrawAnomally;
	TAction *ADrawRadiation;
	TCategoryPanel *PanelTriggers;
	TAction *ACursorSet;
	TPanel *Panel1;
	TToolBar *ToolBar2;
	TToolButton *ARSetBtn;
	TToolButton *ARAddBtn;
	TToolButton *ARDecBtn;
	TAction *ACursorAdd;
	TAction *ACursorDec;
	TPopupMenu *PopupMenuOut;
	TMenuItem *N6;
	TMenuItem *NPrewTile;
	TMenuItem *NDebug;
	TMenuItem *NRun;
	TMenuItem *NTestAnom;
	TMenuItem *NInfo;
	TPanel *DebugPanel;
	TMemo *Log;
	TLabel *DebugLabel;
	TMenuItem *NHelp;
	TMenuItem *NAbout;
	TAction *AUndo;
	TMenuItem *NExport;
	TMenuItem *N2;
	TMenuItem *N3;
	TImage *NullTile;
	TRadioGroup *AR;
	TButtonGroup *PTriggers;
	TMenuItem *NReplace;
	TMenuItem *NCopy;
	TImageList *TriggersIm;
	TToolButton *DrawTrigBtn;
	TAction *ADrawTriggers;
	TCheckBox *openTRIG;
	TEdit *ARPowerE;
	TUpDown *ARPower;
	TMenuItem *N1;
	TTrackBar *Scaler;
	TAction *LoadVars;
	TToolButton *Grid40Btn;
	TAction *ADrawGrid40;
	TMenuItem *NReplaceSel;
	TToolButton *RulerBtn;
	TMenuItem *NCurrTile;
	TToolButton *MovedBtn;
	TAction *MoveTool;
	TCategoryPanel *PanelSprites;
	TScrollBox *ScrollBox1;
	TFlowPanel *PSprites;
	TButton *loadsprites;
	TImageList *TileBtns;
	TBitBtn *BitBtn1;
	TCheckBox *CBdoublebuf;
	TImage *DeleteSprite;
	TSavePictureDialog *SavePictureDialog1;
	TCheckBox *CBTilesLog;
	TBitBtn *BitBtn2;
	TButton *Button1;
	TPanel *OutPanel;
	TScrollBar *ScrollWi;
	TScrollBar *ScrollHe;
	TImage *Out;
	TButton *spris;
	void __fastcall PTilesButtonClicked(TObject *Sender, int Index);
	void __fastcall NTilesNamesClick(TObject *Sender);
	void __fastcall OutMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall ADrawGridExecute(TObject *Sender);
	void __fastcall OutMouseLeave(TObject *Sender);
	void __fastcall PanelTileExpand(TObject *Sender);
	void __fastcall PanelARExpand(TObject *Sender);
	void __fastcall ADrawAnomallyExecute(TObject *Sender);
	void __fastcall ADrawRadiationExecute(TObject *Sender);
	void __fastcall PanelTriggersExpand(TObject *Sender);
	void __fastcall AR0Click(TObject *Sender);
	void __fastcall AR100Click(TObject *Sender);
	void __fastcall ARRandomClick(TObject *Sender);
	void __fastcall ACursorSetExecute(TObject *Sender);
	void __fastcall ACursorAddExecute(TObject *Sender);
	void __fastcall ACursorDecExecute(TObject *Sender);
	void __fastcall NPrewTileClick(TObject *Sender);
	void __fastcall NDebugClick(TObject *Sender);
	void __fastcall NTestAnomClick(TObject *Sender);
	void __fastcall NInfoClick(TObject *Sender);
	void __fastcall AUndoExecute(TObject *Sender);
	void __fastcall NExportClick(TObject *Sender);
	void __fastcall ARClick(TObject *Sender);
	void __fastcall NReplaceClick(TObject *Sender);
	void __fastcall NCopyClick(TObject *Sender);
	void __fastcall ADrawTriggersExecute(TObject *Sender);
	void __fastcall PTriggersButtonClicked(TObject *Sender, int Index);
	void __fastcall openTRIGClick(TObject *Sender);
	void __fastcall FileNewExecute(TObject *Sender);
	void __fastcall FileSaveExecute(TObject *Sender);
	void __fastcall FileOpenAccept(TObject *Sender);
	void __fastcall FileSaveAsAccept(TObject *Sender);
	void __fastcall ARangeSelectExecute(TObject *Sender);
	void __fastcall ARPowerEChange(TObject *Sender);
	void __fastcall ScalerChange(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ADrawGrid40Execute(TObject *Sender);
	void __fastcall NReplaceSelClick(TObject *Sender);
	void __fastcall RangeBtnClick(TObject *Sender);
	void __fastcall NullTileClick(TObject *Sender);
	void __fastcall NCurrTileClick(TObject *Sender);
	void __fastcall MoveToolExecute(TObject *Sender);
	void __fastcall loadspritesClick(TObject *Sender);
	void __fastcall PanelSpritesExpand(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall NAboutClick(TObject *Sender);
	void __fastcall CBdoublebufClick(TObject *Sender);
	void __fastcall StatusBarDblClick(TObject *Sender);
	void __fastcall ScrollBox1Resize(TObject *Sender);
	void __fastcall DeleteSpriteClick(TObject *Sender);
	void __fastcall OutKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall FormKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall OutMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall OutMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall OutMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall OutPaint(TObject *Sender);
	void __fastcall OutPanelResize(TObject *Sender);
	void __fastcall ScrollWiChange(TObject *Sender);
	void __fastcall ScrollHeChange(TObject *Sender);
	void __fastcall OutMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall sprisClick(TObject *Sender);

private:	// User declarations
	int FSelRad;
	int FSelAnom;
public:		// User declarations
	__fastcall TEditorForm(TComponent* Owner);
	inline void SetCell(int Col, int Row);
	int GetResultCursorPower(int Curr, int New);
	void RefreshLocationName(UnicodeString FileName);
	void Ready(bool State);
	int SelTile;
	int PrewTile;
	int SelectedTile;
	bool Painting; //Нажата мышь
	//bool RangeSelect;
	bool DrawGrid;
	char Saved;
	bool DrawAnom;
	bool DrawRad;
	bool DrawTrig;
	int SelTrig;
	__property int SelRad = {read=FSelRad, write=SetSelRad};
	__property int SelAnom = {read=FSelAnom, write=SetSelAnom};
	TColor ColorAnom;
	TColor ColorRad;
   void SetSelAnom(int ASelAnom)
	{
		ColorAnom = Map.GetAnomallyColor(ASelAnom);
		FSelAnom = ASelAnom;
	}
	void SetSelRad(int ASelRad)
	{
		ColorRad = Map.GetRadiationColor(ASelRad);
		FSelRad = ASelRad;
	}

	TGridDrawState RangeState;
	bool TestDraw;
	enum EBrush {bTile, bAR, bTrig };
	EBrush Brush;
	enum ECursorMode {bSet=0, bAdd=1, bRem=2};
	ECursorMode CursorMode;
	void CursorModeChange()
	{
		ARSetBtn->Down = CursorMode==bSet;
		ARAddBtn->Down = CursorMode==bAdd;
		ARDecBtn->Down = CursorMode==bRem;
   }

	struct UNDO
	{
		TMap::TCell *Cell;
		int Tile;
	} Undo[UNDOTILELIMIT];
	int UndoCurr;
	TRect Copy;
	int FDraws;
	__property int Draws = {read=FDraws, write=SetDraws};
	void SetDraws(int ADraws)
	{
		FDraws = ADraws;
		StatusBar->Panels->Items[SDRAW]->Text = FDraws;
	}
	bool DrawTile;
	//TImageList *TilesVar[4];
	//int VAR;
	Graphics::TBitmap *CurrTile;
	void CreateNoneTile();
	//bool RulerActive;
	tagPOINT Ruler;
	double PixelOnMeter;
	int MoveX, MoveY; //move mode
	//Спрайты
	TImage **Sprites;
	void __fastcall SpritesClick(TObject *Sender);
	//TNotifyEvent SpriteClickN;
	int *Buttons;
	//void RefreshCell(int x, int y) 	{  	}
	//Panel2->Left++;
	Graphics::TBitmap *Sprite;// = new TImage(Out);
	int SelSprite;
	Graphics::TBitmap *Store;
	int RX,RY;
	//long draws;
	void SetSprite(int mapsprite)
	{
		if (mapsprite >= 0)
			SelSprite = mapsprite;// curr;
		int sx = Map.Sprites[SelSprite]->Width - Scaler->Position * Map.Sprites[SelSprite]->Width/16.;
		int sy = Map.Sprites[SelSprite]->Height - Scaler->Position * Map.Sprites[SelSprite]->Height/16.;
		Sprite->SetSize(Map.Sprites[SelSprite]->Width
			,Map.Sprites[SelSprite]->Height);
		if (mapsprite >= 0)
			if (RX == 0 && RY == 0)
				Out->Canvas->Draw(0,0,Store); //Для перевыбора спрайта
		Store->SetSize(Sprite->Width, Sprite->Height);
		//Сoхранить
		Store->Canvas->CopyRect(Store->Canvas->ClipRect, Out->Canvas, Store->Canvas->ClipRect);
		//Предпросмотр
		Sprite->Canvas->FillRect(Sprite->Canvas->ClipRect);
		Sprite->Canvas->StretchDraw(Sprite->Canvas->ClipRect, Map.Sprites[SelSprite]->Bitmap);//(Sprite->)
		//Sprite = Map.Sprites[SelSprite]->Bitmap;
		if (mapsprite >= 0)
			Out->Canvas->Draw(0,0,Sprite);  //*/
		RX = RY = 0;
		Log->Lines->Add("set"+IntToStr(Sprite->Width)+","+IntToStr(Sprite->Height));
		//Log->Lines->Add("def"+IntToStr(Out->DefaultColWidth));

	}
	int scallercaeb;
	int nSprites;
	bool MapMoving;
	bool NeedPopup;
	int CellX, CellY; //Выбранная ячейка из Активате
	Graphics::TBitmap *In;
	int VisibleRowCount; //округл вверх
	int VisibleColCount;
	int CellSize;
	void OutRepaint();
	bool GetCell(); //CellX, CellY; SelX, SelXY;
	int SelX, SelY;
	bool GetCellOf(int X, int Y);
};
//---------------------------------------------------------------------------
extern PACKAGE TEditorForm *EditorForm;
//---------------------------------------------------------------------------
#endif
