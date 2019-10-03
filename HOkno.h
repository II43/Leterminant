//---------------------------------------------------------------------------

#ifndef HOknoH
#define HOknoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
#include <ComCtrls.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *StringGrid1;
        TEdit *Edit1;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit2;
        TImage *Image1;
        TProgressBar *ProgressBar1;
        TLabel *Label3;
        TButton *Button2;
        TButton *Button3;
        TButton *Button1;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        String strEdit1;
        Matice* __fastcall NactiMATzTabulky();
        void __fastcall ZapisMATdoTabulky(Matice *mat);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
