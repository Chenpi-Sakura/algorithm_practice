/*
[USACO2.4] 两只塔姆沃斯牛 The Tamworth Two
题目描述
两只牛逃跑到了森林里。Farmer John 开始用他的专家技术追捕这两头牛。你的任务是模拟他们的行为（牛和 John）。
追击在 10×10 的平面网格内进行。一个格子可以是：一个障碍物，两头牛（它们总在一起），或者 Farmer John。两头牛和 Farmer John 可以在同一个格子内（当他们相遇时），但是他们都不能进入有障碍的格子。

一个格子可以是：

. 空地；
* 障碍物；
C 两头牛；
F Farmer John。
这里有一个地图的例子：

*...*.....
......*...
...*...*..
..........
...*.F....
*.....*...
...*......
..C......*
...*.*....
.*.*......

牛在地图里以固定的方式游荡。每分钟，它们可以向前移动或是转弯。如果前方无障碍（地图边沿也是障碍），它们会按照原来的方向前进一步。否则它们会用这一分钟顺时针转 90 度。 同时，它们不会离开地图。
Farmer John 深知牛的移动方法，他也这么移动。
每次（每分钟）Farmer John 和两头牛的移动是同时的。如果他们在移动的时候穿过对方，但是没有在同一格相遇，我们不认为他们相遇了。当他们在某分钟末在某格子相遇，那么追捕结束。
读入十行表示地图。每行都只包含 10 个字符，表示的含义和上面所说的相同。保证地图中只有一个 F 和一个 C。F 和 C 一开始不会处于同一个格子中。
计算 Farmer John 需要多少分钟来抓住他的牛，假设牛和 Farmer John 一开始的行动方向都是正北（即上）。 如果 John 和牛永远不会相遇，输出 0。

输入格式
输入共十行，每行 10 个字符，表示如上文描述的地图。

输出格式
输出一个数字，表示 John 需要多少时间才能抓住牛们。如果 John 无法抓住牛，则输出 0。
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 10;
char cfmap[N][N];

int mian()
{
    PII cow, far, dcow, dfar, cowd = {0, 1}, fard = {0, 1};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> cfmap[i][j];
            if (cfmap[i][j] == 'C') cow.first = i, cow.second = j, cfmap[i][j] == '.';
            if (cfmap[i][j] == 'F') far.first = i, far.second = j, cfmap[i][j] == '.';
        }
    }

    dcow.first = cow.first, dcow.second = cow.second;
    dfar.first = far.first, dfar.second = far.second;

    while (cow != far)
    {
        if ()
    }
}
