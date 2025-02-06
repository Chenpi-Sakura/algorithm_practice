/*
6-5 删除输入字符串中重复次数排在前k的字符
任意输入一个长度不超过1000的字符串(字符不限于字母范围)，然后删除字符串中重复率排在前k的字符（若有不同字符重复次数相同，则ASCII小的字符的重复次数排在前面），其中0≤k，若k值大于等于字符串中重复率排在最后的位置时，则删除全部字符。

函数接口定义：
void delchar(char data[],int k);

输入样例1：
abc!A@#!BBB@#abc!A!@abc
3
输出样例1：
abcA##abcAabc
输入样例2：
cccaaabbbd
2
输出样例2：
cccd
输入样例3：
cccaaabbbd
4
输出样例3：

*/

#include <stdio.h>
#define N 1001
void delchar(char data[], int k)
{
    int len;
    for (len = 0; data[len] != '\0'; len++)
        ;
    // 统计字符个数
    int count[256] = {0};
    for (int i = 0; i < len; i++)
    {
        count[(unsigned int)data[i]]++;
    }

    // 结构体以方便统计
    struct CharFeq
    {
        char ch;
        int fe;
    } cf[256];

    int uniqueChar = 0;
    for (int i = 0; i < 256; i++)
    {
        if (count[i] > 0)
        {
            cf[uniqueChar].ch = i;
            cf[uniqueChar].fe = count[i];
            uniqueChar++;
        }
    }

    if (k >= uniqueChar)
    {
        data[0] = '\0';
        return 0;
    }
    // // 写入结构体
    // for (int i = 0; i < 256; i++)
    // {
    //     cf[i].ch = (char)i;
    //     cf[i].fe = count[i];
    // }

    // // 不同字符的个数
    // int total;
    // for (total = 0; cf[total].fe != 0; total++);
    // if (k > total)
    // {
    //     data[0] = '\0';
    // }

    // 排序
    for (int i = 0; i < uniqueChar; i++)
    {
        for (int j = 0; j < 255 - i; j++)
        {
            if (cf[j].fe < cf[j + 1].fe || (cf[j].fe == cf[j + 1].fe && cf[j].ch > cf[j + 1].ch))
            {
                struct CharFeq temp;
                temp = cf[j];
                cf[j] = cf[j + 1];
                cf[j + 1] = temp;
            }
        }
    }

    // for (int i = 0; data[i] != '\0'; i++)
    // {
    //     for (int j = 0; j < k; j++)
    //     {
    //         if (data[i] == cf[j].ch)
    //         {
    //             int pos = i;
    //             for (int k = i; data[k] != '\0'; k++)
    //             {
    //                 if (data[k] != cf[j].ch)
    //                 {
    //                     data[pos++] = data[k];
    //                 }
    //             }
    //             data[pos] = '\0';
    //             break;
    //         }
    //     }
    // }
    // 找出需要删除的字符
    int deleteFlags[256] = {0};
    for (int i = 0; i < k; i++)
    {
        deleteFlags[(unsigned char)cf[i].ch] = 1;
    }

    // 删除字符串中需要删除的字符
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if (!deleteFlags[(unsigned char)data[i]])
        {
            data[index++] = data[i];
        }
    }
    data[index] = '\0'; // 结束符
}

int main(void)
{
    int k;
    char data[N] = {'\0'};
    gets(data);
    scanf("%d", &k);

    delchar(data, k); // 删除data数组中，字符重复率排在前k的字符

    printf("%s", data);
    return 0;
}