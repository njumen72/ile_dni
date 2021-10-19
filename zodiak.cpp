#include <iostream>
#include "zodiak.h"

using namespace std;

void zodiak (int miesiac, int dzien)
{
    switch (miesiac)
    {
        case 1:
            if (dzien < 20)
                cout << " Koziorozec";
            else
                cout << " Wodnik";
            break;
        case 2:
            if (dzien < 19)
                cout << " Wodnik";
            else
                cout << " Ryby";
            break;
        case 3:
            if (dzien < 21)
                cout << " Ryby";
            else
                cout << " Baran";
            break;
        case 4:
            if (dzien < 20)
                cout << " Baran";
            else
                cout << " Byk";
            break;
        case 5:
            if (dzien < 23)
                cout << " Byk";
            else
                cout << " Bliznieta";
            break;
        case 6:
            if (dzien < 22)
                cout << " Bliznieta";
            else
                cout << " Rak";
            break;
        case 7:
            if (dzien < 23)
                cout << "Rak";
            else
                cout << " Lew";
            break;
        case 8:
            if (dzien < 24)
                cout << " Lew";
            else
                cout << " Panna";
            break;
        case 9:
            if (dzien < 23)
                cout << " Panna";
            else
                cout << " Waga";
            break;
        case 10:
            if (dzien < 23)
                cout << " Waga";
            else
                cout << " Skorpion";
            break;
        case 11:
            if (dzien < 22)
                cout << " Skorpion";
            else
                cout << " Strzelec";
            break;
        case 12:
            if (dzien < 22)
                cout << " Strzelec";
            else
                cout << " Koziorozec";
            break;
    }
}
