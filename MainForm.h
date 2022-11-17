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
#include <Buttons.hpp>
#include <ExtActns.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------

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
class TEditorForm : public TForm
{
__published:	// IDE-managed Components
	TImageList *Tiles;
	TImageList *TriggersIm;
	TImageList *ButtonsImages;
	TActionList *ActionList1;
	TAction *FileNew;
	TFileOpen *FileOpen;
	TAction *FileSave;
	TFileSaveAs *FileSaveAs;
	TFileExit *FileExit;
	TAction *ARangeSelect;
	TAction *ADrawGrid;
	TAction *ADrawAnomally;
	TAction *ADrawRadiation;
	TAction *ACursorSet;
	TAction *ACursorAdd;
	TAction *ACursorDec;
	TAction *AUndo;
	TSavePicture *SavePicture1;
	TAction *ADrawTriggers;
	TPopupMenu *PopupMenuOut;
	TMenuItem *NPrewTile;
	TMenuItem *N6;
	TMenuItem *NCopy;
	TMainMenu *MainMenu1;
	TMenuItem *NFile;
	TMenuItem *NNew;
	TMenuItem *NOpen1;
	TMenuItem *NSave;
	TMenuItem *NSaveAs;
	TMenuItem *N2;
	TMenuItem *NExport;
	TMenuItem *N3;
	TMenuItem *NExit;
	TMenuItem *NEdit;
	TMenuItem *NUndo;
	TMenuItem *NDebug;
	TMenuItem *NReplace;
	TMenuItem *NRun;
	TMenuItem *NInfo;
	TMenuItem *NTestAnom;
	TMenuItem *NHelp;
	TMenuItem *NAbout;
	TToolBar *ToolBar1;
	TToolButton *NewBtn;
	TToolButton *OpenBtn;
	TToolButton *SaveBtn;
	TToolButton *ToolButton4;
	TToolButton *CellBtn;
	TToolButton *RangeBtn;
	TToolButton *ToolButton5;
	TToolButton *DrawGridBtn;
	TToolButton *DrawAnomallyBtn;
	TToolButton *DrawRadiationBtn;
	TToolButton *DrawTrigBtn;
	TStatusBar *StatusBar;
	TCategoryPanelGroup *CategoryPanelGroup1;
	TCategoryPanel *PanelTile;
	TButtonGroup *PTiles;
	TCategoryPanel *PanelAR;
	TRadioButton *AR0;
	TRadioButton *AR100;
	TRadioButton *ARRandom;
	TPanel *Panel1;
	TToolBar *ToolBar2;
	TToolButton *ARSetBtn;
	TToolButton *ARAddBtn;
	TToolButton *ARDecBtn;
	TRadioGroup *AR;
	TCategoryPanel *PanelTriggers;
	TButtonGroup *PTriggers;
	TSplitter *Splitter1;
	TDrawGrid *Out;
	TPanel *DebugPanel;
	TLabel *DebugLabel;
	TImage *NullTile;
	TMemo *Memo1;
	TCheckBox *openTRIG;
	void __fastcall FileNewExecute(TObject *Sender);
	void __fastcall FileSaveExecute(TObject *Sender);
	void __fastcall FileOpenAccept(TObject *Sender);
	void __fastcall FileSaveAsAccept(TObject *Sender);
	void __fastcall ARangeSelectExecute(TObject *Sender);
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
