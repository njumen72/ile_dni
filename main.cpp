#include <iostream>
#include <windows.h>
#include "biblioteka.h"

using namespace std;

inline void zlaWartosc ();

int urRok, urMiesiac, urDzien;
int dniRoku;
int dniMiesiaca [12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    SYSTEMTIME lt;
    GetLocalTime (&lt);
    char znak;

    do {
        system ("cls");
        dniRoku = 0;
        cout << "Podaj date swoich narodzin\n";
        cout << "--------------------------\n";
        // walidacja wprowadzanych danych
    zlyRok:
        cout.width (17);
        cout << "Podaj rok: ";
        cin >> urRok;

        if ((urRok > lt.wYear) || (urRok < 1583)) // od poczadku 1583 obowiazuje kalendarz gregorianski
        {
            zlaWartosc();
            goto zlyRok;
        }

    zlyMiesiac:
        cout.width (17);
        cout << "Podaj miesiac: ";
        cin >> urMiesiac;

        if ((urMiesiac > 12) || (urMiesiac < 1) || ((urRok == lt.wYear) && (urMiesiac > lt.wMonth)))
        {
            zlaWartosc();
            goto zlyMiesiac;
        }

    zlyDzien:
        cout.width (17);
        cout << "Podaj dzien: ";
        cin >> urDzien;

        if ((urDzien < 1) || ((urRok == lt.wYear) && (urMiesiac == lt.wMonth) && (urDzien >= lt.wDay)))
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
                    if (urDzien > 31)
                    {
                        zlaWartosc();
                        goto zlyDzien;
                    }

                    break;

                case 4:
                case 6:
                case 9:
                case 11:
                    if (urDzien > 30)
                    {
                        zlaWartosc();
                        goto zlyDzien;
                    }

                    break;

                case 2:
                    if (urDzien > 29)
                    {
                        zlaWartosc();
                        goto zlyDzien;
                    }
                    else if (urDzien == 29)
                    {
                        if (przestepny (urRok))
                            goto dalej;
                        else
                        {
                            zlaWartosc();
                            goto zlyDzien;
                        }
                    }
            }
        }

    dalej:

        for (int i = 0; i < (urMiesiac - 1); i++) // kalkulacja dnia roku urodzenia
            dniRoku += dniMiesiaca[i];

        int urDzienRoku;
        urDzienRoku = dniRoku + urDzien;

        if (przestepny (urRok))
        {
            if (urMiesiac > 2)
                urDzienRoku++;
        }

        int dni;

        if (przestepny (urRok))
            dni = 366 - urDzienRoku;
        else
            dni = 365 - urDzienRoku;

        int lata;
        lata = lt.wYear - urRok; // kalkulacja ilosci dni w latach minionych
        dni += lata * 365;
        int ileDodac = 0;

        for (int i = urRok; i <= lt.wYear; i++) // dni przestepnych w zakresie lat
        {
            if (przestepny (i))
                ileDodac++;
        }

        if (przestepny (urRok))
            ileDodac--;

        dni += ileDodac;
        // dzien biezacego roku
        dniRoku = 0;

        for (int j = 0; j < (lt.wMonth - 1); j++)
            dniRoku += dniMiesiaca[j];

        int dzien;
        dzien = dniRoku + lt.wDay;

        if (przestepny (lt.wYear))
            dni -= (366 - dzien);
        else
            dni -= (365 - dzien);

        int urDzTygodnia;
        urDzTygodnia = dni % 7; // urodzeniowy dzien tygodnia
        urDzTygodnia = (lt.wDayOfWeek - urDzTygodnia) % 7;
        // lata
        lata = (dni - ileDodac) / 365;
        // wyswietlanie danych wejsciowych
        cout << "--------------------------\n";
        cout.width (16);
        cout << "Data urodzenia: " << urRok << ".";
        cout.fill ('0');
        cout.width (2);
        cout << urMiesiac << ".";
        cout.width (2);
        cout << urDzien;
        dzienTygodnia (urDzTygodnia);
        cout.fill (' ');
        cout.width (16);
        cout << " Biezaca data: " << lt.wYear << ".";
        cout.fill ('0');
        cout.width (2);
        cout << lt.wMonth << ".";
        cout.width (2);
        cout << lt.wDay;
        cout.fill (' ');
        dzienTygodnia (lt.wDayOfWeek);
        cout << "--------------------------\n";
        cout << "Urodzil(es/as) sie w " << urDzienRoku << " dniu " << urRok << " roku" << endl;
        cout << "Twoj znak zodiaku to";
        zodiak (urMiesiac, urDzien);
        cout << endl;
        cout << "Liczysz " << dni << " dni" << endl;
        int miesiace;
        miesiace = lt.wMonth - (urMiesiac % 12);

        if (urDzien > lt.wDay)
            miesiace--;

        if (lt.wDay < urDzien)
        {
            dni = (dniMiesiaca[lt.wMonth - 1] - urDzien + 1) + lt.wDay;

            if (przestepny (lt.wYear))
                dni++;
        }
        else
            dni = lt.wDay - urDzien;

        cout << "Masz " << lata << " lat(a), " << miesiace << " miesia(ce/cy), " << dni << " dni." << endl;
        //-------------------------
        cout << "\nZakoncz: [t] tak / [n] nie ? :";
        cin >> znak;
    }
    while ((znak != 't') && (znak != 'T'));

    return 0;
}
//----------------------------------------------
inline void zlaWartosc ()
{
    cerr << "Zla wartosc!. Wpisz ponownie\n";
}
