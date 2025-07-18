#include <bits/stdc++.h>
using namespace std;
#define int long long

// void solve()
// {
//     int n, q; cin >> n >> q;
//     int x = (n - 1) / 2 + (n - 1) % 2;
//     vector<int> a; a.resize(n);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     while (q--)
//     {
//         int p, v; cin >> p >> v;
//         a[p - 1] += v;
//         int ans = 0;
//         vector<int> b = {a.begin(), a.end()};
//         sort(b.begin(), b.end());
//         int l = 0, r = n;
//         for (int i = 0; i < b.size(); i++)
//         {

//             int j = i;
//             while (j + 1 < b.size() && b[j] == b[j + 1]) j++;
//             if (b.size() - j - 1 >= x) ans += j - i + 1;
//             // cout << b[j] << ' ' << ans << endl;
//             i = j;
//         }
//         cout << ans << endl;
//     }
// }

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int n, m, q;
int a[N];
struct Query{int p, v;} queries[N];
vector<int> all_nums;
int bit[N * 2];

int lowbit(int x) {return x & (-x);}

void add(int x, int v)
{
    while (x <= m)
    {
        bit[x] += v;
        x += lowbit(x);
    }
}

int query(int x)
{
    int s = 0;
    while (x)
    {
        s += bit[x];
        x -= lowbit(x);
    }
    return s;
}

int find(int k)
{
    int pos = 0, sum = 0;
    for (int i = log2(m); i >= 0; i--)
    {
        int next = pos + (1 << i);
        if (next <= m && sum + bit[next] < k)
        {
            sum += bit[next];
            pos = next;
        }
    }
    return pos + 1;
}

void solve()
{
    cin >> n >> q;
    all_nums.clear();

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        all_nums.push_back(a[i]);
    }

    for (int i = 0; i < q; i++) cin >> queries[i].p >> queries[i].v;

    vector<int> temp_a(a + 1, a + n + 1);
    for (int i = 0; i < q; i++)
    {
        auto [p, v] = queries[i];
        temp_a[p - 1] += v;
        all_nums.push_back(temp_a[p - 1]);
    }

    sort(all_nums.begin(), all_nums.end());
    all_nums.erase(unique(all_nums.begin(), all_nums.end()), all_nums.end());
    m = all_nums.size();

    auto get_id = [&](int val) 
    {
        return lower_bound(all_nums.begin(), all_nums.end(), val) - all_nums.begin() + 1;
    };

    for (int i = 1; i <= m; i++) bit[i] = 0;
    for (int i = 1; i <= n; i++) add(get_id(a[i]), 1);

    int t = n - n / 2 + 1;
    for (int i = 0; i < q; i++)
    {
        auto [p, v] = queries[i];
        add(get_id(a[p]), -1);
        a[p] += v;
        add(get_id(a[p]), 1);

        int id = find(t);
        int ans = query(id - 1);
        cout << ans << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
