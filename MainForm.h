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
#include "cspin.h"
#include <ExtActns.hpp>
#include <Graphics.hpp>

const int TILESIZE = 10;
//MAPS Maps;
TMap Map;
int const STX = 1;
int const STY = 2;
int const STTILE = 5;
int const STMAX = 0;
int const SR = 3;
int const SA = 4;
int const PANELSCHOP = 62;
int const UNDOTILELIMIT = 128;

//---------------------------------------------------------------------------
class TEditorForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *NFile;
	TDrawGrid *Out;
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
	TMemo *Memo1;
	TLabel *DebugLabel;
	TMenuItem *NHelp;
	TMenuItem *NAbout;
	TAction *AUndo;
	TMenuItem *NExport;
	TMenuItem *N2;
	TMenuItem *N3;
	TSavePicture *SavePicture1;
	TImage *NullTile;
	TRadioGroup *AR;
	TButtonGroup *PTriggers;
	TMenuItem *NReplace;
	TMenuItem *NCopy;
	TImageList *TriggersIm;
	TToolButton *DrawTrigBtn;
	TAction *ADrawTriggers;
	TCheckBox *openTRIG;
	void __fastcall PTilesButtonClicked(TObject *Sender, int Index);
	void __fastcall OutDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall OutSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall OutClick(TObject *Sender);
	void __fastcall OutMouseActivate(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y, int HitTest, TMouseActivate &MouseActivate);
	void __fastcall NTilesNamesClick(TObject *Sender);
	void __fastcall OutMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall ADrawGridExecute(TObject *Sender);
	void __fastcall OutMouseLeave(TObject *Sender);
	void __fastcall OutKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall PanelTileExpand(TObject *Sender);
	void __fastcall PanelARExpand(TObject *Sender);
	void __fastcall ADrawAnomallyExecute(TObject *Sender);
	void __fastcall ADrawRadiationExecute(TObject *Sender);
	void __fastcall PanelTriggersExpand(TObject *Sender);
	void __fastcall ARPowerChange(TObject *Sender);
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
	void __fastcall OutKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall AUndoExecute(TObject *Sender);
	void __fastcall NExportClick(TObject *Sender);
	void __fastcall ARClick(TObject *Sender);
	void __fastcall NReplaceClick(TObject *Sender);
	void __fastcall NCopyClick(TObject *Sender);
	void __fastcall ADrawTriggersExecute(TObject *Sender);
	void __fastcall PTriggersButtonClicked(TObject *Sender, int Index);
	void __fastcall openTRIGClick(TObject *Sender);

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
	bool Painting;
	bool RangeSelect;
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
};
//---------------------------------------------------------------------------
extern PACKAGE TEditorForm *EditorForm;
//---------------------------------------------------------------------------
#endif
