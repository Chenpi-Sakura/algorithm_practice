/*
    字符串哈希模板
    
    1.求一个字符串的哈希值相当于求前缀和 
      求一个字符串的子串的哈希值相当于求区间和。 
    
    2.前缀和h[i] = h[i-1] × p + s[i], h[0]=0 
    A       A,                                          h[1]=65 
    AB      A × p^1 + B,                                h[2] = h[1] × p + 66
    ABC     A × p^2 + B x p^1 + C,                      h[3] = h[2] × p + 67
    ABCD    A x p^3 + B × p^2 + C x p^1 + D
    ABCDE   A × p^4 + B × p^3 + C × p^2 + D × p1 + E

    3.区间和 h[l,r] = h[r] - h[l-1] × p^(r - l + 1)
      例如，DE = ABCDE - ABC × p^2 = D × p^1 + E 
      即 h[4,5] = h[5] - h[3] × p^2 
    
    4.计算前缀和，时间复杂度：O(n) 
      查询区间和，时间复杂度：O(1)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
char s[N]; // 注意此处字符从 s[1] 开始

typedef unsigned long long ULL;
const int P = 131;
// p[i] = P^i, h[i] = s[1 ~ i]的hash值
ULL p[N], h[N];

// 预处理 hash 函数的前缀和
void init()
{
    int len = strlen(s);
    p[0] = 1, h[0] = 0;
    for (int i = 1; i <= len; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i];
    }
}

// 计算 s[l ~ r] 的 hash 值
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

bool substr(int l1, int r1, int l2, int r2)
{
    return get(l1, r1) == get(l2, r2);
}   