#include "Fraction.h"

int getDigit(long x)
{
    int result = 1;
    while(x > 10)
    {
        x /= 10;
        result++;
    }
    return result;
}

Fraction::Fraction(double x)
{
    x *= 10000.0;
    x += (x >= 0.0) ? 0.5 : -0.5;
    std::cout << x << std::endl;
    top = long(x);
    bottom = 10000;
    this->simplify();
}

void Fraction::simplify()
{
    if(top == 0)
    {
        bottom = 1;
        return;
    }
    long a = (top < 0) ? -top: top,
         b = bottom,
         temp;

    // iterative
    while(b != 0)
    {
        temp = a % b; a = b; b = temp;
        // std::cout << temp << ", " << a << ", " << b << std::endl;
    }
    /*
        Recursive:

        EUCLID(a,b)
        1  wenn b = 0 dann
        2    Ergebnis = a
        3  sonst
        4    Ergebnis = EUCLID(b, Divisionsrest(a durch b))    // siehe Modulo-Funktion
    */
    top /= a;
    bottom /= a;
}

Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    Fraction temp;
    temp.bottom = f1.bottom * f2.bottom;
    temp.top = f1.top * f2.bottom + f2.top * f1.bottom;
    temp.simplify();
    return temp;
}

Fraction operator-(const Fraction &f1, const Fraction &f2)
{
    Fraction temp;
    temp.bottom = f1.bottom * f2.bottom;
    temp.top = f1.top * f2.bottom - f2.top * f1.bottom;
    temp.simplify();
    return temp;
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    Fraction temp;
    temp.top = f1.top * f2.top;
    temp.bottom = f1.bottom * f2.bottom;
    temp.simplify();
    return temp;
}

Fraction operator/(const Fraction &f1, const Fraction &f2)
{
    Fraction temp;
    temp.top = f1.top * f2.bottom;
    temp.bottom = f1.bottom * f2.top;
    temp.simplify();
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Fraction &f)
{
    os << f.top << '/' << f.bottom;
    return os;
}

std::istream& operator>>(std::istream& is, Fraction &f)\
{
    std::cout << "\nInput a fraction.\n"
              << "Top   : "; is >> f.top;
    std::cout << "Bottom: "; is >> f.bottom;

    if(!is) return is;
    if(f.bottom == 0)
    {
        std::cout << "\nError: The bottom is 0!\n"
                  << "Input a new bottom: "; is >> f.bottom;
        if(f.bottom == 0)
        {
            std::cerr << "\nYou better quit MATH right now!\n";
            exit(1);
        }
    }
    if(f.bottom < 0)
    {
        f.top = -f.top;
        f.bottom = -f.bottom;
    }
    return is;
}


