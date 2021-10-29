#include "biblioteka.h"

bool przestepny (int rok)
{
    if (((rok % 4 == 0) && (rok % 100 != 0)) || (rok % 400 == 0))
        return (true);

    return (false);
}
