/*
P1064 [NOIP 2006 提高组] 金明的预算方案

题目描述
金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间金明自己专用的很宽敞的房间。更让他高兴的是，妈妈昨天对他说：“你的房间需要购买哪些物品，怎么布置，你说了算，只要不超过 n 元钱就行”。今天一早，金明就开始做预算了，他把想买的物品分为两类：主件与附件，附件是从属于某个主件的，下表就是一些主件与附件的例子：

主件	附件
电脑	打印机，扫描仪
书柜	图书
书桌	台灯，文具
工作椅	无

如果要买归类为附件的物品，必须先买该附件所属的主件。每个主件可以有 0 个、1 个或 2 个附件。每个附件对应一个主件，附件不再有从属于自己的附件。金明想买的东西很多，肯定会超过妈妈限定的 n 元。于是，他把每件物品规定了一个重要度，分为 5 等：用整数 1 到 5 表示，第 5 等最重要。他还从因特网上查到了每件物品的价格（都是 10 元的整数倍）。他希望在不超过 n 元的前提下，使每件物品的价格与重要度的乘积的总和最大。   

设第 j 件物品的价格为 vj，重要度为 wj，共选中了 k 件物品，编号依次为 j1,j2,...,jk，则所求的总和为：
vj1 * wj1 + vj2 * wj2 + ... + vjk * wjk   
请你帮助金明设计一个满足要求的购物单。

输入格式
第一行有两个整数，分别表示总钱数 n 和希望购买的物品个数 m。
第 2 到第 (m + 1) 行，每行三个整数，第 (i + 1) 行的整数 vi，pi，qi 分别表示第 i 件物品的价格、重要度以及它对应的的主件。如果 qi=0，表示该物品本身是主件。

输出格式
输出一行一个整数表示答案。

输入输出样例 #1   

输入 #1
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0

输出 #1
2200

说明/提示
数据规模与约定
对于全部的测试点，
保证 1 <= n <= 3.2 * 10^4，1 <= m <= 60，0 <= vi <= 10^4，1 <= pi <= 5，0 <= qi <= m，答案不超过 2 * 10^5。
*/

/*
    分组背包dp：在01背包的基础上增加了依赖关系
*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 3.2e4 + 5, M = 65; 
int v[M][3], p[M][3], f[N];
int n, m;

int cost2(int x, int y)
{
    return v[x][0] + v[x][y];
}

int cost3(int x)
{
    return v[x][0] + v[x][1] + v[x][2];
}

int calc(int x, int y)
{
    return v[x][y] * p[x][y];
}

int main( )
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int w, o, q; cin >> w >> o >> q;
        if (!q)
        {
            v[i][0] = w;
            p[i][0] = o;
        }
        else
        {
            if (v[q][1] == 0)
            {
                v[q][1] = w;
                p[q][1] = o;
            }
            else
            {
                v[q][2] = w;
                p[q][2] = o;
            }
        }
    }

    for (int i = 1; i <= m; i++)
    { // 物品 i
        for (int j = n; j >= 1; j--)
        { // 时间 j
            if (j >= v[i][0]) 
                f[j] = max(f[j], f[j - v[i][0]] + calc(i, 0));
            if (j >= cost2(i, 1)) 
                f[j] = max(f[j], f[j - cost2(i, 1)] + calc(i, 0) + calc(i, 1));
            if (j >= cost2(i, 2)) 
                f[j] = max(f[j], f[j - cost2(i, 2)] + calc(i, 0) + calc(i, 2));
            if (j >= cost3(i)) 
                f[j] = max(f[j], f[j - cost3(i)] + calc(i, 0) + calc(i, 1) + calc(i, 2));
        }
    }

    cout << f[n] << endl;
    return 0;
}