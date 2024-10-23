/*
DNA序列编辑距离
问题描述
小R正在研究DNA序列，他需要一个函数来计算将一个受损DNA序列（dna1）转换成一个未受损序列（dna2）所需的最少编辑步骤。编辑步骤包括：增加一个碱基、删除一个碱基或替换一个碱基。

测试样例
样例1：

输入：dna1 = "AGT",dna2 = "AGCT"
输出：1

样例2：

输入：dna1 = "AACCGGTT",dna2 = "AACCTTGG"
输出：4

样例3：

输入：dna1 = "ACGT",dna2 = "TGC"
输出：3

样例4：

输入：dna1 = "A",dna2 = "T"
输出：1

样例5：

输入：dna1 = "GGGG",dna2 = "TTTT"
输出：4
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string dna1, string dna2)
{
    int m = dna1.size();
    int n = dna2.size();

    // 创建一个二维数组来存储编辑距离
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // 初始化边界条件
    for (int i = 0; i <= m; ++i)
    {
        dp[i][0] = i; // 从 dna1 到空字符串的距离
    }
    for (int j = 0; j <= n; ++j)
    {
        dp[0][j] = j; // 从空字符串到 dna2 的距离
    }

    // 填充 dp 数组
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dna1[i - 1] == dna2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1]; // 字符相同，不需要额外操作
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j] + 1,       // 删除
                                dp[i][j - 1] + 1,       // 插入
                                dp[i - 1][j - 1] + 1}); // 替换
            }
        }
    }

    return dp[m][n]; // 返回 dna1 转换为 dna2 的最小编辑距离
}

int main()
{
    cout << (solution("AGT", "AGCT") == 1) << endl;
    cout << (solution("AACCGGTT", "AACCTTGG") == 4) << endl;
    cout << (solution("ACGT", "TGC") == 3) << endl;
    cout << (solution("A", "T") == 1) << endl;
    cout << (solution("GGGG", "TTTT") == 4) << endl;

    return 0;
}
// 动态规划，看不懂