/*
28. 找出字符串中第一个匹配项的下标

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

示例 1：

输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
示例 2：

输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 
提示：

1 <= haystack.length, needle.length <= 104
haystack 和 needle 仅由小写英文字符组成
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = -1;
        next[0] = j; // 初始化
        for (int i = 1; i < s.size(); i++)
        {
            while (j >= 0 && s[i] != s[j + 1]) j = next[j]; // 前后缀不相同，向前回退
            if (s[i] == s[j + 1]) j++; // 前后缀相同，j进位
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) 
    {
        if (needle.size() == 0) return 0;
        vector<int> next(needle.size());
        getNext(&next[0], needle);
        int j = -1, len = haystack.size(); // next数组里记录的起始位置为-1
        for (int i = 0; i < len; i++)
        {
            while (j >= 0 && haystack[i] != needle[j + 1]) j = next[j];
            if (haystack[i] == needle[j + 1]) j++;
            if (j == (needle.size() - 1)) return (i - needle.size() + 1);
        }
        return -1; // 将return -1放在函数内部并闭合函数
    }
};
