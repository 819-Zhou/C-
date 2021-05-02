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
    long getEuroPart() const {return data / 100;}
    int getCents() const {return (int)(data % 100);}
    double asDouble() const {return (double) data / 100.0;}
    string asString() const;
    void print(ostream &os) const
    {
        os << asString() << " Euro" << endl;
    }
    Euro operator-() const
    {
        Euro temp;
        temp.data = -data;
        return temp;
    }
    Euro operator+(const Euro &e) const
    {
        Euro temp;
        temp.data = data + e.data;
        return temp;
    }
    Euro operator-(const Euro &e) const
    {
        Euro temp;
        temp.data = data - e.data;
        return temp;
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

inline string Euro::asString() const
{
    stringstream sStream;
    long temp = data;
    if(temp < 0) {sStream << '-'; temp = -temp;}
        sStream << temp / 100 << ', '
                << setfill('0') << setw(2) << temp % 100;
        return sStream.str();
}