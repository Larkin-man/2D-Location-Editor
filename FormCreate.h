//---------------------------------------------------------------------------

#ifndef FormCreateH
#define FormCreateH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TCreateForm : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCreateForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCreateForm *CreateForm;
//---------------------------------------------------------------------------
#endif
