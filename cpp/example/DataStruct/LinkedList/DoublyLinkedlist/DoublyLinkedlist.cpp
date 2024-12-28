#include <bits/stdc++.h>
using namespace std;

struct DNode
{
    DNode *prior;
    int data;
    DNode *next;
};
typedef DNode *LinkList;

void HeadInsert(LinkList head, LinkList &tail, int n)
{
    DNode *NewNode = new DNode;
    NewNode->data = n;
    NewNode->next = head->next;
    NewNode->prior = head;

    if (tail == head)
        tail = NewNode;
    else
        head->next->prior = NewNode;
    head->next = NewNode;

    head->data++;
}

void TailInsert(LinkList head, LinkList &tail, int n)
{
    DNode *NewNode = new DNode;
    NewNode->data = n;
    NewNode->next = nullptr;
    NewNode->prior = tail;

    tail->next = NewNode; // 维护旧尾指针

    tail = NewNode;
    head->data++;
}

bool DeleteNode(LinkList head, LinkList &tail, int n)
{
    DNode *Current = head;

    while (Current->next != nullptr)
    {
        if (Current->next->data == n)
        {
            DNode *temp = Current->next;
            Current->next = temp->next;

            if (tail != temp)
            {
                temp->next->prior = Current;
            }
            else
            {
                tail = Current;
            }

            head->data--;
            delete temp;
            return true;
        }
        Current = Current->next;
    }
    return false;
}

void PrintList(LinkList head, LinkList tail, bool isPositive = true)
{
    if (isPositive)
    {
        DNode *Current = head->next;
        while (Current != nullptr)
        {
            cout << Current->data << "->";
            Current = Current->next;
        }
        cout << "END" << endl;
    }
    else
    {
        DNode *Current = tail;
        while (Current != head)
        {
            cout << Current->data << "<-";
            Current = Current->prior;
        }
        cout << "HEAD" << endl;
    }
}

int main()
{
    LinkList head = new DNode;
    head->prior = nullptr;
    head->data = 0;
    head->next = nullptr;
    LinkList tail = head;

    // 测试功能
    while (true)
    {
        cout << "\n选择操作: \n";
        cout << "1. 头插法插入节点\n";
        cout << "2. 尾插法插入节点\n";
        cout << "3. 删除节点\n";
        cout << "4. 正序打印链表\n";
        cout << "5. 逆序打印链表\n";
        cout << "6. 退出程序\n";
        cout << "输入你的选择：";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "输入要插入的节点值：";
            int value;
            cin >> value;
            HeadInsert(head, tail, value);
            cout << "节点 " << value << " 已头插成功！" << endl;
        }
        else if (choice == 2)
        {
            cout << "输入要插入的节点值：";
            int value;
            cin >> value;
            TailInsert(head, tail, value);
            cout << "节点 " << value << " 已尾插成功！" << endl;
        }
        else if (choice == 3)
        {
            cout << "输入要删除的节点值：";
            int value;
            cin >> value;
            if (DeleteNode(head, tail, value))
            {
                cout << "节点 " << value << " 已删除成功！" << endl;
            }
            else
            {
                cout << "节点 " << value << " 不存在！" << endl;
            }
        }
        else if (choice == 4)
        {
            cout << "正序链表内容：";
            PrintList(head, tail, true);
        }
        else if (choice == 5)
        {
            cout << "逆序链表内容：";
            PrintList(head, tail, false);
        }
        else if (choice == 6)
        {
            cout << "退出程序。" << endl;
            break;
        }
        else
        {
            cout << "无效选择，请重新输入！" << endl;
        }

        cout << "当前链表长度：" << head->data << endl;
    }

    return 0;
}