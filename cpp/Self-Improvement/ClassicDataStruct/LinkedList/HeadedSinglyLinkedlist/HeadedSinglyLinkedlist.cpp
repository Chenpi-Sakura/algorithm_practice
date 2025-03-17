#include <bits/stdc++.h>
using namespace std;

struct LNode
{
    int data;
    LNode *next;
};
typedef LNode *LinkList;

void HeadInsert(LinkList head, LinkList &tail, int n)
{
    LNode *NewNode = new LNode;
    NewNode->data = n;
    NewNode->next = head->next;

    head->next = NewNode;
    head->data++;

    if (tail == head)
    {
        tail = NewNode;
    } // 尾指针的维护
}

void TailInsert(LinkList head, LinkList &tail, int n)
{
    LNode *NewNode = new LNode;
    NewNode->data = n;
    NewNode->next = nullptr;

    tail->next = NewNode;
    tail = NewNode;
    head->data++;
}

bool DeleteNode(LinkList head, int t)
{
    LNode *Current = head;
    while (Current->next != nullptr)
    {
        if (Current->next->data == t)
        {
            LNode *temp = Current->next;
            Current->next = Current->next->next;
            delete (temp);
            head->data--;
            return true;
        }
        Current = Current->next;
    }
    return false;
}

void PrintList(LinkList head)
{
    LNode *Current = head->next;
    while (Current != nullptr)
    {
        cout << Current->data << " -> ";
        Current = Current->next;
    }
    cout << "END" << endl;
}

int main()
{
    LinkList head = new LNode;
    LinkList tail = head; // tail的作用不像现在的头指针是一个独立存在的节点，而是表明最后一个节点所在的位置
    head->data = 0;
    head->next = nullptr;

    HeadInsert(head, tail, 10);
    HeadInsert(head, tail, 20);
    HeadInsert(head, tail, 30);
    HeadInsert(head, tail, 40);

    PrintList(head);
    cout << head->data << endl;

    TailInsert(head, tail, 50);
    TailInsert(head, tail, 60);
    TailInsert(head, tail, 70);
    TailInsert(head, tail, 80);

    PrintList(head);
    cout << head->data << endl;

    if (DeleteNode(head, 80))
    {
        cout << "Success!" << endl;
    }
    else
    {
        cout << "Fail!" << endl;
    }
    if (DeleteNode(head, 40))
    {
        cout << "Success!" << endl;
    }
    else
    {
        cout << "Fail!" << endl;
    }
    if (DeleteNode(head, 90))
    {
        cout << "Success!" << endl;
    }
    else
    {
        cout << "Fail!" << endl;
    }
    if (DeleteNode(head, 80))
    {
        cout << "Success!" << endl;
    }
    else
    {
        cout << "Fail!" << endl;
    }

    PrintList(head);
    cout << head->data << endl;

    return 0;
}