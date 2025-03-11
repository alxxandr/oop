#include <iostream>
#include "multime.h"
using namespace std;

int main()
{
    Multime M, N;
    M += 13; // in loc de adauga sa avem +=
    M -= 2;  // in loc de extrage sa avem -=
    M += 1;
    M += 2;
    M += 3;
    N += 33;
    N += M;
    cout << N << endl;
    Multime P = N;
    cout << P << endl;
    M = P;
    cout << P << endl;
    cin >> P;
    cout << P << endl;
}
