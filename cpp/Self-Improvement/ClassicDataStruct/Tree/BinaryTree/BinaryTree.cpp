#include <bits/stdc++.h>
using namespace std;

struct BiTNode
{
    int data;
    BiTNode *lchild;
    BiTNode *rchild;
};
typedef BiTNode *BiTree;

// 先序遍历  顺序：中 左 右
void preTree(BiTree treeNode)
{
    if (treeNode == nullptr)
        return;
    else
    {
        cout << treeNode->data << " ";
        preTree(treeNode->lchild);
        preTree(treeNode->rchild);
    }
}

// 中序遍历  顺序：左 中 右
void midTree(BiTree treeNode)
{       
    if (treeNode == nullptr)
        return;
    else
    {
        midTree(treeNode->lchild);
        cout << treeNode->data << " ";
        midTree(treeNode->rchild);
    }
}

// 后序遍历  顺序：左 右 中
void posTree(BiTree treeNode)
{
    if (treeNode == nullptr)
        return;
    else
    {
        posTree(treeNode->lchild);
        posTree(treeNode->rchild);
        cout << treeNode->data << " ";
    }
}

void creatTree(BiTree &treeNode)
{
    int n;
    cin >> n;
    if (n == 0)
    { // n为0时，说明当前位置为空
        treeNode = nullptr;
    }
    else
    { // n不为0，创建新的节点，按照先序的顺序创建
        BiTNode *NewNode = new BiTNode;
        NewNode->data = n;
        treeNode = NewNode;
        creatTree(treeNode->lchild);
        creatTree(treeNode->rchild);
    }
}

int main()
{
    BiTree Tree = nullptr;
    creatTree(Tree);
    cout << "先序遍历：";
    preTree(Tree);
    cout << "中序遍历：";
    midTree(Tree);
    cout << "后序遍历：";
    posTree(Tree);
    return 0;
}