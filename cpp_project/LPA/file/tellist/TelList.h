#include <string>

using namespace std;

#define PSEUDO -1
#define MAX 100

struct Person {string name, nr;};

class TelList
{
  private:
    Person list[MAX];
    int counter;
    string filename;
    bool dirty;
  public:
    TelList() : counter(0), filename(""), dirty(false){}
    int getCount() {return this->counter;}

    Person *retrieve(int i)
    {return (i >= 0 & i < this->counter) ? &list[i] : NULL;}
    bool append(const Person& p)
    {return this->append(p.name, p.nr);}
    bool append(const string &name, const string &nr);
    bool erase(const string &name);
    int search(const string & name) const;
    void print() const;
    int print(const string &name) const;
    int getNewPerson();

    const string &getFilename() const {return this->filename;}
    bool setFilename(const string& fn)
    {
        if(fn.empty()) return false;
        else {this->filename = fn; this->dirty = true; return true;}
    }
    bool isDirty() const {return this->dirty;}
    bool load();
    bool save();
    bool saveAs();
};
