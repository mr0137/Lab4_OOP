#include "TreeNode.h"

TreeNode::TreeNode()
{
	BookId = 0;
	Author = "";
	Title = "";
	Year = 0;
	Quantity = 0;

	this->Left = nullptr;
	this->Right = nullptr;
}

TreeNode::TreeNode(int f_id, string f_author, string f_title, int f_year, int f_quantity)
{
	BookId = f_id;
	Author = f_author;
	Title = f_title;
	Year = f_year;
	Quantity = f_quantity;

	this->Left = nullptr;
	this->Right = nullptr;
}

int TreeNode::GetBookId() const
{
	return BookId;
}

string TreeNode::GetAuthor() const
{
	return Author;
}

string TreeNode::GetTitle() const
{
	return Title;
}

int TreeNode::GetYear() const
{
	return Year;
}

int TreeNode::GetQuantity() const
{
	return Quantity;
}

TreeNode * TreeNode::GetLeft() const
{
	return Left;
}

TreeNode * TreeNode::GetRight() const
{
	return Right;
}

void TreeNode::SetBookId(int f_id)
{
	BookId = f_id;
}

void TreeNode::SetAuthor(string f_author)
{
	Author = f_author;
}

void TreeNode::SetTitle(string f_title)
{
	Title = f_title;
}

void TreeNode::SetYear(int f_year)
{
	Year = f_year;
}

void TreeNode::SetQuantity(int f_quantity)
{
	Quantity = f_quantity;
}

void TreeNode::SetLeft(TreeNode * node)
{
	Left = node;
}

void TreeNode::SetRight(TreeNode * node)
{
	Right = node;
}

void TreeNode::Print()
{
	cout << "BookId : " << BookId << endl;
	cout << "Author : " << Author << endl;
	cout << "Title : " << Title << endl;
	cout << "Year : " << Year << endl;
	cout << "Quantity : " << Quantity << endl;
	cout << "-~-~-~-~-" << endl;
}

