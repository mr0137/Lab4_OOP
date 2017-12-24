#pragma once
#include <iostream>
#include <string>
using namespace std;

class TreeNode
{
public:
    TreeNode();
	TreeNode(int f_id, string f_author, string f_title, int f_year, int f_quantity);
    ~TreeNode() {};

    int GetBookId() const;
    string GetAuthor() const;
    string GetTitle() const;
	int GetYear() const;
	int GetQuantity() const;

    TreeNode* GetLeft() const;
    TreeNode* GetRight() const;

	void SetBookId(int f_id);
	void SetAuthor(string f_author);
	void SetTitle(string f_author);
	void SetYear(int f_year);
	void SetQuantity(int f_quantity);

    void SetLeft(TreeNode *node);
    void SetRight(TreeNode *node);

    void Print();

private:
    int BookId;
	string Author;
    string Title;
	int Year;
	int Quantity;

    TreeNode* Left;
    TreeNode* Right;
};