#include <bits/stdc++.h>
using namespace std;

class ArrTree
{
private:
    vector<int> tree;

public:
    ArrTree(int size)
    {
        tree.resize(size, -1); // 这里的 -1 表示空节点
    }

    const vector<int> &getTree() const
    {
        return tree;
    } // 提供访问接口

    void insert(int index, int value)
    {
        if (index >= 0 && index < tree.size())
        {
            tree[index] = value;
        }
    }

    int leftchild(int index)
    {
        int left = 2 * index + 1;
        if (left < tree.size())
            return left;
        return -1;
    }

    int rightchild(int index)
    {
        int right = 2 * index + 2;
        if (right < tree.size())
            return right;
        return -1;
    }

    int parent(int index)
    {
        if (index > 0 && index < tree.size())
            return (index - 1) / 2;
        return -1;
    }

    void printTree()
    {
        int n = tree.size();
        int levelStart = 0;
        int levelEnd = 1;

        while (levelStart < n)
        {
            for (int i = levelStart; i < min(levelEnd, n); i++)
            {
                cout << tree[i] << " ";
            }
            cout << endl;
            levelStart = levelEnd;
            levelEnd = levelEnd * 2 + 1;
        }
    }
};

int main()
{
    // 创建一个大小为 7 的完全二叉树
    ArrTree tree(7);

    // 插入一些节点
    tree.insert(0, 10); // 根节点
    tree.insert(1, 20); // 左子节点
    tree.insert(2, 30); // 右子节点
    tree.insert(3, 40); // 左子节点的左子节点
    tree.insert(4, 50); // 左子节点的右子节点
    tree.insert(5, 60); // 右子节点的左子节点

    // 打印树的结构
    cout << "Tree Structure (Level Order):" << endl;
    tree.printTree();

    // 获取并打印某些节点的子节点和父节点
    int parentIndex = tree.parent(1);
    const vector<int> &treeData = tree.getTree(); // 通过 getTree() 获取树的数据
    cout << "Parent of node " << 1 << " (value " << treeData[1] << "): ";
    if (treeData[parentIndex] != -1)
    {
        cout << "Index: " << parentIndex << ", Value: " << treeData[parentIndex] << endl;
    }
    else
    {
        cout << "No parent (root node)" << endl;
    }

    int leftIndex = tree.leftchild(0);
    cout << "Left child of node 0 (value " << treeData[0] << "): ";
    if (treeData[leftIndex] != -1)
    {
        cout << "Index: " << leftIndex << ", Value: " << treeData[leftIndex] << endl;
    }
    else
    {
        cout << "No left child" << endl;
    }

    int rightIndex = tree.rightchild(2);
    cout << "Right child of node 2 (value " << treeData[2] << "): ";
    if (treeData[rightIndex] != -1)
    {
        cout << "Index: " << rightIndex << ", Value: " << treeData[rightIndex] << endl;
    }
    else
    {
        cout << "No right child" << endl;
    }

    return 0;

    return 0;
}
