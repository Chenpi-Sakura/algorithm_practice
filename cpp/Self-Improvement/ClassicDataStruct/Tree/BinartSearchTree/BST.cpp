#include <bits/stdc++.h>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *lchild;
    BSTNode *rchild;
};
typedef BSTNode *BSTree;

void insert(BSTree &Tree, int n)
{
    if (Tree == nullptr)
    {
        BSTNode *NewNode = new BSTNode;
        NewNode->data = n;
        NewNode->lchild = nullptr;
        NewNode->rchild = nullptr;
        Tree = NewNode;
    }
    else
    {
        if (n < Tree->data)
        {
            insert(Tree->lchild, n);
        }
        else
        {
            insert(Tree->rchild, n);
        }
    }
}

BSTree rsearch(BSTree TreeNode, int t)
{
    if (TreeNode == nullptr)
    {
        return nullptr;
    }

    if (TreeNode->data < t)
    {
        rsearch(TreeNode->lchild, t);
    }
    else if (TreeNode->data > t)
    {
        rsearch(TreeNode->rchild, t);
    }
    else if (TreeNode->data == t)
    {
        return TreeNode;
    }
    return nullptr;
}

BSTree isearch(BSTree TreeNode, int t)
{
    BSTNode *current = TreeNode;
    while (current != nullptr)
    {
        if (current->data < t)
            current = current->lchild;
        else if (current->data > t)
        {
            current = current->rchild;
        }
        else if (current->data == t)
        {
            return current;
        }
    }
    return current;
}

BSTree deleteNode(BSTree TreeNode, int t)
{
    if (TreeNode == nullptr)
    {
        return nullptr;
    }
    if (TreeNode->data < t)
    {
        TreeNode->lchild = deleteNode(TreeNode->lchild, t);
        return TreeNode;
    }
    else if (TreeNode->data > t)
    {
        TreeNode->rchild = deleteNode(TreeNode->rchild, t);
        return TreeNode;
    }
    else
    {
        if (TreeNode->lchild == nullptr && TreeNode->rchild == nullptr)
        {
            delete TreeNode;
            return nullptr;
        }
        else if (TreeNode->lchild != nullptr && TreeNode->rchild == nullptr)
        {
            BSTNode *temp = TreeNode->lchild;
            delete TreeNode;
            return temp;
        }
        else if (TreeNode->lchild == nullptr && TreeNode->rchild != nullptr)
        {
            BSTNode *temp = TreeNode->rchild;
            delete TreeNode;
            return temp;
        }
        else
        {
            BSTNode *curr = TreeNode->lchild;
            BSTNode *temp = TreeNode->lchild;
            while (curr->rchild != nullptr)
            {
                curr = curr->rchild;
            } // 此时curr指向左子树最大的节点
            curr->rchild = TreeNode->rchild;
            delete TreeNode;
            return temp;
        }
    }
}

void midTree(BSTree TreeNode)
{
    if (TreeNode == nullptr)
    {
        return;
    }
    else
    {
        midTree(TreeNode->lchild);
        cout << TreeNode->data << " ";
        midTree(TreeNode->rchild);
    }
}

int getHeight(BSTree TreeNode)
{
    if (TreeNode == nullptr)
    {
        return 0;
    }
    else 
    {
        int lHeight = getHeight(TreeNode->lchild);
        int rHeight = getHeight(TreeNode->rchild);
        int height = lHeight > rHeight ? lHeight : rHeight;
        return height + 1;
    }
}

int main()
{
    BSTree Tree = nullptr;

    while (true)
    {
        cout << "\n=======================\n";
        cout << "请选择操作：\n";
        cout << "1. 插入节点\n";
        cout << "2. 查找节点 (递归)\n";
        cout << "3. 查找节点 (迭代)\n";
        cout << "4. 删除节点\n";
        cout << "5. 中序遍历树\n";
        cout << "6. 获取树高度\n";
        cout << "7. 退出程序\n";
        cout << "请输入你的选择：";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "请输入要插入的值：";
            int value;
            cin >> value;
            insert(Tree, value);
            cout << "节点 " << value << " 已成功插入！\n";
        }
        else if (choice == 2)
        {
            cout << "请输入要查找的值：";
            int value;
            cin >> value;
            BSTree result = rsearch(Tree, value);
            if (result)
                cout << "节点 " << value << " 存在！\n";
            else
                cout << "节点 " << value << " 不存在！\n";
        }
        else if (choice == 3)
        {
            cout << "请输入要查找的值：";
            int value;
            cin >> value;
            BSTree result = isearch(Tree, value);
            if (result)
                cout << "节点 " << value << " 存在！\n";
            else
                cout << "节点 " << value << " 不存在！\n";
        }
        else if (choice == 4)
        {
            cout << "请输入要删除的值：";
            int value;
            cin >> value;
            Tree = deleteNode(Tree, value);
            cout << "节点 " << value << " 已尝试删除！\n";
        }
        else if (choice == 5)
        {
            cout << "树的中序遍历结果：";
            midTree(Tree);
            cout << "\n";
        }
        else if (choice == 6)
        {
            cout << "树的高度：" << getHeight(Tree) << endl;
        }
        else if (choice == 7)
        {
            cout << "退出程序！\n";
            break;
        }
        else
        {
            cout << "无效选择，请重新输入！\n";
        }
    }

    return 0;
}