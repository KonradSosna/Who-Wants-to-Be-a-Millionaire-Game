//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <mmsystem.h>
#include <stdlib>
#include "Unit1.h"


using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMilionerzy *Milionerzy;

// Zmienne
int liczba_pytan=0; //ID pytania
int *w=&liczba_pytan;

String Poprawna;

float s=300; // Czas

int* wylosowane = new int[5]; //rezerwacja tablicy
randomize();



// Losowanie pytania bez powtorzen
int losuj()
{
        int ile_juz_wylosowano = 0; //zmienna pomocnicza

        for (int i = 1; i <= 6; i++)
        {
        bool losowanie_ok;
        int A[6] = { 0,6,12,18,24,30 };
        do{
	        int B = rand() % 6 + 0;
	        int liczba = A[B];
	        losowanie_ok = true;

		for (int j = 1; j <= ile_juz_wylosowano; j++)
		{
			//czy liczba nie zostala juz wczesniej wylosowana?
			if (liczba == wylosowane[j]) losowanie_ok = false;
		}

		if (losowanie_ok == true)
		{
			//mamy unikatowa liczbe, zapiszmy ja do tablicy
			ile_juz_wylosowano++;
			wylosowane[ile_juz_wylosowano] = liczba;
		}
	} while (losowanie_ok != true);
}

        return *wylosowane;
}



// Gdy uzytkownik przegra
void TMilionerzy::przegrales()
        {
        Tlo->Picture->LoadFromFile("img/koniec.bmp");
        Start->Visible=false;
        NowaGra->Visible=true;
        OdpA->Visible=false;
        A->Visible=false;
        OdpB->Visible=false;
        B->Visible=false;
        OdpC->Visible=false;
        C->Visible=false;
        OdpD->Visible=false;
        D->Visible=false;
        Pytanie->Visible=true;
        Pytanie1->Visible=true;
        Timer1->Enabled=false;
        ladowanie->Visible=false;
        kolo1->Enabled=false;
        kolo2->Enabled=false;
        kolo3->Enabled=false;

        switch(*w)
{
        case 0: Pytanie1->Caption="Brak nagrody";                       break;
        case 1: Pytanie1->Caption="Wygrywasz 100 z³";                   break;
        case 2: Pytanie1->Caption="Wygrywasz 200 z³";                   break;
        case 3: Pytanie1->Caption="Wygrywasz 300 z³";                   break;
        case 4: Pytanie1->Caption="Wygrywasz 500 z³";                   break;
        case 5: Pytanie1->Caption="Wygrywasz 1000 z³";                  break;
        case 6: Pytanie1->Caption="Wygrywasz 2000 z³";                  break;
        case 7: Pytanie1->Caption="Wygrywasz 4000 z³";                  break;
        case 8: Pytanie1->Caption="Wygrywasz 8000 z³";                  break;
        case 9: Pytanie1->Caption="Wygrywasz 16000 z³";                 break;
        case 10: Pytanie1->Caption="Wygrywasz 32000 z³";                break;
        case 11: Pytanie1->Caption="Wygrywasz 64000 z³";                break;
        case 12: Pytanie1->Caption="Wygrywasz 125000 z³";               break;
        case 13: Pytanie1->Caption="Wygrywasz 250000 z³";               break;
        case 14: Pytanie1->Caption="Wygrywasz 500000 z³";               break;


}
        }

// Ladowanie nowych pytan
void TMilionerzy::zmien_pytania()
{
        int  i;
        if(*w==0) i=wylosowane[1];
        else if(*w==1) i=wylosowane[2];
        else if(*w==2) i=wylosowane[3];
        else if(*w==3) i=wylosowane[4];
        else if(*w==4) i=wylosowane[5];
        else if(*w==5) i=wylosowane[6];


        Pytanie1->Caption = Pytania->Strings[i];
        A->Caption = Pytania->Strings[i+1];
        B->Caption = Pytania->Strings[i+2];
        C->Caption = Pytania->Strings[i+3];
        D->Caption = Pytania->Strings[i+4];
        Poprawna = Pytania->Strings[i+5];

        Kolo3Odp->Visible=false;
}

// Sprawdz czy wygrales
void TMilionerzy::sprawdz()
{
 if(liczba_pytan==6)
        {
        Tlo->Picture->LoadFromFile("img/koniec.bmp");
        Start->Visible=false;
        NowaGra->Visible=true;
        OdpA->Visible=false;
        A->Visible=false;
        OdpB->Visible=false;
        B->Visible=false;
        OdpC->Visible=false;
        C->Visible=false;
        OdpD->Visible=false;
        D->Visible=false;
        Pytanie->Visible=true;
        Pytanie1->Visible=true;
        Pytanie1->Caption="Wygrales";
        }
 }

//---------------------------------------------------------------------------
__fastcall TMilionerzy::TMilionerzy(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMilionerzy::FormCreate(TObject *Sender)
{
        Tlo->Picture->LoadFromFile("img/tlo.bmp");
        MediaPlayer1->FileName="snd/main-theme.wav";
        MediaPlayer1->Open();
        MediaPlayer2->FileName="snd/lets-play.wav";
        MediaPlayer2->Open();
        MediaPlayer3->FileName="snd/1001000-music.wav";
        MediaPlayer3->Open();
        MediaPlayer4->FileName="snd/correct answer.mp3";
        MediaPlayer4->Open();
        MediaPlayer5->FileName="snd/final answer.mp3";
        MediaPlayer5->Open();
        MediaPlayer6->FileName="snd/wrong answer.mp3";
        MediaPlayer6->Open();


        Start->Visible=true;
        NowaGra->Visible=false;
        OdpA->Visible=false;
        A->Visible=false;
        OdpB->Visible=false;
        B->Visible=false;
        OdpC->Visible=false;
        C->Visible=false;
        OdpD->Visible=false;
        D->Visible=false;
        Pytanie->Visible=false;
        Pytanie1->Visible=false;
        Image1->Visible=false;

        if(MuteButton->Caption=="Mute")
        MediaPlayer1->Play();

        *w=0;
        s=300;

        Pytania = new TStringList;
        Pytania->LoadFromFile("milionerzy.txt");

        Timer1->Enabled=false;
        ladowanie->Visible=false;
        Znacznik->Visible=false;
        Autor->Visible=false;

}
//---------------------------------------------------------------------------
void __fastcall TMilionerzy::StartClick(TObject *Sender)
{
         //Ladowanie
        losuj();
        zmien_pytania();

        MediaPlayer1->Stop();
        if(MuteButton->Caption=="Mute") MediaPlayer2->Play();
        Tlo->Picture->LoadFromFile("img/main.bmp");
        Start->Visible=false;
        NowaGra->Visible=true;
        OdpA->Visible=true;
        A->Visible=true;
        OdpB->Visible=true;
        B->Visible=true;
        OdpC->Visible=true;
        C->Visible=true;
        OdpD->Visible=true;
        D->Visible=true;
        Pytanie->Visible=true;
        Pytanie1->Visible=true;
        Image1->Visible=true;
        if(MuteButton->Caption=="Mute") MediaPlayer3->Play();
        OdpA->Picture->LoadFromFile("img/pod odpowiedz.bmp");
        OdpB->Picture->LoadFromFile("img/pod odpowiedz.bmp");
        OdpC->Picture->LoadFromFile("img/pod odpowiedz.bmp");
        OdpD->Picture->LoadFromFile("img/pod odpowiedz.bmp");
        Pytanie->Picture->LoadFromFile("img/pod pytanie.bmp");
        Image1->Picture->LoadFromFile("img/ktore pytanie.bmp");
        Znacznik->Picture->LoadFromFile("img/znacznik.bmp");



        //Zalaczenie paska ladowania
        Timer1->Enabled=true;
        ladowanie->Visible=true;

        // Przycisk koniec
        koniec->Visible=true;
        koniec->Enabled=true;

        // Autor
        Autor->Visible=true;

        // Znacznik
        Znacznik->Visible=true;

        // Kola ratunkowe
        kolo1->Enabled=true;
        kolo2->Enabled=true;
        kolo3->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMilionerzy::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        if (Application->MessageBox("Czy zamkn¹æ program?",
        "Zakoncz", MB_YESNO | MB_ICONQUESTION) == IDNO)
        {
        Action=caNone;
        }
        else
        {
        MediaPlayer1->Close();
        MediaPlayer2->Close();
        MediaPlayer3->Close();
        MediaPlayer4->Close();
        MediaPlayer5->Close();
        MediaPlayer6->Close();
        delete Pytania;
        delete [] wylosowane;
        }
}
//---------------------------------------------------------------------------

void __fastcall TMilionerzy::AClick(TObject *Sender)
{
        if(A->Caption == Poprawna)
        {
        OdpA->Picture->LoadFromFile("img/pytanie buffor.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer5->Play();
        Application->ProcessMessages(); Sleep(2600);
        OdpA->Picture->LoadFromFile("img/pytanie dobrze.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer4->Play();
        Application->ProcessMessages(); Sleep(4000);
        OdpA->Picture->LoadFromFile("img/pod odpowiedz.bmp");
        *w+=1;
        s=300;
        zmien_pytania();
        }

        else
        {
        OdpA->Picture->LoadFromFile("img/pytanie buffor.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer5->Play();
        Application->ProcessMessages(); Sleep(2600);
        OdpA->Picture->LoadFromFile("img/pytanie zle.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer6->Play();
        Application->ProcessMessages(); Sleep(2600);
        przegrales();
        }

        sprawdz();

}
//---------------------------------------------------------------------------



void __fastcall TMilionerzy::DClick(TObject *Sender)
{
        if(D->Caption == Poprawna)
        {
        OdpD->Picture->LoadFromFile("img/pytanie buffor.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer5->Play();
        Application->ProcessMessages(); Sleep(2600);
        OdpD->Picture->LoadFromFile("img/pytanie dobrze.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer4->Play();
        Application->ProcessMessages(); Sleep(4000);
        OdpD->Picture->LoadFromFile("img/pod odpowiedz.bmp");
        *w+=1;
        s=300;
        zmien_pytania();
        }

        else
{
        OdpD->Picture->LoadFromFile("img/pytanie buffor.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer5->Play();
        Application->ProcessMessages(); Sleep(2600);
        OdpD->Picture->LoadFromFile("img/pytanie zle.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer6->Play();
        Application->ProcessMessages(); Sleep(2600);
        przegrales();
}

       sprawdz();
}
//---------------------------------------------------------------------------

void __fastcall TMilionerzy::CClick(TObject *Sender)
{
        if(C->Caption == Poprawna)
        {
        OdpC->Picture->LoadFromFile("img/pytanie buffor.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer5->Play();
        Application->ProcessMessages(); Sleep(2600);
        OdpC->Picture->LoadFromFile("img/pytanie dobrze.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer4->Play();
        Application->ProcessMessages(); Sleep(4000);
        OdpC->Picture->LoadFromFile("img/pod odpowiedz.bmp");
        *w+=1;
        s=300;
        zmien_pytania();
        }

        else
{
        OdpC->Picture->LoadFromFile("img/pytanie buffor.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer5->Play();
        Application->ProcessMessages(); Sleep(2600);
        OdpC->Picture->LoadFromFile("img/pytanie zle.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer6->Play();
        Application->ProcessMessages(); Sleep(2600);
        przegrales();
}

        sprawdz();
}
//---------------------------------------------------------------------------

void __fastcall TMilionerzy::BClick(TObject *Sender)
{
        if(B->Caption == Poprawna)
        {
        OdpB->Picture->LoadFromFile("img/pytanie buffor.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer5->Play();
        Application->ProcessMessages(); Sleep(2600);
        OdpB->Picture->LoadFromFile("img/pytanie dobrze.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer4->Play();
        Application->ProcessMessages(); Sleep(4000);
        OdpB->Picture->LoadFromFile("img/pod odpowiedz.bmp");
        *w+=1;
        s=300;
        zmien_pytania();
        }

        else
{
        OdpB->Picture->LoadFromFile("img/pytanie buffor.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer5->Play();
        Application->ProcessMessages(); Sleep(2600);
        OdpB->Picture->LoadFromFile("img/pytanie zle.bmp");
        if(MuteButton->Caption=="Mute") MediaPlayer6->Play();
        Application->ProcessMessages(); Sleep(2600);
        przegrales();
}

       sprawdz();
}
//---------------------------------------------------------------------------



void __fastcall TMilionerzy::MuteButtonClick(TObject *Sender)
{
        if(MuteButton->Caption=="Mute")
        {
        MediaPlayer1->Pause();
        MediaPlayer2->Pause();
        MediaPlayer3->Pause();
        MediaPlayer4->Pause();
        MediaPlayer5->Pause();
        MediaPlayer6->Pause();
        MuteButton->Caption="Unmute";
        }
        else
        {
        MediaPlayer1->Pause();
        MediaPlayer2->Pause();
        MediaPlayer3->Pause();
        MediaPlayer4->Pause();
        MediaPlayer5->Pause();
        MediaPlayer6->Pause();
        MuteButton->Caption="Mute";
        }
}
//---------------------------------------------------------------------------



void __fastcall TMilionerzy::Timer1Timer(TObject *Sender)
{
        // Wypelnienie paska ladowania
        s--;
	ladowanie->Position = s;

        // Koniec czasu
        if (s==0 && *w<5) {if(MuteButton->Caption=="Mute") MediaPlayer6->Play();przegrales();}
        else if (s==0 && *w>=5&& *w<10) {if(MuteButton->Caption=="Mute") MediaPlayer6->Play();przegrales();Pytanie1->Caption="Nagroda gwarantowana 1000";}
        else if (s==0 && *w>=10) {if(MuteButton->Caption=="Mute") MediaPlayer6->Play();przegrales();Pytanie1->Caption="Nagroda gwarantowana 32 000";}

        switch(*w)
{
        case 0: Znacznik->Top=576;                      break;
        case 1: Znacznik->Top=546;                      break;
        case 2: Znacznik->Top=516;                      break;
        case 3: Znacznik->Top=486;                      break;
        case 4: Znacznik->Top=456;                      break;
        case 5: Znacznik->Top=426;                      break;
        case 6: Znacznik->Top=396;                      break;
        case 7: Znacznik->Top=366;                      break;
        case 8: Znacznik->Top=336;                      break;
        case 9: Znacznik->Top=306;                      break;


}
}
//---------------------------------------------------------------------------


void __fastcall TMilionerzy::koniecClick(TObject *Sender)
{
if (Application->MessageBox("Czy na pewno chcesz zakoñczyc?",
        "Zakoncz", MB_YESNO | MB_ICONQUESTION) == IDNO)
        {
        Action=caNone;
        }
        else
        {
        if(MuteButton->Caption=="Mute") MediaPlayer6->Play();
        przegrales();
        koniec->Enabled=false;
        }        
}
//---------------------------------------------------------------------------


void __fastcall TMilionerzy::AutorClick(TObject *Sender)
{
        Application->MessageBox("Autor to mistrz!",
        "Info", MB_OK | MB_ICONQUESTION);
}
//---------------------------------------------------------------------------


void __fastcall TMilionerzy::kolo2Click(TObject *Sender)
{
if(A->Caption==Poprawna)OdpA->Picture->LoadFromFile("img/pytanie buffor.bmp");
else if(B->Caption==Poprawna)OdpB->Picture->LoadFromFile("img/pytanie buffor.bmp");
else if(C->Caption==Poprawna)OdpC->Picture->LoadFromFile("img/pytanie buffor.bmp");
else if(D->Caption==Poprawna)OdpD->Picture->LoadFromFile("img/pytanie buffor.bmp");
}
//---------------------------------------------------------------------------


void __fastcall TMilionerzy::kolo3Click(TObject *Sender)
{
        Kolo3Odp->Visible=true;
        if(A->Caption==Poprawna)Kolo3Odp->Picture->LoadFromFile("img/OdpA.bmp");
        else if(B->Caption==Poprawna)Kolo3Odp->Picture->LoadFromFile("img/OdpB.bmp");
        else if(C->Caption==Poprawna)Kolo3Odp->Picture->LoadFromFile("img/OdpC.bmp");
        else if(D->Caption==Poprawna)Kolo3Odp->Picture->LoadFromFile("img/OdpD.bmp");
        kolo3->Cursor=crDefault;
        kolo3->Picture->LoadFromFile("img/kolo3uzyte.bmp");
}
//---------------------------------------------------------------------------

