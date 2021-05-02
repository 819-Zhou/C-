#include <sstream>
#include <iomanip>

using namespace std;


class Euro
{
  private:
    long data;
  public:
    Euro(int euro=0, int cents=0)
    {
        data = 100L * (long)euro + cents;
    }
    Euro(double x)
    {
        x *= 100.0;
        data = (long)(x >= 0.0 ? x + 0.5 : x - 0.5);
    }
    // operator double() const {return (double)data / 100.0;}
    long getEuroPart() const {return data / 100;}
    int getCents() const {return (int)(data % 100);}
    double asDouble() const {return (double) data / 100.0;}
    string asString() const;
    void print(ostream &os) const
    {
        os << asString() << " Euro" << endl;
    }
    friend Euro operator-(const Euro &e1, const Euro &e2);
    friend Euro operator+(const Euro &e1, const Euro &e2);
    friend Euro operator*(const Euro &e, double x)
    {
        Euro temp(((double)e.data / 100.0) * x);
        return temp;
    }
    friend Euro operator*(double x, const Euro &e)
    {
        return e * x;
    }

    Euro &operator+=(const Euro &e)
    {
        data += e.data;
        return *this;
    }
    Euro &operator-=(const Euro& e)
    {
        data -= e.data;
        return *this;
    }

};

inline Euro operator-(const Euro &e1, const Euro &e2)
{
    Euro temp;
    temp.data = e1.data - e2.data;
    return temp;
}

inline Euro operator+(const Euro &e1, const Euro &e2)
{
    Euro temp;
    temp.data = e1.data - e2.data;
    return temp;
}

ostream &operator<<(ostream os, const Euro &e);
istream &operator>>(istream is, Euro& e);

inline string Euro::asString() const
{
    stringstream sStream;
    long temp = data;
    if(temp < 0) {sStream << '-'; temp = -temp;}
        sStream << temp / 100 << ', '
                << setfill('0') << setw(2) << temp % 100;
        return sStream.str();
}

