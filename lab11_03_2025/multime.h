#include <iostream>
using namespace std;


class Multime
{
    int *date;
    int dim; // dimensiunea
    int n;   // numarul curent de elemente
public:
    Multime();
    Multime(int);
    Multime(const Multime &);
    ~Multime();
    void adauga(int);
    void extrage(int);
    Multime &operator+=(const int &);
    Multime &operator+=(const Multime &);
    Multime &operator-=(const int &);
    Multime &operator=(const Multime &);
    friend ostream &operator<<(ostream &, const Multime &);
    friend istream &operator>>(istream &, Multime &);
};

