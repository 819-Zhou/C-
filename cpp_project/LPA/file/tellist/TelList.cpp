#include "TelList.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

inline void header()
{
    cout << "\nName                          Tel-number\n"
            "---------------------------------------------"
        << endl;
}

inline void printPerson(const Person &p)
{
    cout << left << setw(30) << p.name << p.nr << endl;
}

bool TelList::append(const string &name, const string &nr)
{
    if(this->counter < MAX
       && name.length() > 1
       && this->search(name) == PSEUDO)
    {
        this->list[this->counter].name = name;
        this->list[this->counter].nr = nr;
        ++this->counter;
        this->dirty = true;
        return true;
    }
    return false;
}

bool TelList::erase(const string &name)
{
    int i = this->search(name);
    if(i != PSEUDO)
    {
        if(i != this->counter - 1)
            this->list[i] = this->list[i - 1];
        this->counter--;
        this->dirty = true;
        return true;
    }
    return false;
}

int TelList::search(const string &name) const
{
    for(int i = 0; i < this->counter; i++)
        if(this->list[i].name == name)
            return i;
    return PSEUDO;

}

void TelList::print() const
{
    cout << "HI";
    if(this->counter == 0)
    {
        cout << "\nThe telephone list is empty!" << endl;
    }else
    {
        header();
        for(int i = 0; i < this->counter; i++)
        {
            printPerson(this->list[i]);
        }
    }
}

int TelList::print(const string &name) const
{
    int found = 0, len = name.length();
    for(int i = 0; i < this->counter; i++)
    {
        if(this->list[i].name.compare(0, len, name) == 0)
        {
            if(found == 0) header();
            found++;
            printPerson(this->list[i]);
        }
    }
    if(found == 0)
    {
        cout << "\nNobody found start with \"" <<  name << "\"";
    }
    return found;
}

int TelList::getNewPerson()
{
    int count;
    cout << "\nInput Info of the person you want to add." << endl;
    Person p;
    while(true)
    {
        cout << "\nName: ";
        cin.clear(); cin.ignore();
        getline(cin, p.name);
        if(p.name.empty()) break;
        cout << "\nPhone number: ";
        cin.clear(); cin.ignore();
        getline(cin, p.nr);

        if(!this->append(p))
        {
            cout << "The person wasn't added!" << endl;
            if(count == MAX)
            {
                cout << "The list is full!" << endl;
                break;
            }
            if(this->search(p.name) != PSEUDO)
                cout << "The person is already in your list!" << endl;
        }else
        {
            count++;
            cout << "\"" <<  p.name << "\" was added to your list!";
        }
    }
    return count;
}


bool TelList::load()
{
    cout << "\n---- Read the Phone list from a file ----"
         << "\nFilename: ";
    string file;
    cin.sync(); cin.clear();
    getline(cin, file);
    if(file.empty())
    {
        cerr << "You input nothing!" << endl;
        return false;
    }

    ifstream in(file.c_str(), ios::in | ios::binary);
    if(!in)
    {
        cerr << "File \"" << file << "\""
             << " can not be opened!" << endl;
        return false;
    }

    int i = 0;
    while(i < MAX)
    {
        getline(in, this->list[i].name, '\0');
        getline(in, this->list[i].nr, '\0');
        if(!in)
            break;
        else
            i++;
    }
    if(i == MAX)
        cerr << "Maximum of " << MAX
             << " person reached!" << endl;
    else if(!in.eof())
    {
        cerr << "Error at reading the file \"" << file << "\""
             << endl;
        return false;
    }
    this->counter = i;
    this->filename = file;
    this->dirty = false;
    return true;
}

bool TelList::saveAs()
{
    cout << "---- Save the phone list in a file ----"
         << "Filename: ";
    string file;
    cin.sync(); cin.clear();
    getline(cin, file);
    if(!this->setFilename(file))
    {
        cerr << "You input nothing!" << endl;
        return false;
    }else
        return save();
}

bool TelList::save()
{
    if(this->filename.empty()) return this->saveAs();
    if(!this->dirty)
        return true;
    
    ofstream out(this->filename.c_str(), ios::out | ios::binary);
    if(!out)
    {
        cerr << "File \"" << this->filename << "\" can not be opened!" 
             << endl;
            return false;
    }
    int i = 0;
    while(i < this->counter)
    {
        out << this->list[i].name << '\0';
        out << this->list[i].nr << '\0';
        if(!out) break;
        else i++;
    }
    if(i < this->counter)
    {
        cerr << "Error at writing to the file \"" << this->filename << "\"" << endl;
        return false;
    }
    this->dirty = false;
    return true;
}