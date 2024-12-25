/*单链表 删除节点 两点之间插入节点*/

#include <bits/stdc++.h>
using namespace std;

struct LNode
{
    int data;
    struct LNode *next;
};

void TailInsert(LNode **head, LNode **tail, int n)
{
    LNode *Newnode = (LNode *)malloc(sizeof(LNode));
    Newnode->data = n;
    Newnode->next = NULL;

    if (*head == NULL)
    {
        *head = Newnode;
        *tail = Newnode;
    }
    else
    {
        (*tail)->next = Newnode;
        *tail = Newnode;
    }
}

bool DeleteNode(LNode **head, int key)
{
    if (*head == NULL)
    {
        return false;
    }
    LNode *temp;
    // 实现头部删除
    if ((*head)->data == key)
    {
        temp = *head;
        *head = temp->next;
        free(temp);
        return true;
    }
    // 实现除头部以外的删除
    else
    {
        LNode *pos = *head;
        while (pos->next != NULL)
        {
            if (pos->next->data == key)
            {
                temp = pos->next;
                pos->next = pos->next->next;
                free(temp);
                return true;
            }
            else
            {
                pos = pos->next;
            }
        }
        return false;
    }
}

bool Insert(LNode **head, LNode **tail, int n, int t = -1)
{
    LNode *Newnode = (LNode *)malloc(sizeof(LNode));
    if (Newnode == NULL)
    {
        return false; // 内存分配失败
    }
    Newnode->data = n;

    // 如果链表为空，直接初始化头和尾
    if (*head == NULL)
    {
        Newnode->next = NULL;
        *head = Newnode;
        *tail = Newnode;
        return true;
    }

    // 尾部插入
    if (t < 0)
    {
        Newnode->next = NULL;
        (*tail)->next = Newnode;
        *tail = Newnode;
        return true;
    }

    // 头部插入
    if ((*head)->data == t)
    {
        Newnode->next = *head;
        *head = Newnode;
        return true;
    }

    // 中部插入
    LNode *pos = *head;
    while (pos->next != NULL)
    {
        if (pos->next->data == t)
        {
            Newnode->next = pos->next;
            pos->next = Newnode;
            return true;
        }
        pos = pos->next;
    }
    return false;
}
// 搜索实际上与删除，插入相似，在单链表中只能实现线性查找

void PrintList(LNode *head)
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
    LNode *head = NULL;
    LNode *tail = NULL;
    for (int i = 0; i < 5; i++)
    {
        int n;
        cin >> n;
        TailInsert(&head, &tail, n);
    }
    PrintList(head);

    int key;
    cin >> key;
    if (DeleteNode(&head, key))
        PrintList(head);
    else
        cout << "False" << endl;

    int n;
    cin >> n >> key;
    if (Insert(&head, &tail, n, key))
        PrintList(head);
    else
        cout << "False" << endl;

    return 0;
}