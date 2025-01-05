    /*
    P3156 【深基15.例1】询问学号

    输入格式
    第一行 2 个整数 n 和 m，表示学生个数和询问次数。
    第二行 n 个整数，表示按顺序进入教室的学号。
    第三行 m 个整数，表示询问第几个进入教室的同学。

    输出格式
    输出 m 个整数表示答案，用换行隔开。
    */

    #include <bits/stdc++.h>
    using namespace std;

    typedef long long LL;
    vector<LL> a;

    int main()
    {
        LL n, m;
        cin >> n >> m;
        a.resize(n);

        for (LL i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (LL i = 0; i < m; i++)
        {
            LL t;
            cin >> t;
            cout << a[t - 1] << endl;
        }
        return 0;
    }