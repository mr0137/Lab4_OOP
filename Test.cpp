#include "Test.h"

BinTree Database(const string file_name , BinTree f)
{
	int id;
	string title;
	string author;
	int year;
	int quantity;
	char zero;

	ifstream File(file_name);

	if (!File)
	{
		cout << "File could not be opened" << endl;
		exit(1);
	}

	while (File >> id)
	{
		File >> zero;//считываем символ ';'
		getline(File, author, ';');
		getline(File, title, ';');
		File >> year;
		File >> zero;
		File >> quantity;

		if (f.Find(id) == nullptr)//дл€ отсеевани€ повторений
		{
			f.AddNode(new TreeNode(id, author, title, year, quantity));
			/*cout << id << endl;
			cout << author << endl;
			cout << title << endl;
			cout << year << endl;
			cout << quantity << endl;
			cout << "-------" << endl;*/
		}
	}
	
	return f;
}

void Print(BinTree f)
{
	cout << "List of available books: " << endl << endl;
	f.Print();
}

void Print(BinTree f, int f_id)
{
	cout << "Information about Book Id " << f_id << ":" << endl << endl;

	TreeNode* p = f.Find(f_id);

	if (p != nullptr) 
	{
		p->Print();
	}
	else 
	{
		cout << "Book with such number doesn't exist" << endl << endl;
	}
}

void Print(BinTree f, string f_author)
{
		cout << "Book that was written by " << f_author << ":" << endl << endl;
		f.Print(f_author);
	
}

