#include "Euro.h"
#include <iostream>

using namespace std;

ostream &operator<<(ostream os, const Euro &e)
{
    os << e.asString() << "Euro";
    return os;
}

istream &operator>>(istream is, Euro& e)
{
    cout << "Euro-sum (Format ...x,xx): ";
    int euro = 0, cents = 0; char c = 0;
    if(!(is >> euro >> c >> cents)) return is;
    if((c != ',' && c != '.') || cents >= 100)
        is.setstate(ios::failbit);
    else
        e = Euro(euro, cents);
    return is;
}

