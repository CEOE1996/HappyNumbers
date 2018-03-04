#include "num.h"

Num::Num(){

}

Num::Num(const short& n){
    N = n;
}

void Num::setN(const short& n)
{
    N = n;
}

short Num::getN()
{
    return N;
}
short Num::Square()
{
    return N * N;
}

bool Num::IsPrimo()
{
    if(N == 2 or N == 3 or N == 5 or N == 7) return true;
    if((N % 2) == 0) return false;
    if((N % 3) == 0) return false;
    if((N % 5) == 0) return false;
    if((N % 7) == 0) return false;
    return true;
}
