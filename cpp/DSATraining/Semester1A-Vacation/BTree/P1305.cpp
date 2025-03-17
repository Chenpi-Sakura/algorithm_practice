/*
题目描述
输入一串二叉树，输出其前序遍历。

输入格式
第一行为二叉树的节点数 n。(1≤n≤26)
后面 n 行，每一个字母为节点，后两个字母分别为其左右儿子。特别地，数据保证第一行读入的节点必为根节点。
空节点用 * 表示

输出格式
二叉树的前序遍历。
*/

// 数组模拟
#include<bits/stdc++.h> 
using namespace std;

char tree[30][3];
int n;

void preTree(char root)
{
    if (root != '*')
    {
        cout << root;
        for (int i = 0; i < n; i++)
        {
            if (tree[i][0] == root)
            {
                preTree(tree[i][1]);
                preTree(tree[i][2]);
            }
        }
    }
}

int main( )
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i][0] >> tree[i][1] >> tree[i][2];
    }    
    preTree(tree[0][0]);

    return 0;
}

// 结构体模拟，本质思路相同

#include<bits/stdc++.h> 
using namespace std;

struct Triple
{
    char data;
    int le;
    int ri;
};

Triple tree[30];

void preTree(int root)
{
    if (root == 0) return;

    cout << tree[root].data;
    preTree(tree[root].le);
    preTree(tree[root].ri);
}

int main( )
{
    int n; cin >> n;
    int root;
    for (int i = 1; i <= n; i++)
    {
        char a, b, c; cin >> a >> b >> c;
        int index = a - 'a' + 1;
        if (i == 1) root = index;
        tree[index].data = a;
        if (b != '*')
        {
            tree[index].le = b - 'a' + 1;
            tree[b - 'a' + 1].data = b;
        }
        if (c != '*')
        {
            tree[index].ri = c - 'a' + 1;
            tree[c - 'a' + 1].data = c;
        }
    }

    preTree(root);
    return 0;
}