/*
P1030 [NOIP 2001 普及组] 求先序排列
题目描述
给出一棵二叉树的中序与后序排列。求出它的先序排列。（约定树结点用不同的大写字母表示，且二叉树的节点个数 ≤ 8）。

输入格式
共两行，均为大写字母组成的字符串，表示一棵二叉树的中序与后序排列。

输出格式
共一行一个字符串，表示一棵二叉树的先序。
*/
#include <bits/stdc++.h>
using namespace std;

void solve(string m, string b)
{
    if (b.empty()) return;
    
    char root = b.back();
    int pos = m.find(root);
    b.pop_back();

    cout << root;
    solve(m.substr(0, pos), b.substr(0, pos));
    solve(m.substr(pos + 1), b.substr(pos));
}

int main()
{
    string m, b; cin >> m >> b;
    solve(m, b);

    return 0;
}