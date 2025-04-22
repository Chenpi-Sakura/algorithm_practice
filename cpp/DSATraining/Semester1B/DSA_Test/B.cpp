#include <iostream>

int main() {
    // 使用 std::ios_base::sync_with_stdio(false) 和 std::cin.tie(NULL)
    // 加速 C++ 标准库的输入输出操作，对于大量输入数据（T很大时）有帮助
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T; // 查询的数量
    std::cin >> T;
    
    // 处理每个查询
    while (T--) {
        long long n, m; // 矩形的尺寸 (使用 long long 以处理大数)
        int a, b;       // 约束条件的指示符
        std::cin >> n >> m >> a >> b;
        
        // 基本条件检查: 多米诺骨牌覆盖要求总面积 n * m 必须是偶数.
        // 如果 n 和 m 都是奇数, 面积就是奇数, 无法覆盖.
        if ((n % 2 != 0) && (m % 2 != 0)) {
            std::cout << "No\n";
        } else {
            // 面积是偶数, 继续根据约束条件判断
            
            if (a == 1 && b == 1) {
                // 情况 1: 没有约束 (a=1, b=1). 
                // 只要面积是偶数, 总能用多米诺骨牌覆盖.
                std::cout << "Yes\n";
                
            } else if (a == 0 && b == 1) {
                // 情况 2: 只有约束 1 (a=0, b=1): 短边不能相邻.
                // 这强制所有骨牌必须是水平放置的 (1x2).
                // 因此, 只有当矩形的宽度 m 是偶数时才可能覆盖.
                if (m % 2 == 0) {
                    std::cout << "Yes\n";
                } else {
                    std::cout << "No\n";
                }
                
            } else if (a == 1 && b == 0) {
                // 情况 3: 只有约束 2 (a=1, b=0): 长边不能相邻.
                // 这强制所有骨牌必须是竖直放置的 (2x1).
                // 因此, 只有当矩形的高度 n 是偶数时才可能覆盖.
                if (n % 2 == 0) {
                    std::cout << "Yes\n";
                } else {
                    std::cout << "No\n";
                }
                
            } else { // a == 0 && b == 0
                // 情况 4: 两个约束都存在 (a=0, b=0).
                // 约束 1 要求纯水平覆盖 (m 偶). 约束 2 要求纯竖直覆盖 (n 偶).
                // 这在 n >= 2 且 m >= 2 时是矛盾的.
                // 只有当 n=1 或 m=1 时, 才能满足其中一种覆盖方式且不违反约束.
                // (面积为偶数保证了 n=1 时 m 偶, m=1 时 n 偶)
                if (n == 1 || m == 1) {
                    std::cout << "Yes\n";
                } else {
                    // n >= 2 且 m >= 2, 约束条件矛盾.
                    std::cout << "No\n";
                }
            }
        }
    }
    
    return 0; // 程序正常退出
}