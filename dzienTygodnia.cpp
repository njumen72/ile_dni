#include <iostream>
#include <windows.h>
#include "dzienTygodnia.h"

using namespace std;

void dzienTygodnia (int dzTyg)
{
    switch (dzTyg)
    {
        case 0:
            cout << " (niedziela)\n";
            break;

        case 1:
            cout << " (poniedzialek)\n";
            break;

        case 2:
            cout << " (wtorek)\n";
            break;

        case 3:
            cout << " (sroda)\n";
            break;

        case 4:
            cout << " (czwartek)\n";
            break;

        case 5:
            cout << " (piatek)\n";
            break;

        case 6:
            cout << " (sobota)\n";
            break;
    }
}

