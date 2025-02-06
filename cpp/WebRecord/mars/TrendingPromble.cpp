/*

奇妙货币交易问题
问题描述
小R住在一个名为 X 国的国家，这里的货币非常特殊，面值为 V^0,V^1,V^2,...,V^n，并且n可以无限大。该国的交易规则也很特别：在一次交易中，双方只能对每种面值的货币使用不超过两次。

例如，小R想买一件价格为 198 的物品，货币的基数 V=10 时，小R可以使用 2 张 100(10^2)的纸币，卖家则找回 2 张 1(10^0)的纸币。由于这个奇怪的规则，很多 X 国人都无法快速判断某个物品是否可以用这种方式交易成功，他们常常会请聪明的你来帮助。

你能帮他们判断一下，是否能按照规则用给定的货币面值 V 来完成价格为 W 的交易吗？

*/
/*
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string solution(int V, int W)
{
    // Edit your code here
    int total = 0, i;
    for (i = 0; total < W; i++)
    {
        int add = pow(V, i);
        if (total < W)
        {
            total += add;
        }
        if (total < W)
        {
            total += add;
        }
        else
        {
            break;
        }
    } // 找到刚好超过W的V次幂

    for (i -= 1; total > W && i >= 0; i--)
    {
        int sub = pow(V, i);
        if ((total - sub) >= W)
        {
            total -= sub;
        }

        if ((total - sub) >= W)
        {
            total -= sub;
        }

        if (total == W)
        {
            break;
        }
    } // 从大到小减去

    if (i != -1)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}
int main()
{
    // Add your test cases here
    //cout << (solution(10, 9) == "Yes") << endl;
    cout << (solution(200, 40199) == "Yes") << endl;
    cout << (solution(108, 50) == "NO") << endl;
    return 0;
}
*/

/*

    该题目的核心是探究一个数是否能通过另一个数的幂加减得到
    限制条件为每个次幂的数字只能用两次

    想法一：
        用V的次幂构建一个刚好比W大的数字
        然后再找数字相减
        避免出现多次使用货币的情况
        相减时从大到小


*/

#include <iostream>
#include <cmath>
using namespace std;

string solution(int V, int W) {
    int remaining = W;
    int maxPower = 0;

    // 找到最高的次幂，V^maxPower <= W
    while (pow(V, maxPower) <= W) {
        maxPower++;
    }
    maxPower--; // maxPower 是从 0 开始计算的次幂，所以减去1

    // 从最大次幂开始贪心
    for (int i = maxPower; i >= 0; i--) {
        int value = pow(V, i); // 当前面值
        int use = min(remaining / value, 2); // 每种面值最多使用2次
        remaining -= use * value; // 减去使用的面值
    }

    // 检查是否凑齐了价格
    return (remaining == 0) ? "Yes" : "No";
}

int main() {
    // 测试用例
    cout << solution(10, 198) << endl;    // 应输出 "Yes"
    cout << solution(10, 40199) << endl;  // 应输出 "Yes"
    cout << solution(108, 50) << endl;    // 应输出 "No"
    return 0;
}
