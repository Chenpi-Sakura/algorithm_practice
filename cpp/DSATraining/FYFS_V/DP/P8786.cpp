/*
[蓝桥杯 2022 省 B] 李白打酒加强版
题目描述
话说大诗人李白，一生好饮。幸好他从不开车。
一天，他提着酒壶，从家里出来，酒壶中有酒 2 斗。他边走边唱：
无事街上走，提壶去打酒。
逢店加一倍，遇花喝一斗。
这一路上，他一共遇到店 N 次，遇到花 M 次。已知最后一次遇到的是花，他正好把酒喝光了。

请你计算李白这一路遇到店和花的顺序，有多少种不同的可能?
注意：壶里没酒（0 斗）时遇店是合法的，加倍后还是没酒；但是没酒时遇花是不合法的。

输入格式
第一行包含两个整数 N 和 M。

输出格式
输出一个整数表示答案。由于答案可能很大，输出模 10e9 + 7的结果。
*/

/*
    计数dp
*/

#include<bits/stdc++.h> 
using namespace std;

const int M = 1e9 + 7;
int f[205][105][105];
int n, m;

int main( )
{
    cin >> n >> m;
    f[0][0][2] = 1;
    for (int i = 0; i < n + m; i++)
    { // 第 i 步操作
        for (int j = 0; j < m; j++)
        { // 看了 j 次花
            for (int k = 0; k <= m; k++)
            { // 还有 k 斗酒
                if (f[i][j][k])
                {
                    if (k > 0) f[i + 1][j + 1][k - 1] = (f[i + 1][j + 1][k - 1] + f[i][j][k]) % M;
                    if (k <= 50) f[i + 1][j][k * 2] = (f[i + 1][j][k * 2] + f[i][j][k]) % M;
                }
            }
        }
    }

    cout << f[n + m][m][0] << endl;
    return 0;
}