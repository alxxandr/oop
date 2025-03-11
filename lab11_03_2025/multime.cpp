#include "multime.h"
#pragma warning(disable : 4996)

Multime::Multime()
{
    dim = 10;
    date = new int[dim];
    n = 0;
}
Multime::Multime(int d)
{
    dim = d;
    date = new int[dim];
    n = 0;
}
Multime::Multime(const Multime &M)
{
    dim = M.dim;
    n = M.n;
    date = new int[dim];
    for (int i = 0; i < n; i++)
    {
        date[i] = M.date[i];
    }
}
Multime::~Multime()
{
    if (date)
        delete[] date;
}
void Multime::adauga(int v)
{
    if (n == dim)
    {
        cout << "Multimea este plina!" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
        if (date[i] ==
            v)
            return;
    date[n++] =
        v;
}
void Multime::extrage(int
                          v)
{
    for (int i = 0; i < n; i++)
        if (date[i] ==
            v)
        {
            for (int j = i; j < n - 1; j++)
                date[j] = date[j + 1];
            n--;
        }
}
Multime &Multime::operator+=(const int &
                                 i)
{
    adauga(
        i);
    return *this;
}
Multime &Multime::operator+=(const Multime &
                                 M)
{
    for (int i = 0; i <
                    M.n;
         i++)
        adauga(
            M.date[i]);
    return *this;
}
Multime &Multime::operator-=(const int &
                                 i)
{
    extrage(
        i);
    return *this;
}
Multime &Multime::operator=(const Multime &
                                M)
{
    if (this != &M)
    {
        if (date)
            delete[] date;
        dim =
            M.dim;
        n =
            M.n;
        date = new int[dim];
        for (int i = 0; i < n; i++)
        {
            date[i] =
                M.date[i];
        }
    }
    return *this;
}
ostream &operator<<(ostream &out, const Multime &
                                      M)
{
    cout << "{";
    for (int i = 0; i <
                    M.n;
         i++)
        cout << " " << M.date[i];
    cout << " }" << endl;
    return out;
}
istream &operator>>(istream &in, Multime &
                                     M)
{
    M.n = 0;
    char linie[100], *temp;
    in.getline(linie, 100);
    temp = strtok(linie, " ");
    while (temp != NULL)
    {
        M.adauga(atoi(temp));
        temp = strtok(NULL, " ");
    }
    return in;
}