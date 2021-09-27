#include <iostream>
#include <windows.h>

using namespace std;

unsigned int urRok, urMiesiac, urDzien;

int main()
{
    SYSTEMTIME lt;
    GetSystemTime (&lt);
    cout << "Podaj date swoich narodzin\n";
    cout << "--------------------------\n";
zlyRok:
    cout.width (17);
    cout << "Podaj rok: ";
    cin >> urRok;
    if (urRok > lt.wYear)
    {
        cout << "Zly format roku!. Wprowadz ponownie.\n";
        goto zlyRok;
    }
zlyMiesiac:
    cout.width (17);
    cout << "Podaj miesiac: ";
    cin >> urMiesiac;
    if ((urRok == lt.wYear) && (urMiesiac > lt.wMonth) || (urMiesiac > 12))
    {
        cout << "Zly format miesiaca!. Wprowadz ponownie.\n";
        goto zlyMiesiac;
    }
zlyDzien:
    cout.width (17);
    cout << "Podaj dzien: ";
    cin >> urDzien;
    if ((urRok == lt.wYear) && (urMiesiac == lt.wMonth) && (urDzien >= lt.wDay))
    {
        cout << "Zly format dnia!. Wprowadz ponownie.\n";
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
                    cout << "Zly format dnia!. Wprowadz ponownie.\n";
                    goto zlyDzien;
                }
                break;
            }
            case 4:
            case 6:
            case 9:
            case 11:
            {
                if (urDzien > 30)
                {
                    cout << "Zly format dnia!. Wprowadz ponownie.\n";
                    goto zlyDzien;
                }
                break;
            }
            case 2:
            {
                if (urDzien > 29)
                {
                    cout << "Zly format dnia!. Wprowadz ponownie.\n";
                    goto zlyDzien;
                }
                else if (urDzien == 29)
                {
                    if (((urRok % 4 == 0) && (urRok % 100 != 0)) || (urRok % 400 == 0))
                    {
                        goto dalej;
                    }
                    else
                    {
                        cout << "Zly format dnia!. Wprowadz ponownie.\n";
                        goto zlyDzien;
                    }
                }
                break;
            }
        }
    }
dalej:
    cout << "--------------------------\n";
    cout.width (16);
    cout << " Urodziles sie: " << urRok << ".";
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
    int ileDodac;
    ileDodac = (lt.wYear - urRok) / 4;
    cout << ileDodac << endl;
    int dniMiesiaca [12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cout << endl;
    system ("pause");
    return 0;
}
