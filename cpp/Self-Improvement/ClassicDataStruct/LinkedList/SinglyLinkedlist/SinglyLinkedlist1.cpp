/*定义了一个简单的单链表结构，然后遍历并输出链表中每个节点的数据。*/

#include <bits/stdc++.h>
using namespace std;

struct LNode
{
    int data;
    struct LNode *next;
};

int main()
{
    LNode *head = (LNode *)malloc(sizeof(LNode));
    LNode *body = (LNode *)malloc(sizeof(LNode));
    LNode *tail = (LNode *)malloc(sizeof(LNode));

    head->data = 100;
    head->next = body;

    body->data = 141;
    body->next = tail;

    tail->data = 111;
    tail->next = NULL;

    LNode *current = head; // 从头节点开始
    while (current != NULL)
    {
        cout << current->data << " -> "; // 打印当前节点的值
        current = current->next;         // 移动到下一个节点
    }

    // 释放链表占用的内存
    free(head);
    free(body);
    free(tail);

    return 0;
}