#include "List.h"

List::List(const List& l)
{
	first = last = NULL;
	for(Person *i = l.first; i != NULL; i = i->getNext())
		push(i);
}

List::~List()
{
	Person *p = first, *next = NULL;

	for(; p != NULL; p = next)
	{
		next = p->next;
		delete p;
	}
}

void List::push(Person *p)
{
	if(last == NULL)
		first = last = p;
	else
	{
		last->next = p;
		last = p;
	}
}

void List::push(const string &n, const double m)
{
	Person *p = new Person(n, m);
	if(last == NULL)
		first = last = p;
	else
	{
		last->next = p;
		last = p;
	}
}

void List::pop()
{
	if(first != NULL)
	{
		Person *p = first;
		first = first->next;
		delete p;
		if(first == NULL)
			last = NULL;
	}
}

List &List::operator=(const List& l)
{
	Person *tmp = first,
		   *next = NULL;

	for(; tmp != NULL; tmp = next)
	{
		next = tmp->next;
		delete tmp;
	} 
	first = last = NULL;

	for(tmp = l.first; tmp != NULL; tmp = tmp->next)
		push(tmp);
	return *this;
}

ostream &operator<<(ostream &os, const List &l)
{
	if(l.front() == NULL)
	{
		os << "The List is empty\n";
	}

	for(Person *i = l.front(); i != NULL; i = i->getNext())
	{
		os << *i << endl;
	}
	return os;
}

ostream &operator<<(ostream &os, const Person &p)
{
	os << setw(20) << p.getName() << left << "money: "
	   << fixed << setprecision(2) << p.getMoney();
	return os;
}
