#include "Fraction.h"
#include <iostream>

using namespace std;

int main()
{
    Fraction f1, f2(0.565346);
    cout << f2;
    cin >> f1;
    cout << (f1 * f2).asResult(10);
    return 0;
}