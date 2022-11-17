//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include "TMap.cpp"
#include <Dialogs.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TForm_Main : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N_Open;
        TMenuItem *N_Save;
        TMenuItem *N_SaveAs;
        TMenuItem *N_New;
        TScrollBar *ScrollBar_G;
        TScrollBar *ScrollBar_V;
        TToolBar *ToolBar1;
        TBevel *Bevel1;
        TImage *Image1;
        TStatusBar *StatusBar1;
        TSpeedButton *SpeedButton_C;
        TSpeedButton *SpeedButton_P;
        TToolButton *ToolButton1;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
   TMenuItem *N2;
   TMenuItem *N3;
   TColorDialog *ColorDialog1;
   TImageList *ImageList1;
   TMenuItem *NExport;
   TMenuItem *NImport;
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall N_NewClick(TObject *Sender);
        void __fastcall EditScroll(int width, int height);
        void __fastcall ScrollBar_VChange(TObject *Sender);
        void __fastcall SpeedButton_CClick(TObject *Sender);
        void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall BufPaint();
        void __fastcall N_SaveClick(TObject *Sender);
        void __fastcall N_OpenClick(TObject *Sender);
        void __fastcall N_SaveAsClick(TObject *Sender);
   void __fastcall N3Click(TObject *Sender);
   void __fastcall NExportClick(TObject *Sender);
   void __fastcall NImportClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        int bufX, bufY, stX, stY, stG, stV;
        bool mkR, mkL;
        __fastcall TForm_Main(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Main *Form_Main;
//---------------------------------------------------------------------------
#endif
