#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int *arr;
    int capacity;
    int topIndex;

public:
    Stack(int cap) : capacity(cap), topIndex(-1)
    {
        arr = new int[capacity];
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool push(int n)
    {
        if (topIndex >= capacity - 1)
        {
            return false;
        }
        arr[++topIndex] = n;
        return true;
    }

    bool pop()
    {
        if (topIndex == -1)
        {
            return false;
        }
        topIndex--;
        return true;
    }

    int top()
    {
        if (topIndex == -1)
        {
            throw runtime_error("Stack is empty");
        }
        return arr[topIndex];
    }

    int size()
    {
        return topIndex + 1;
    }

    bool empty()
    {
        return topIndex == -1;
    }
};

int main()
{
    Stack s(5); // 创建一个容量为5的栈

    // 测试push操作
    cout << "Pushing elements to the stack:" << endl;
    for (int i = 1; i <= 5; i++)
    {
        if (s.push(i))
        {
            cout << "Pushed " << i << " into the stack." << endl;
        }
        else
        {
            cout << "Failed to push " << i << ", stack overflow!" << endl;
        }
    }

    // 测试栈的大小
    cout << "Current stack size: " << s.size() << endl; // 应该是5

    // 测试top操作
    cout << "Top element: " << s.top() << endl; // 应该是5

    // 测试pop操作
    cout << "\nPopping elements from the stack:" << endl;
    while (!s.empty())
    {
        cout << "Popped " << s.top() << " from the stack." << endl;
        s.pop();
    }

    // 测试栈是否为空
    cout << "\nIs the stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    // 测试栈的溢出
    cout << "\nAttempting to pop from an empty stack:" << endl;
    try
    {
        s.pop();
    }
    catch (const runtime_error &e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }

    // 测试top操作（栈为空时）
    cout << "\nAttempting to get the top element of an empty stack:" << endl;
    try
    {
        cout << "Top element: " << s.top() << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
}