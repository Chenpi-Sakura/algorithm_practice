/*
[USACO09DEC] Selfish Grazing S
题目描述
Each of Farmer John's N (1 <= N <= 50,000) cows likes to graze in a certain part of the pasture, which can be thought of as a large one-dimeensional number line. Cow i's favorite grazing range starts at location S_i and ends at location E_i (1 <= S_i < E_i; S_i < E_i <= 100,000,000).

Most folks know the cows are quite selfish; no cow wants to share any of its grazing area with another. Thus, two cows i and j can only graze at the same time if either S_i >= E_j or E_i <= S_j. FJ would like to know the maximum number of cows that can graze at the same time for a given set of cows and their preferences.

Consider a set of 5 cows with ranges shown below:

  ... 1    2    3    4    5    6    7    8    9   10   11   12   13 ...
  ... |----|----|----|----|----|----|----|----|----|----|----|----|----
Cow 1:      <===:===>          :              :              :
Cow 2: <========:==============:==============:=============>:
Cow 3:          :     <====>   :              :              :
Cow 4:          :              :     <========:===>          :
Cow 5:          :              :     <==>     :              :
These ranges represent (2, 4), (1, 12), (4, 5), (7, 10), and (7, 8), respectively.

For a solution, the first, third, and fourth (or fifth) cows can all graze at the same time. If the second cow grazed, no other cows could graze. Also, the fourth and fifth cows cannot graze together, so it is impossible for four or more cows to graze.

约翰有N(1≤N≤50000)头牛，约翰的草地可以认为是一条直线．每只牛只喜欢在某个特定的范围内吃草．第i头牛喜欢在区间(Si，Ei)吃草，1≤Si<Ei≤1,000,000,00.

奶牛们都很自私，他们不喜欢和其他奶牛共享自己喜欢吃草的领域，因此约翰要保证任意

两头牛都不会共享他们喜欢吃草昀领域．如果奶牛i和奶牛J想要同时吃草，那么要满足：Si>=Ej或者Ei≤Sj．约翰想知道在同一时刻，最多可以有多少头奶牛同时吃草？

输入格式
* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains the two space-separated integers: S_i and E_i

输出格式
* Line 1: A single integer representing the maximum number of cows that can graze at once.
*/

#include<bits/stdc++.h> 
using namespace std;

typedef pair<int, int> PII;
const int N = 1e6;
PII cow[N];

bool cmp(PII a, PII b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main( )
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> cow[i].first >> cow[i].second;
    sort(cow, cow + n, cmp);

    int ans = 0, last = 0;
    for (int i = 0; i < n; i++)
    {
        if (cow[i].first >= last)
        {
            ans++; 
            last = cow[i].second;
        }
    }
    
    cout << ans << endl;
    return 0;
}