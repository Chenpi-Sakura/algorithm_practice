/*
# 【模板】KMP

## 题目描述

给出两个字符串 s1 和 s2，若 s1 的区间 [l, r] 子串与 s2 完全相同，则称 s2 在 s1 中出现了，其出现位置为 $l$。  
现在请你求出 s2 在 s1 中所有出现的位置。

定义一个字符串 s 的 border 为 s 的一个**非 s 本身**的子串 t，满足 t 既是 s 的前缀，又是 s 的后缀。  
对于 s2，你还需要求出对于其每个前缀 s' 的最长 border t' 的长度。

## 输入格式

第一行为一个字符串，即为 s1。  
第二行为一个字符串，即为 s2。

## 输出格式

首先输出若干行，每行一个整数，**按从小到大的顺序**输出 s2 在 s1 中出现的位置。  
最后一行输出 |s2| 个整数，第 i 个整数表示 s2 的长度为 $i$ 的前缀的最长 border 长度。
*/
#include<bits/stdc++.h> 
using namespace std;

const int N = 1e7;
string s1, s2;
int Next[N];

void getNext(int len)
{
    int j = -1; Next[0] = j;
    for (int i = 1; i < len; i++)
    {
        while (j >= 0 && s2[i] != s2[j + 1]) j = Next[j];
        if (s2[i] == s2[j + 1]) j++;
        Next[i] = j;
    }
}

void findSub(int len1, int len2)
{
    int j = -1;
    for (int i = 0; i < len1; i++)
    {
        while (j >= 0 && s1[i] != s2[j + 1]) j = Next[j];
        if (s1[i] == s2[j + 1]) j++;
        if (j + 1 == len2)
        {
            cout << i - len2 + 2 << endl;
            j = Next[j]; // 此处直接回溯，确保了效率
        }
    }
}

int main( )
{
    cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size();
    
    getNext(len2);
    findSub(len1, len2);
    for (int i = 0; i < len2; i++) cout << Next[i] + 1 << " ";
    return 0;
}