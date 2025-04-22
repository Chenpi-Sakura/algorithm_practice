#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
struct LNode
{int data, tail;};
LNode LList[N];
LNode CList[N];
LNode DList[N];
unordered_set<int> s;
int tot;

int main()
{
    int head, n; cin >> head >> n;
    while (n--)
    {
        int h, d, t; cin >> h >> d >> t;
        LList[h].data = d; LList[h].tail = t;
    }
    int Dhead = -1;
    int Dlast = -1, Clast = -1;
    tot = head;
    while (tot != -1)
    {
        if (s.find(abs(LList[tot].data)) != s.end())
        {
            if (Dhead == -1) Dhead = tot;
            DList[tot].data = LList[tot].data;
            DList[tot].tail = -1;
            if (Dlast != -1) DList[Dlast].tail = tot;
            Dlast = tot;
        }
        else
        {
            CList[tot].data = LList[tot].data;
            CList[tot].tail = -1;
            if (Clast != -1) CList[Clast].tail = tot;
            Clast = tot;
        }
        s.insert(abs(LList[tot].data));
        tot = LList[tot].tail;
    }

    tot = head;
    while (tot != -1)
    {
        printf("%05d %d ", tot, CList[tot].data);
        if (CList[tot].tail != -1) printf("%05d\n", CList[tot].tail);
        else printf("%d\n", CList[tot].tail);
        tot = CList[tot].tail;
    }
    tot = Dhead;
    while (tot != -1)   
    {
        printf("%05d %d ", tot, DList[tot].data);
        if (DList[tot].tail != -1) printf("%05d\n", DList[tot].tail);
        else printf("%d\n", DList[tot].tail);
        tot = DList[tot].tail;
    }
    return 0;
}