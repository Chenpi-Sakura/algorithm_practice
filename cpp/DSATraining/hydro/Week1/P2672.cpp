/*
题目背景
阿明是一名推销员，他奉命到螺丝街推销他们公司的产品。螺丝街是一条死胡同，出口与入口是同一个，街道的一侧是围墙，另一侧是住户。螺丝街一共有 N 家住户，第 i 家住户到入口的距离为 Si 米。由于同一栋房子里可以有多家住户，所以可能有多家住户与入口的距离相等。阿明会从入口进入，依次向螺丝街的 X 家住户推销产品，然后再原路走出去。
阿明每走 1 米就会积累 1 点疲劳值，向第 i 家住户推销产品会积累 Ai 点疲劳值。阿明是工作狂，他想知道，对于不同的 X，在不走多余的路的前提下，他最多可以积累多少点疲劳值。

输入格式
第一行有一个正整数 N，表示螺丝街住户的数量。
接下来的一行有 N 个正整数，其中第 i 个整数 Si 表示第 i 家住户到入口的距离。数据保证 S1 ≤ S2 ≤ ... ≤ Sn < 10^8。
接下来的一行有 N 个正整数，其中第 i 个整数 Ai 表示向第 i 户住户推销产品会积累的疲劳值。数据保证 Ai < 1000。

输出格式
输出 N 行，每行一个正整数，第 i 行整数表示当 X = i 时，阿明最多积累的疲劳值。

对于 100% 的数据，1≤N≤100000。

动态规划？
动态规划的思路：
设 dp[i][j] 表示在前 i 家住户中，选择 j 个住户，能够得到的最大疲劳值。
状态转移：对于每个 j，我们有两个选择：要么不选择第 i 家住户（即继承 dp[i-1][j]），要么选择第 i 家住户并增加疲劳值（即继承 dp[i-1][j-1] 并加上当前住户的疲劳值）。

繁琐，路程更新难
*/
/*贪心前缀和应该是最佳答案*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;
PII arrdata[N];
int s[N];
int a[N];
int h[N];
int n;

bool cmp(PII a, PII b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arrdata[i].second;
    for (int i = 1; i <= n; i++) cin >> arrdata[i].first;

    sort(arrdata + 1, arrdata + n + 1, cmp);

    for (int i = 1; i <= n; i++) a[i] = a[i - 1] + arrdata[i].first;
    for (int i = 1; i <= n; i++) s[i] = max(s[i - 1], arrdata[i].second);
    for (int i = n; i > 0; i--) h[i] = max(h[i + 1], arrdata[i].first + 2 * arrdata[i].second);

    for (int i = 1; i <= n; i++) cout << max(a[i] + 2 * s[i], a[i - 1] + h[i]) << endl;
    return 0;
}