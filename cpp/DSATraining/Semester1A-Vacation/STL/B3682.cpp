/*
题目描述
第五人格抽奖宝箱被称为珍宝。某一赛季珍宝池中共有 n 件道具。道具不可以重复获得。因此，第一次抽出某道具，可以将该道具放入仓库。之后抽出该道具，不会将该道具放入仓库，而是给予一定的碎片补偿。
道具共有五种品质，分别为金色、紫色、蓝色、绿色与白色，不同品质道具给予的碎片补偿数量不同，具体数量如下表所示。

品质	碎片补偿数量	品质代号
金色	2000	       1
紫色	1000           2
蓝色	200	           3
绿色    36             4
白色    6	           5
某 E 一共抽了 k 次珍宝。现在告诉你珍宝池和某 E 的抽出道具情况，请问某 E 一共得到了多少碎片。

输入格式
输入共 n+k+1 行。

输入的第一行为两个正整数 n,k，分别代表珍宝池中道具的数量和某 E 抽珍宝次数。
接下来 n 行，每行一个字符串和一个整数，分别代表道具的名称和品质代号。
接下来 k 行，每行一个字符串，代表某 E 抽到的道具的名称。数据保证对应名称的道具在上面的 n 个道具中出现过。

输出格式
输出一行一个整数，代表可以获得的碎片数量。
*/
#include <bits/stdc++.h>
using namespace std;

map<string, pair<int, bool>> Tmap;

int main()
{
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        string name; int code; cin >> name >> code;
        if (code == 1) code = 2000;
        else if (code == 2) code = 1000;
        else if (code == 3) code = 200;
        else if (code == 4) code = 36;
        else code = 6;
        Tmap[name].first = code; Tmap[name].second = true;
    }
    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        string name; cin >> name;
        if (Tmap[name].second) Tmap[name].second = false;
        else ans += Tmap[name].first;
    }
    cout << ans << endl;
    return 0;
}