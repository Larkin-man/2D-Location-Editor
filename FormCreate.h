//---------------------------------------------------------------------------

#ifndef FormCreateH
#define FormCreateH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm_Create : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit_W;
        TButton *Button_Create;
        TButton *Button_Cancel;
        TEdit *Edit_H;
        TLabel *Label1;
        TLabel *Label2;
        void __fastcall Button_CancelClick(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall Button_CreateClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        bool mOK;
        int W, H;
        __fastcall TForm_Create(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Create *Form_Create;
//---------------------------------------------------------------------------
#endif
