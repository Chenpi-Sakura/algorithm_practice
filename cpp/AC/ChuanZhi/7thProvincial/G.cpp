#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 3e5 + 5;
const int D = 30; // max bits for 10^9
const int INF = 4e18; // A large enough infinity

struct Basis
{
    int b[D + 1], c[D + 1];

    Basis()
    {
        for (int i = 0; i <= D; ++i)
        {
            b[i] = 0;
            c[i] = INF;
        }
    }

    void insert(int v, int w)
    {
        for (int i = D; i >= 0; i--)
        {
            if (!(v >> i & 1)) continue;
            if (!b[i])
            {
                b[i] = v;
                c[i] = w;
                return;
            }
            if (w < c[i])
            {
                swap(v, b[i]);
                swap(w, c[i]);
            }
            v ^= b[i];
        }
    }

    int get_min_cost()
    {
        int res = INF;
        for (int i = 0; i <= D; i++)
        {
            if (b[i]) res = min(res, c[i]);
        }
        return res;
    }
};

struct Node
{
    int v_xor;
    int w_sum;
    Basis basis;
} tree[N * 4];

int V[N], W[N];

Node merge(const Node& a, const Node& b)
{
    Node res;
    res.v_xor = a.v_xor ^ b.v_xor;
    res.w_sum = a.w_sum + b.w_sum;
    res.basis = a.basis;
    for (int i = 0; i <= D; i++)
    {
        if (b.b[i])
        {
            res.basis.insert(b.b[i], b.c[i]);
        }
    }
    return res;
}

void pushup(int u)
{
    tree[u] = merge(tree[u << 1], tree[u << 1 | 1]);
}

void build(int u, int l, int r)
{
    if (l == r)
    {
        tree[u].v_xor = V[l];
        tree[u].w_sum = W[l];
        tree[u].basis = Basis();
        if (V[l] != 0)
        {
            tree[u].basis.insert(V[l], W[l]);
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void update(int u, int l, int r, int pos, int v, int w)
{
    if (l == r)
    {
        tree[u].v_xor = v;
        tree[u].w_sum = w;
        tree[u].basis = Basis();
        if (v != 0)
        {
            tree[u].basis.insert(v, w);
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
    {
        update(u << 1, l, mid, pos, v, w);
    }
    else
    {
        update(u << 1 | 1, mid + 1, r, pos, v, w);
    }
    pushup(u);
}

Node query(int u, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return tree[u];
    }
    int mid = (l + r) >> 1;
    if (qr <= mid)
    {
        return query(u << 1, l, mid, ql, qr);
    }
    if (ql > mid)
    {
        return query(u << 1 | 1, mid + 1, r, ql, qr);
    }
    return merge(query(u << 1, l, mid, ql, qr), query(u << 1 | 1, mid + 1, r, ql, qr));
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> V[i] >> W[i];
    }

    build(1, 1, n);

    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int k, v;
            cin >> k >> v;
            V[k] = v;
            update(1, 1, n, k, V[k], W[k]);
        }
        else if (op == 2)
        {
            int k, w;
            cin >> k >> w;
            W[k] = w;
            update(1, 1, n, k, V[k], W[k]);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            Node res = query(1, 1, n, l, r);
            if (res.v_xor != 0)
            {
                cout << res.w_sum << endl;
            }
            else
            {
                int min_cost = res.basis.get_min_cost();
                if (min_cost == INF)
                {
                    cout << 0 << endl;
                }
                else
                {
                    cout << res.w_sum - min_cost << endl;
                }
            }
        }
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
