#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int inf = 0x3f3f3f3f;
int cnt;
int a[N];
int tree[N][3]; // Left, Data, Right

// 写成中序遍历了:-(
// bool checkA(int l, int r)
// {
//     if (l == r) return true;
//     int mid = (l + r) / 2;
//     if (a[(l + mid - 1) / 2] < a[mid] && a[mid] <= a[(mid + r + 1) / 2]) 
//         return checkA(l, mid - 1) && checkA(mid + 1, r);
//     return false;
// }

// bool checkB(int l, int r)
// {
//     if (l == r) return true;
//     int mid = (l + r) / 2;
//     if (a[(l + mid - 1) / 2] >= a[mid] && a[mid] > a[(mid + r + 1) / 2]) 
//         return checkB(l, mid - 1) && checkB(mid + 1, r);
//     return false;
// }

bool checkA(int l, int r)
{
    if (l == r) 
    {
        tree[l][0] = -inf;
        tree[l][1] = a[l];
        tree[l][2] = -inf;
        return true;
    }
    int mid = (l + r) / 2;
    tree[l][0] = l + 1;
    tree[l][1] = a[l];
    tree[l][2] = mid + 1;
    if (a[l + 1] < a[l] && a[l] <= a[mid + 1]) 
        return checkA(l + 1, mid) && checkA(mid + 1, r);
    return false;
}

bool checkB(int l, int r)
{
    if (l == r) 
    {
        tree[l][0] = -inf;
        tree[l][1] = a[l];
        tree[l][2] = -inf;
        return true;
    }
    int mid = (l + r) / 2;
    tree[l][0] = l + 1;
    tree[l][1] = a[l];
    tree[l][2] = mid + 1;
    if (a[l + 1] >= a[l] && a[l] > a[mid + 1]) 
        return checkB(l + 1, mid) && checkB(mid + 1, r);
    return false;
}

void pos(int index)
{
    if (index == -inf) return;
    pos(tree[index][0]);
    pos(tree[index][2]);
    if (cnt == 0) {cout << tree[index][1]; cnt++;}
    else {cout << ' ' << tree[index][1]; cnt++;}
}

int main()
{
    int n; cin >> n;
    memset(a, -inf, sizeof(a));
    for (int i = 0; i < n; i++) cin >> a[i];
    if (checkA(0, n - 1) || checkB(0, n - 1))
    {
        cout << "YES" << endl;
        pos(0);
        cout << endl;
    }
    else cout << "NO" << endl;
    return 0;
}