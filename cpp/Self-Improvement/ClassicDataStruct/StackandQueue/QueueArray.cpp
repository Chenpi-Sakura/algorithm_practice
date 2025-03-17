#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int *arr;
    int capacity;
    int front;
    int rear;

public:
    Queue(int cap) : capacity(cap), front(0), rear(0)
    {
        arr = new int[capacity];
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool in(int n)
    {
        if (rear == capacity)
        {
            return false;
        }
        arr[rear++] = n;
        return true;
    }

    bool out()
    {
        if (front == rear)
        {
            return false;
        }
        front++;
        return true;
    }

    int check(bool isFront)
    {
        if (front == rear)
        {
            throw runtime_error("Queue is empty");
        }
        if (isFront)
            return arr[front];
        else
            return arr[rear - 1];
    }

    int num()
    {
        return rear - front;
    }
};

int main()
{
    Queue q(5); // 创建一个容量为 5 的队列

    // 测试入队操作
    cout << "Adding elements to the queue:" << endl;
    for (int i = 1; i <= 5; i++)
    {
        if (q.in(i))
        {
            cout << "Added " << i << " to the queue." << endl;
        }
        else
        {
            cout << "Queue is full, couldn't add " << i << endl;
        }
    }

    // 查看队列中的元素数量
    cout << "Current number of elements in the queue: " << q.num() << endl;

    // 测试队列头和队列尾元素
    try
    {
        cout << "Front element: " << q.check(true) << endl; // 应该是 1
        cout << "Rear element: " << q.check(false) << endl; // 应该是 5
    }
    catch (const runtime_error &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    // 测试出队操作
    cout << "\nRemoving elements from the queue:" << endl;
    while (q.num() > 0)
    {
        cout << "Removed " << q.check(true) << " from the queue." << endl;
        q.out(); // 每次出队一个元素
    }

    // 测试队列为空时的操作
    cout << "\nIs the queue empty? " << (q.num() == 0 ? "Yes" : "No") << endl;

    // 尝试从空队列中获取元素
    cout << "\nAttempting to get the front and rear of an empty queue:" << endl;
    try
    {
        cout << "Front element: " << q.check(true) << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }

    return 0;
}