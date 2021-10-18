#include <iostream>
#include <windows.h>
#include "zodiak.h"
#include "przestepny.h"

using namespace std;

void zlaWartosc (void);

unsigned int urRok, urMiesiac, urDzien;
int dniRoku = 0;

int main()
{
    SYSTEMTIME lt;
    GetSystemTime (&lt);
    cout << "Podaj date swoich narodzin\n";
    cout << "--------------------------\n";
    //waliacja wprowadzanych danych
zlyRok:
    cout.width (17);
    cout << "Podaj rok: ";
    cin >> urRok;
    if (urRok > lt.wYear)
    {
        zlaWartosc();
        goto zlyRok;
    }
zlyMiesiac:
    cout.width (17);
    cout << "Podaj miesiac: ";
    cin >> urMiesiac;
    if ((urRok == lt.wYear) && (urMiesiac > lt.wMonth) || (urMiesiac > 12))
    {
        zlaWartosc();
        goto zlyMiesiac;
    }
zlyDzien:
    cout.width (17);
    cout << "Podaj dzien: ";
    cin >> urDzien;
    if ((urRok == lt.wYear) && (urMiesiac == lt.wMonth) && (urDzien >= lt.wDay))
    {
        zlaWartosc();
        goto zlyDzien;
    }
    else
    {
        switch (urMiesiac)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                {
                    if (urDzien > 31)
                    {
                        zlaWartosc();
                        goto zlyDzien;
                    }
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                {
                    if (urDzien > 30)
                    {
                        zlaWartosc();
                        goto zlyDzien;
                    }
                }
                break;
            case 2:
                {
                    if (urDzien > 29)
                    {
                        zlaWartosc();
                        goto zlyDzien;
                    }
                    else if (urDzien == 29)
                    {
                        if (przestepny (urRok))
                        {
                            goto dalej;
                        }
                        else
                        {
                            zlaWartosc();
                            goto zlyDzien;
                        }
                    }
                }
        }
    }
dalej:
    //wyswietlanie danych wejsciowych
    cout << "--------------------------\n";
    cout.width (16);
    cout << "Data urodzenia: " << urRok << ".";
    cout.fill ('0');
    cout.width (2);
    cout << urMiesiac << ".";
    cout.width (2);
    cout << urDzien << endl;
    cout.fill (' ');
    cout.width (16);
    cout << " Biezaca data: " << lt.wYear << ".";
    cout.fill ('0');
    cout.width (2);
    cout << lt.wMonth << ".";
    cout.width (2);
    cout << lt.wDay << endl;
    cout << "--------------------------\n";
    //kalkulacja dnia roku urodzenia
    int dniMiesiaca [12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < (urMiesiac - 1); i++)
    {
        dniRoku += dniMiesiaca[i];
    }
    int urDzienRoku;
    urDzienRoku = dniRoku + urDzien;
    if (przestepny (urRok))
    {
        if (urMiesiac > 2)
            urDzienRoku++;
    }
    cout << "Urodzil(es/as) sie w " << urDzienRoku << " dniu " << urRok << " roku" << endl;
    cout << "Twoj znak zodiaku to";
    zodiak (urMiesiac, urDzien);
    cout << endl;
    int dni;
    if (przestepny (urRok))
    {
        dni = 366 - urDzienRoku;
    }
    else
    {
        dni = 365 - urDzienRoku;
    }
    //kalkulacja ilosci dni w latach minionych
    int lata;
    lata = lt.wYear - urRok;
    //cout << lata << " lat" << endl;
    dni += lata * 365;
    //cout << dni << endl;
    int ileDodac;
    ileDodac = (lt.wYear - urRok) / 4; //dni przestepnych w zakresie lat
    dni += ileDodac;
    //------------------------
    dniRoku = 0;
    for (int j = 0; j < (lt.wMonth - 1); j++)
    {
        dniRoku += dniMiesiaca[j];
    }
    int dzien;
    dzien = dniRoku + lt.wDay;
    cout << dzien << " dzien biezacego roku" << endl;
    if (przestepny (lt.wYear))
    {
        dni -= (366 - dzien);
    }
    else
    {
        dni -= (365 - dzien);
    }
    cout << "Liczysz " << dni << " dni" << endl;
    cout << "Masz " << dni / 365 << " lat(a)" << endl;
    cout << endl;
    system ("pause");
    return 0;
}
//----------------------------------------------
void zlaWartosc (void)
{
    cerr << "Zla wartosc. Wprowadz ponownie.\n";
}
