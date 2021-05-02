#include <iostream>
#include <iomanip>

class Fraction
{
  private:
    long top, bottom = 0;
  public:
    Fraction(long top=0, long bottom=1)
    {
        if(bottom == 0)
        {
            std::cerr << "\nError: Division by zero!\n";
            exit(1);
        }
        this->top = top;
        this->bottom = bottom;
        this->simplify();
    }
    Fraction(double x);
    double asResult(int precision=2)
    {
        std::cout << std::fixed << std::setprecision(precision);
        return (double)top / bottom;
    }
    void simplify();

    Fraction operator-() {return Fraction(-top, bottom);}
    friend Fraction operator+(const Fraction &f1, const Fraction &f2);
    friend Fraction operator-(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator/(const Fraction &f1, const Fraction &f2);

    friend std::ostream& operator<<(std::ostream& os, const Fraction &f);
    friend std::istream& operator>>(std::istream& is, Fraction &f);

    Fraction operator++(int i)
    {
        top += bottom;
        return *this;
    }
    Fraction operator--(int i)
    {
        top -= bottom;
        return *this;
    }
    Fraction &operator+=(const Fraction &f)
    {
        if(bottom == f.bottom)
        {
            top += f.top;
        }
        else
        {
            bottom *= f.bottom;
            top = top * f.bottom + f.top * bottom;
        }
        return *this;
    }
    Fraction &operator-=(const Fraction &f)
    {
        if(bottom == f.bottom)
        {
            top -= f.top;
        }
        else
        {
            bottom *= f.bottom;
            top = top * f.bottom - f.top * bottom;
        }
        return *this;
    }
    Fraction &operator*=(const Fraction &f)
    {
        top *= f.top;
        bottom *= f.bottom;
        return *this;
    }
     Fraction &operator/=(const Fraction &f)
    {
        top /= f.top;
        bottom /= f.bottom;
        return *this;
    }
};