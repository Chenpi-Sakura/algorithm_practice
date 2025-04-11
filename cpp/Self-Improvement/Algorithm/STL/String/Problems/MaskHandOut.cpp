#include <bits/stdc++.h> // 引入所有标准库头文件，方便竞赛使用
using namespace std;
#define int long long // 定义int为long long，防止某些情况下的整数溢出（虽然此题可能不需要）

typedef pair<int, int> PII;         // 定义整数对类型别名
typedef pair<string, string> PSS; // 定义字符串对类型别名 (用于存储 姓名, 身份证号)

// 定义一个新的结构来存储申请信息，包含原始索引
struct AppInfo {
    PSS name_id;    // pair<string, string> (姓名, 身份证号)
    int time_mins;  // int, 提交时间（转换为分钟数）
    int original_idx; // int, 当天输入的原始序号（用于时间相同时排序）

    // 重载小于号运算符，用于 std::sort 排序
    // 优先按提交时间（分钟数）升序排序
    // 如果时间相同，则按输入的原始序号升序排序
    bool operator<(const AppInfo& other) const {
        if (time_mins != other.time_mins) {
            return time_mins < other.time_mins;
        }
        return original_idx < other.original_idx; // 时间相同时，按输入顺序排
    }
};


// map<PSS, int> Mask; // 旧的使用 PSS 作为 key 的方式，效率稍低
map<string, int> Mask; // 建议只用 身份证号(string) 作为 key，存储剩余冷却天数
vector<AppInfo> Apply;       // vector, 存储当天所有通过初步验证的申请信息 (使用新结构)
vector<PSS> Dan;             // vector, 按首次出现顺序列出所有提交过有效申请且身体状况为1的人 (姓名, 身份证号)
set<string> Dan_ids; // set, 用于高效检查Dan列表中的身份证号是否重复，保证Dan中每个人只出现一次

// 将 "hh:mm" 格式的时间字符串转换为从 00:00 开始的总分钟数
int timCal(string x)
{
    int h = stoll(x.substr(0, 2)); // 提取小时并转为整数
    int m = stoll(x.substr(3, 2)); // 提取分钟并转为整数
    return h * 60 + m;            // 计算总分钟数
}

// 主处理函数
void solve()
{
    int d, p; // d: 总天数, p: 两次获取口罩的间隔天数
    cin >> d >> p;

    // 按天处理
    for (int i = 1; i <= d; i++) // i 代表当前是第几天
    {
        int t, s; // t: 当天的申请数量, s: 当天可发放的口罩数量
        cin >> t >> s;

        // --- 1. 更新冷却时间 ---
        // 遍历当前所有处于冷却期的人
        for (auto& pair_in_mask : Mask) { // 使用引用直接修改值
            if (pair_in_mask.second > 0) {
                pair_in_mask.second--;
            }
        }
        

        // --- 2. 读取和初步处理当天的申请 ---
        Apply.clear(); // 清空上一天的申请列表
        for (int j = 0; j < t; j++) // j 是当天申请的原始输入序号 (从0开始)
        {
            string name, id, time_str; // 姓名, 身份证号, 提交时间字符串
            int status; // 身体状况 (0 或 1)
            cin >> name >> id >> status >> time_str;

            // --- 2.1 验证身份证号格式 ---
            bool allDig = true; // 假设全为数字
            if (id.size() != 18) continue; // 长度必须是18位，否则跳过此申请
            for (char c : id) { // 遍历身份证号的每个字符
                if (!isdigit(c)) { // 如果发现非数字字符
                    allDig = false; // 标记为无效
                    break;        // 不用继续检查了
                }
            }
            if (!allDig) continue; // 如果包含非数字字符，跳过此申请

            // --- 身份证号格式有效 ---

            // --- 2.2 将有效申请添加到待处理列表 Apply ---
            // 存储 (姓名, 身份证号), 计算出的分钟数, 原始输入序号 j
            Apply.push_back({{name, id}, timCal(time_str), j});

            // --- 2.3 记录身体状况为1的申请人 (去重) ---
            if (status == 1) { // 如果身体状况为1
                // 使用 set 检查该身份证号是否已记录过
                if (Dan_ids.find(id) == Dan_ids.end()) { // 如果 Dan_ids 中找不到这个 id
                     Dan.push_back({name, id}); // 将 (姓名, 身份证号) 添加到 Dan 列表
                     Dan_ids.insert(id);        // 将该 id 加入 Dan_ids 集合，表示已记录
                }
            }
        } // 当天所有申请读取处理完毕

        // --- 3. 排序当天所有有效申请 ---
        // 使用 AppInfo 中重载的 < 运算符排序
        // 优先按时间升序，时间相同按原始输入序号 j 升序
        sort(Apply.begin(), Apply.end());

        // --- 4. 发放口罩 ---
        int distributed_today = 0; // 记录当天已发放的口罩数量
        // 遍历排序后的申请列表
        for (const auto& current_app : Apply) { // 使用 const auto& 避免不必要的拷贝
            if (distributed_today >= s) { // 如果当天口罩已发完
                break; // 结束发放流程
            }

            // 检查申请人是否处于冷却期
            // Mask.count(key) 检查 key 是否存在于 map 中
            // 如果 key 不存在 (count==0) 或 存在但冷却计数器 <= 0，则符合资格
            string current_id = current_app.name_id.second; // 获取当前申请的身份证号
            if (Mask.count(current_id) == 0 || Mask[current_id] <= 0)
            {
                // --- 符合发放条件 ---
                cout << current_app.name_id.first << ' ' << current_id << "\n"; // 输出发放名单 (姓名 身份证号)，使用 "\n" 换行
                Mask[current_id] = p + 1; // 设置冷却时间 (p 天间隔 + 当前这 1 天 = p + 1)
                distributed_today++;      // 已发放数量加 1
            }
            // 无论是否发放，都继续处理下一个排序后的申请者
        } // 当天发放流程结束
    } // 所有天数处理完毕

    // --- 5. 输出所有记录在案的身体状况为1的人员列表 ---
    for (const auto& person : Dan) { // 遍历 Dan 列表
        cout << person.first << ' ' << person.second << "\n"; // 输出姓名和身份证号
    }
}

// 主函数
signed main()
{
    // 优化输入输出速度
    ios::sync_with_stdio(0); // 关闭 C++ 标准流与 C 标准流的同步
    cin.tie(0);             // 解除 cin 与 cout 的绑定

    int t = 1; // 题目说明只有一组测试数据
    // cin >> t; // 如果有多组测试数据，则取消此行注释
    while (t--) { // 执行测试数据
        solve(); // 调用处理函数
    }
    return 0; // 程序正常结束
}