/* 问题描述

给你两个版本号 `version1` 和 `version2`，请你比较它们。

版本号由一个或多个修订号组成，各修订号由一个 `.` 连接。每个修订号由多位数字组成，可能包含前导零。每个版本号至少包含一个字符。修订号从左到右编号，下标从 0 开始，最左边的修订号下标为 0，下一个修订号下标为 1，以此类推。例如，`2.5.33` 和 `0.1` 都是有效的版本号。

比较版本号时，请按从左到右的顺序依次比较它们的修订号。比较修订号时，只需比较忽略任何前导零后的整数值。也就是说，修订号 `1` 和修订号 `001` 相等。如果版本号没有指定某个下标处的修订号，则该修订号视为 0。例如，版本 `1.0` 小于版本 `1.1`，因为它们下标为 0 的修订号相同，而下标为 1 的修订号分别为 `0` 和 `1`，`0 < 1`。

返回规则如下：
- 如果 `version1 > version2` 返回 `1`，
- 如果 `version1 < version2` 返回 `-1`，
- 除此之外返回 `0`。
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int solution(std::string v1, std::string v2) {
    // Edit your code here
    string segment;
    stringstream ss(v1); //定义数据流，能够使数据以数据流的形式传入
    vector<int> numbers1;
    
    while (getline(ss, segment, '.')){
        numbers1.push_back(stoi(segment));
    }//处理第一个version,将.之间的数字转存为数组n1里的数据
    
    stringstream ss(v2);
    vector<int> numbers2;
    
    while (getline(ss, segment, '.')){
        numbers2.push_back(stoi(segment));
    }

    return -1;
}

int main() {
    // Add your test cases here

    std::cout << (solution("0.1", "1.1") == -1) << std::endl;
    std::cout << (solution("1.0.1", "1") == 1) << std::endl;
    std::cout << (solution("7.5.2.4", "7.5.3") == -1) << std::endl;
    std::cout << (solution("1.0", "1.0.0") == 0) << std::endl;

    return 0;
}


/*
借助了cha桑的帮助，一个人实在是有点想不到。
*/