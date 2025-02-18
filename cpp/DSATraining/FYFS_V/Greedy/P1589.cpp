#include<bits/stdc++.h> 
using namespace std;

const int N = 1e7;
typedef pair<int, int> PII;
PII a[N];

int main( )
{
    int n, l; cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n); 
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int current = a[i].first;
        
        while (1)
        {
            ans++;
            current += l;
            if (current >= a[i].second)
            {
                if (current < a[i + 1].first) break;
                // else i++;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}