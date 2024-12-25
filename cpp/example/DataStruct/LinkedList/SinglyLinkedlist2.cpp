/*单链表 头插法 和 尾插法*/

#include <bits/stdc++.h>
using namespace std;

struct LNode
{
    int data;
    struct LNode *next;
};

LNode *head = NULL;

void HeadInsert(int n)
{
    LNode *Newnode = (LNode *)malloc(sizeof(LNode));
    Newnode->data = n;
    Newnode->next = head;
    head = Newnode;
}

//O(n)法
void LastInsert(int n)
{
    // 创建一个节点
    LNode *Newnode = (LNode *)malloc(sizeof(LNode));
    Newnode->data = n;
    Newnode->next = NULL;

    if (head == NULL)
    {
        head = Newnode;
    }
    else
    {
        LNode *last = head;
        while (last->next != NULL)
        {
            last = last->next; 
        }
        last->next = Newnode;
    }
}

//O(1)法
LNode *tail = NULL;
void TailInsert(int n)
{
    LNode *Newnode = (LNode *)malloc(sizeof(LNode));
    Newnode->data = n;
    Newnode->next = NULL;

    if(head == NULL)
    {
        head = Newnode;
        tail = Newnode;
    }
    else
    {
        tail->next = Newnode;
        tail = Newnode;
    }
}

void PrintList()
{
    LNode *current = head;
    while (current != NULL)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl; // 打印链表结束标志
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        int n;
        cin >> n;
        //HeadInsert(n);
        LastInsert(n);
    }
    PrintList();

    return 0;
}