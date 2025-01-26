/*
P1996 约瑟夫问题

题目描述 n 个人围成一圈，从第一个人开始报数,数到 m 的人出列，再由下一个人重新从 1 开始报数，数到 m 的人再出圈，依次类推，直到所有的人都出圈，请输出依次出圈人的编号。

输入格式
输入两个整数 n,m。

输出格式
输出一行 n 个整数，按顺序输出每个出圈人的编号。
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
typedef Node *Hnode;

void addNode(Hnode &tail, int n)
{
    Node *NewNode = new Node;
    NewNode->data = n;
    NewNode->next = nullptr;
    tail->next = NewNode;
    tail = NewNode;
}

void deleteNode(Hnode &curr)
{
    if (curr->next == curr)
    {
        curr = nullptr;
        return;
    }
    Node *temp = curr->next;
    curr->next = temp->next;
    delete (temp);
}

int main()
{
    int n, m;
    cin >> n >> m;

    Hnode head = new Node;
    head->next = nullptr;
    Hnode tail = head;
    for (int i = 1; i <= n; i++)
    {
        addNode(tail, i);
    }
    tail->next = head->next; // 头尾相接
    Hnode curr = head->next;

    // cout << curr->data << endl;

    int index = 1;
    while (curr != nullptr)
    {
        if (index + 1 == m)
        {
            cout << curr->next->data << " ";
            deleteNode(curr);
            index = 0;
        }
        if (curr != nullptr)
            curr = curr->next;
        index++;
    }

    return 0;
}

#include<bits/stdc++.h> 
using namespace std;

vector<int> a;

int main( )
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) a.push_back(i);
    int t = 0, p = 0;
    while (!a.empty())
    {
        if(p >= a.size()) p = 0;
        if (t + 1 == m)
        {
            cout << a[p] << " ";
            a.erase(a.begin() + p);
            t = 0;
        }
        else 
        {
            p++;
            t++;
        }
    }
    return 0;
}