//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <MPlayer.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TMilionerzy : public TForm
{
__published:	// IDE-managed Components
        TImage *Tlo;
        TButton *Start;
        TMediaPlayer *MediaPlayer1;
        TMediaPlayer *MediaPlayer2;
        TMediaPlayer *MediaPlayer3;
        TMediaPlayer *MediaPlayer4;
        TImage *OdpA;
        TImage *OdpB;
        TImage *OdpC;
        TImage *OdpD;
        TLabel *A;
        TImage *Pytanie;
        TLabel *D;
        TLabel *B;
        TLabel *C;
        TLabel *Pytanie1;
        TButton *NowaGra;
        TMediaPlayer *MediaPlayer5;
        TButton *MuteButton;
        TMediaPlayer *MediaPlayer6;
        TProgressBar *ladowanie;
        TTimer *Timer1;
        TImage *Image1;
        TImage *Znacznik;
        TLabel *koniec;
        TLabel *Autor;
        TImage *Kolo3Odp;
        TImage *kolo1;
        TImage *kolo2;
        TImage *kolo3;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall StartClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall AClick(TObject *Sender);
        void __fastcall DClick(TObject *Sender);
        void __fastcall CClick(TObject *Sender);
        void __fastcall BClick(TObject *Sender);
        void __fastcall MuteButtonClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall koniecClick(TObject *Sender);
        void __fastcall AutorClick(TObject *Sender);
        void __fastcall kolo2Click(TObject *Sender);
        void __fastcall kolo3Click(TObject *Sender);
private:	// User declarations
        TStringList *Pytania;
public:		// User declarations
        __fastcall TMilionerzy(TComponent* Owner);
        void sprawdz();
        void zmien_pytania();
        void przegrales();
};
//---------------------------------------------------------------------------
extern PACKAGE TMilionerzy *Milionerzy;
//---------------------------------------------------------------------------
#endif
