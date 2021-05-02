#include "List.h"

using namespace std;

int main()
{
	cout << "---- Linkedlist test ----\n\n";

	List l;
	string name;
	double m;

	cout << "Input name and money! EZ!\n";
	while(true)
	{
		cout << "Name: ";
		getline(cin, name);
		if(name == "`") break;
		cout << "Money: ";
		cin.clear();
		cin >> m;
		cin.ignore();
		l.push(name, m);
	}

	cout << "The list looks like this: \n";
	cout << l << endl;
	cout << "\nCopy from the previous list: \n";
	List copy_l(l);
	cout << copy_l << endl;
	return 0;
}
