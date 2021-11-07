#include <iostream>
#include "biblioteka.h"

using namespace std;

void dzienTygodnia (int dzTyg)
{
    switch (dzTyg)
    {
        case 0:
            cout << " (niedziela)\n";
            break;

        case 1:
        case -6:
            cout << " (poniedzialek)\n";
            break;

        case 2:
        case -5:
            cout << " (wtorek)\n";
            break;

        case 3:
        case -4:
            cout << " (sroda)\n";
            break;

        case 4:
        case -3:
            cout << " (czwartek)\n";
            break;

        case 5:
        case -2:
            cout << " (piatek)\n";
            break;

        case 6:
        case -1:
            cout << " (sobota)\n";
            break;
    }
}

