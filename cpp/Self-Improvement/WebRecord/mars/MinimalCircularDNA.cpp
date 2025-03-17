/*
问题描述
小C正在研究一种环状的 DNA 结构，它由四种碱基A、C、G、T构成。这种环状结构的特点是可以从任何位置开始读取序列，因此一个长度为 n 的碱基序列可以有 n 种不同的表示方式。小C的任务是从这些表示中找到字典序最小的序列，即该序列的“最小表示”。

例如：碱基序列 ATCA 从不同位置读取可能的表示有 ATCA, TCAA, CAAT, AATC，其中 AATC 是字典序最小的表示。
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> create_vector(string dna)
{
    vector<string> dnalist;
    int len = dna.size();
    string temp = dna;

    for (int i = 0; i < len; i++)
    {
        int lastChar = temp.back();
        temp.pop_back();
        temp.insert(temp.begin(), lastChar);
        dnalist.push_back(temp);
    }

    return dnalist;
}// 创建环状DNA所含有的所有种类字符串，方便后续的比较

string compare(const vector<string> &dnalist)
{
    int min = 0, len = dnalist.size();
    for (int i = 1; i < len; i++)
    {
        if (dnalist[min] > dnalist[i])
        {
            min = i;
        }
    }

    return dnalist[min];
}// 使用依序比较获取字典序最小的字符串

string solution(string dna)
{
    // Please write your code here

    vector<string> dnalist = create_vector(dna);
    return compare(dnalist);
}

int main()
{
    // You can add more test cases here
    cout << (solution("ATCA") == "AATC") << endl;
    cout << (solution("CGAGTC") == "AGTCCG") << endl;
    cout << (solution("TCATGGAGTGCTCCTGGAGGCTGAGTCCATCTCCAGTAG") == "AGGCTGAGTCCATCTCCAGTAGTCATGGAGTGCTCCTGG") << endl;
    return 0;
}