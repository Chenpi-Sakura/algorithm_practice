/*
发射站
题目描述
某地有 N 个能量发射站排成一行，每个发射站 i 都有不相同的高度 Hi，并能向两（两端的发射站只能向一边）同时发射能量值为 Vi 的能量，发出的能量只被两边最近的且比它高的发射站接收。显然，每个发射站发来的能量有可能被 0 或 1 或 2 个其他发射站所接受。
请计算出接收最多能量的发射站接收的能量是多少。

输入格式
第 1 行一个整数 N。

第 2 到 N+1 行，第 i+1 行有两个整数 Hi 和 Vi，表示第 i 个发射站的高度和发射的能量值。

输出格式
输出仅一行，表示接收最多能量的发射站接收到的能量值。答案不超过 32 位带符号整数的表示范围。

输入数据 1
3
4 2 
3 5 
6 10

输出数据 1
7
*/
/*
    很明显，如果直接找的话，这里明显会超时，所以要运用单调栈来提高查找效率，由于两边都需要，我们降低代码复杂度采取两次换向查询
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int h[N], v[N], ans[N], q[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i] >> v[i];

    int top = 0;
    for (int i = 1; i <= n; i++)
    {
        while (top > 0 && h[q[top]] < h[i])
        {
            ans[i] += v[q[top]];
            top--;
        }
        q[++top] = i;
    }
    
    top = 0;
    for (int i = n; i > 0; i--)
    {
        while (top > 0 && h[q[top]] < h[i])
        {
            ans[i] += v[q[top]];
            top--;
        }
        q[++top] = i;
    }

    int res = ans[0];
    for (int i = 1; i <= n; i++) res = max(res, ans[i]);

    cout << res << endl;
    return 0;
}