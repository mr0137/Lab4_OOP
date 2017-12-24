#include "BinTree.h"
#include "Test.h"
#include <fstream>

int main()
{
	BinTree f;
	f=Database("LibraryFile.csv", f);
	Print(f);
	f.RemoveNode(3);
	cout << endl << endl;
	f.Print();
	cout << endl << endl;
	f.AddNode(new TreeNode(3,"Dickens","Little Dorrit",1855,1));
	f.AddNode(new TreeNode(3, "Dickens", "Little Dorrit", 1855, 1));
	f.Print();
	cout << endl << endl;
	f.Print("Dickens");

	system("pause");
	return 0;
}