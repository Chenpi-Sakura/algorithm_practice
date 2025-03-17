/*01字典树，目的是异或和最大的计算
其本质是一棵二叉树，深度为31*/
#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N];
int ch[N * 31][2], idx;
/* ch 儿子数组, N * 31 是为了保证所有的数都能被存下 */

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int j = (x >> i) & 1;
        if (ch[p][j] == 0) ch[p][j] == ++idx;
        p = ch[p][j];
    }
}

int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int j = (x >> i) & 1;
        if (ch[p][!j])
        {
            // 该条件涉及异或和的原理，如果对应位相同，结果为0；如果对应位不同，结果为1。
            // 如果当前位是0，我们希望找一个1，这样异或结果为1，
            // 如果当前位是1，我们希望找一个0，这样异或结果为1。
            // 因此，我们选择查询当前相反位是否存在，
            // 如果存在，我们选择该位
            p = ch[p][!j];
            res += 1 << i; // 累加位权
        }
        else
        {   // 如果不存在，我们只能选择当前位
            p = ch[p][j]; // 相应的，该位就能累加
        }
    }
    return res;    
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, query(a[i]));

    cout << ans << endl;
    return 0;
}