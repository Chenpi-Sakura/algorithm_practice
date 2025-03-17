/*
村村通
题目描述
某市调查城镇交通状况，得到现有城镇道路统计表。表中列出了每条道路直接连通的城镇。市政府 "村村通工程" 的目标是使全市任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要相互之间可达即可）。请你计算出最少还需要建设多少条道路？

输入格式
输入包含若干组测试数据，每组测试数据的第一行给出两个用空格隔开的正整数，分别是城镇数目 n 和道路数目 m ；随后的 m 行对应 m 条道路，每行给出一对用空格隔开的正整数，分别是该条道路直接相连的两个城镇的编号。简单起见，城镇从 1 到 n 编号。

注意：两个城市间可以有多条道路相通。
在输入数据的最后，为一行一个整数 0，代表测试数据的结尾。

输出格式
对于每组数据，对应一行一个整数。表示最少还需要建设的道路数目。
*/
#include<bits/stdc++.h> 
using namespace std;

const int N = 1e3 + 10;
int fa[N];

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]); // 查找根节点的同时进行路径压缩
}

void unionset(int x, int y) // 合并两个集合
{
    fa[find(x)] = find(y);
}

int main( )
{
    int n; cin >> n;
    while (n)
    {
        int m; cin >> m;
        for (int i = 1; i <= n; i++) fa[i] = i;
        while (m--)
        {
            int x, y; cin >> x >> y;
            unionset(x, y);
        }
        int ans = -1;
        for (int i = 1; i <= n; i++)
        {
            if (fa[i] == i) ans++;
        }
        cout << ans << endl;
        cin >> n;
    }
    return 0;
}
