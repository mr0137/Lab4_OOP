#include "BinTree.h"

BinTree::BinTree()
{
	Root = nullptr;
}

void BinTree::AddNode(TreeNode * node)
{
	if (node == nullptr)
	{
		cout << "node == null" << endl;
		return;
	}

	if (Root == nullptr)
	{
		Root = node;
		return;
	}
	TreeNode* CurrentNode = Root;
	TreeNode* ParentNode;

	while (CurrentNode != nullptr)
	{
		ParentNode = CurrentNode;

		if (node->GetBookId() > CurrentNode->GetBookId())
		{
				CurrentNode = CurrentNode->GetRight();

			if (CurrentNode == nullptr) 
			{
				ParentNode->SetRight(node);

			}
		}
		else if (node->GetBookId() < CurrentNode->GetBookId())
		{
			CurrentNode = CurrentNode->GetLeft();

			if (CurrentNode == nullptr) 
			{
				ParentNode->SetLeft(node);
			}
		}
		else
		{
			if (node->GetBookId() == CurrentNode->GetBookId())
			{
				cout << "Node already exist" << endl;
				return;
			}
			CurrentNode->SetAuthor(node->GetAuthor());
			CurrentNode->SetTitle(node->GetTitle());
			CurrentNode->SetYear(node->GetYear());
			CurrentNode->SetQuantity(node->GetQuantity());
			break;
		}
	}
	
}

int BinTree::RemoveNode(int f_id)
{
	if (Root == nullptr || f_id < 0) 
	{
		return 0;
	}

	TreeNode* Current = Root;
	TreeNode* Parent = Root;
	TreeNode* temp;
	int tempid;

	while (f_id != Current->GetBookId()) 
	{
		Parent = Current;
		if (f_id <= Current->GetBookId()) 
		{
			Current = Current->GetLeft();
		}
		else 
		{
			Current = Current->GetRight();
		}

		if (Current == nullptr) 
		{
			cout << "Element with book id : '" << f_id << "' doesn't exist";
			return 0;
		}
	}

	if (Current->GetLeft() == nullptr && Current->GetRight() == nullptr) 
	{
		if (Current == Root)
		{
			delete[] Root;
			Root = nullptr;
		}
		else if (Parent->GetLeft() == Current)
		{
			delete[] Parent->GetLeft();
			Parent->SetLeft(nullptr);
		}
		else
		{
			delete[] Parent->GetRight();
			Parent->SetRight(nullptr);
		}
	}
	else if (Current->GetLeft() == nullptr)
	{
		TreeNode* temp = Current;
		if (Current == Parent->GetRight()) 
		{
			Parent->SetRight(Current->GetRight());
		}
		else {
			Parent->SetLeft(Current->GetRight());
		}
		delete temp;
	}
	else if (Current->GetRight() == nullptr)
	{
		TreeNode* temp = Current;
		if (Current == Parent->GetRight()) 
		{
			Parent->SetRight(Current->GetLeft());
		}
		else 
		{
			Parent->SetLeft(Current->GetLeft());
		}
		delete[] temp;
	}
	else
	{
		temp = FindNode(Current->GetRight());
		tempid = temp->GetBookId();
		RemoveNode(temp->GetBookId());
		Current->SetBookId(tempid);
	}

	return 1;
}

TreeNode* BinTree::Find(int f_id)
{
	TreeNode* p = Root;
	if (p == nullptr) 
	{
		return nullptr;
	}

	while (p != nullptr)
	{
		if (f_id == p->GetBookId()) 
		{
			return p;
		}
		else if (f_id < p->GetBookId()) 
		{
			p = p->GetLeft();
		}
		else 
		{
			p = p->GetRight();
		}
	}

	return nullptr;
}

TreeNode* BinTree::FindNode(TreeNode *ptr) 
{	
	if (ptr == nullptr)
	{
		return nullptr;
	}
	TreeNode* p = ptr;
	while (p->GetLeft() != nullptr) 
	{
		p = p->GetLeft();
	}
	return p;
}

void BinTree::Print() 
{
	PrintNodes(Root);
}

void BinTree::Print(string f_author) 
{
	PrintNodes(Root, f_author);
}

void BinTree::PrintNodes(TreeNode *ptr)
{
	if (ptr != nullptr)
	{
		PrintNodes(ptr->GetLeft());
		ptr->Print();
		PrintNodes(ptr->GetRight());
	}
}

void BinTree::PrintNodes(TreeNode *ptr, string f_author)
{
	if (ptr != nullptr)
	{
		PrintNodes(ptr->GetLeft(), f_author);
		if (ptr->GetAuthor() == f_author) 
		{
			ptr->Print();
		}
		PrintNodes(ptr->GetRight(), f_author);
	}
}