/*
7-10 最长最短单词

输入1行句子（不多于200个单词，每个单词长度不超过100），只包含字母、空格和逗号。单词由至少一个连续的字母构成，空格和逗号都是单词间的间隔。

试输出第1个最长的单词和第1个最短单词。

提示
如果所有单词长度相同，那么第一个单词既是最长单词也是最短单词。

输入格式:
一行句子。

输出格式:
两行输出：
第1行，第一个最长的单词。
第2行，第一个最短的单词。

输入样例:
在这里给出一组输入。例如：

I am studying Programming language C in Peking University
输出样例:
在这里给出相应的输出。例如：

Programming
I
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char line[1001];
    fgets(line, sizeof(line), stdin);

    line[strcspn(line, "\n")] = '\0';

    const char *delimiters = " ,";

    char *word = strtok(line, delimiters);

    char *firstLongest = NULL, *firstShortest = NULL;
    int maxLength = -1, minLength = 101;

    while (word != NULL)
    {
        int length = strlen(word);
        if (length > maxLength)
        {
            maxLength = length;
            firstLongest = word;
        }

        if (length < minLength)
        {
            minLength = length;
            firstShortest = word;
        }

        word = strtok(NULL, delimiters);
    }

    printf("%s\n", firstLongest);
    printf("%s\n", firstShortest);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 输入
    string s;
    getline(cin, s);

    // 创建输入流以及创造单词库
    stringstream ss(s);
    string word;
    vector<string> words;

    // 输入单词库
    while (ss >> word)
    {
        words.push_back(word);
    }

    // 创建最短与最长
    string shortest = words[0], longest = words[0];

    for (string &w : words)
    {
        if (w.size() < shortest.size())
        {
            shortest = w;
        }
        if (w.size() > longest.size())
        {
            longest = w;
        }
    }

    cout << shortest << endl;
    cout << longest << endl;

    return 0;
}