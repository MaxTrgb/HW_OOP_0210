#include <iostream>
#include "HashTable.h"
using namespace std;

int main()
{
	HashTable table(5);

	table.add("1", "A");	
	table.add("2", "B");
	table.add("3", "C");
	table.add("4", "D");
	table.add("5", "E");


	table.printTable();

	cout << "\nSearch result: ";
	cout << table.search("3") <<  endl;

	cout << "\nRemoving element: " << endl;
	table.remove("3");

	table.printTable();

}
