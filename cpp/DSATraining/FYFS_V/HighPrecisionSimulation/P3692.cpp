/*
夏幻的考试
题目背景
夏之幻是软件工程系的大神，学校把举办考试的任务交给她了。

题目描述
某大学软工专业要举办一场笔试，学生们要在机读答题卡上填写答案来进行答题。学校把机读卡识别任务交给了夏之幻，但是这套系统的需求太复杂了，她还要做自己的其他项(you)目(xi)，所以她想让你来帮忙实现一部分功能。
试卷分卷头，单选题两部分。
夏幻大神已经写好了识别程序，因此卷头和答案将直接以数字信息的形式呈现给你，你要实现下面几个功能:
需要处理T张试卷，按顺序检查下列选项。

1.检查考号的填写是否准确。
输入信息的格式:
一行，一个16位无符号二进制数id。表示考生的考号为id，正确的考号范围在十进制下是1~10000。
如果考号有错误，输出一行“Wrong ID”并结束对这张试卷的处理(剩下两个选项的数据依然要读入，但不输出任何内容)，不含引号。如果考号正确，输出一行,“ID: ”+一个整数，表示考号的十进制形式。不含引号。
无需考虑考号是否重复，只要在范围内均为正确。

2.检查试卷类型是否正确。
输入信息格式:
一行，两个整数，中间无分隔，只能是0或者1。第一个整数表示试卷类型A是否被涂黑(0表示未涂黑，1表示涂黑)，第二个整数表示试卷类型B是否涂黑。其实试卷类型可以由二进制考号的最后一位得到，0表示A卷，1表示B卷，你只需要检查考生填涂的是否正确。
如果考生将试卷类型正确填涂(填涂且只填涂了正确的那一项)，输出一行“Type Correct”，否则输出一行“Type Incorrect”，不含引号。无论试卷类型是否填涂正确，你还需要接着处理这张试卷。

3.给单选题打分。
单选题的数量n和标准答案将会在录入第一张试卷前给出。
考生答案的输入格式:
n行，每行4个整数，中间无分隔。每个整数是0或1。
按顺序分别代表A,B,C,D是否被涂黑(0表示未涂黑，1表示涂黑)。考生回答正确当且仅当该题正确答案的位置被涂黑，且错误答案的位置未被涂黑。
输出一行，一个四舍五入到小数点后1位的浮点数，表示考生的得分，满分为100分，每个题的分数相同。

输入格式
第一行两个整数T，n，空格分开，含义见题目描述。
接下来一行一个字符串s，长度为n，每个字符是大写字母A,B,C,D中的一个，第i个字符表示单选题i的答案。
接下来T*(n+2)行含有T组信息，表示每张试卷的内容，格式见题目描述。

输出格式
对于每张试卷，输出评判结果，格式见题目描述。两张试卷的评判结果之间空一行。

输入数据 1
2 5
ABCAD
0000000011111111
01
1000
0010
0100
1000
0010
1001001001001001
01
0001
1010
0111
1111
0000

输出数据 1
ID: 255
Type Correct
40.0

Wrong ID

输入数据 2
3 3
ABC
0000000000000000
01
1111
0001
0100
0000000000000010
10
1000
0100
0010
0000000000000011
11
0001
0000
0010

输出数据 2
Wrong ID

ID: 2
Type Correct
100.0

ID: 3
Type Incorrect
33.3

提示
对于100%的数据
1<=T<=1000
1<=n<=50
注意:
1.请在最后一个试卷处理完后也加上一个换行
2.由于win系统和linux系统换行的不同，建议不要使用scanf读入char
*/

#include<bits/stdc++.h> 
using namespace std;

string ans;
int num;

bool IDcheck(string id)
{
    int res = 0, base = 1;
    for (int i = 15; i >= 0; i--)
    {
        res += (id[i] - '0') * base;
        base *= 2;
    }

    if (res < 1 || res > 10000)
    {
        cout << "Wrong ID" << endl;
        return false;
    }

    cout << "ID: " << res << endl;
    return true;
}

bool typeCheck(string id)
{
    string type; cin >> type;
    int checkValue = type[0] + type[1] - 2 * '0';
    if (checkValue == 1)
    {
        if ((id[15] == '0' && type[0] == '1') || (id[15] == '1' && type[1] == '1'))
            return true;
    }
    return false;
}

double jugde()
{
    int correct = 0;
    for (int i = 0; i < num; i++)
    {
        int current = ans[i] - 'A';
        string stuans; cin >> stuans;
        int checkValue = stuans[0] + stuans[1] + stuans[2] + stuans[3] - 4 * '0';
        if (stuans[current] == '1' && checkValue == 1) correct++;
    }
    double res = 100.0 * correct / num;
    return res;
}

int main( )
{
    int n; cin >> n >> num >> ans;
    for (int i = 0; i < n; i++)
    {
        string id; cin >> id;

        bool typeRight = typeCheck(id);
        double res = jugde();

        if (IDcheck(id))
        {
            if (typeRight) cout << "Type Correct" << endl;
            else cout << "Type Incorrect" << endl;
            printf("%.1lf\n", res);
        }
        cout << endl;
    }

    return 0;
}