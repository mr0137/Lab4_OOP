#pragma once
#include "TreeNode.h"

class BinTree
{
private:
    TreeNode* Root;

    TreeNode* FindNode(TreeNode* ptr);

    void PrintNodes(TreeNode *ptr);
    void PrintNodes(TreeNode *, string f_author);
public:
    BinTree();
    ~BinTree() {};

    void AddNode(TreeNode *node);
    int RemoveNode(int f_id);
    void Print();
    void Print(string ptr);
    TreeNode* Find(int f_id);


};