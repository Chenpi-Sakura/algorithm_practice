#include <bits/stdc++.h>
using namespace std;

const int N = 50;
vector<int> bac, mid;
int tree[N][2];

int findIndex(const vector<int>& a, int target)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] == target) return i;
    return -1;
}

void build(vector<int> b, vector<int> m)
{
    if (b.empty()) return;
    int root = b.back(); b.pop_back();
    int pos = findIndex(m, root);
    tree[root][0] = b[pos - 1];
    tree[root][1] = b.back();
    build({b.begin(), b.begin() + pos - 1}, {m.begin(), m.begin() + pos - 1});
    build({b.begin() + pos, b.end()}, {m.begin() + pos + 1, m.end()});
}

int main()
{
    int n; cin >> n;
    bac.resize(n); mid.resize(n);
    for (int i = 0; i < n; i++) cin >> bac[i];
    for (int i = 0; i < n; i++) cin >> mid[i];
    int root = bac.back();
    build(bac, mid);
    cout << tree[root][0] << ' ' << tree[root][1] << endl;
}