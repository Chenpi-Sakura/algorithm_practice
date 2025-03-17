#include <bits/stdc++.h>
using namespace std;

const int N = 500;
int a[N][N];
long long m;
int n;
vector<int> num;

void f()
{
    for (int i = 2; i < m; i++)
    {
        num[i] = a[num[i - 1]][num[i - 2]];
    }
}

int main()
{
    cin >> n >> m;
    num.resize(m);
    num[0] = 1;
    num[1] = 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    f();
    for (int i = 0; i < m; i++)
        cout << num[i] << endl;

    return 0;
}