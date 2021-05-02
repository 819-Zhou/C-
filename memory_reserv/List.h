#include <iostream>
#include <iomanip>

using namespace std;

class Person
{
  private:
	string name;
	double money;
	Person* next;

  public:
  	Person(string n="anonym", int m=0, Person* next=NULL)
  	: name(n), money(m), next(next) {}
  	Person *getNext() const {return next;}
	string getName() const {return this->name;}
	void setName(string n) { name = n; }
	double getMoney() const {return this->money;}
	void setMoney(double m) { money = m; }
  	friend class List;
};

class List
{
  private:
  	Person *first, *last;
  public:
	List(const List& l);
  	List() {first = last = NULL;}
  	~List();
  	Person* front() const {return first;}
  	Person* back()  const {return last;}
  	void push(Person* p);
	void push(const string &name, double money);
  	void pop();

	List &operator=(const List&);
};

ostream &operator<<(ostream &os, const Person &p);
ostream &operator<<(ostream &os, const List &l);
