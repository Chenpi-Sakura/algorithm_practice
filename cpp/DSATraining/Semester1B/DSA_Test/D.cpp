#include <iostream>
#include <algorithm> // 包含 min 函数

int main() {
    // 使用 long long 防止 n*k 潜在的整数溢出
    long long n, k; 
    
    // 读取输入
    if (!(std::cin >> n >> k)) {
        // 如果输入失败，返回错误码
        return 1; 
    }
    
    // 计算有效步长 k_eff，取 k 和 n-k 中较小者
    // 因为连接 i 到 (i+k)%n 和 i 到 (i+n-k)%n 效果相同
    long long k_eff = std::min(k, n - k);
    
    long long pieces; // 用于存储结果（块数）
    
    // 处理特殊情况: n 为偶数且 k_eff 为 n/2
    // 此时所有切割线都是穿过中心的主对角线
    // 注意：k_eff == n / 2 隐含了 n 必须是偶数
    // 但为了代码清晰和安全，明确检查 n % 2 == 0
    if (n % 2 == 0 && k_eff * 2 == n) {
        // n/2 条主对角线将 n 边形分割成 n 个三角形区域
        pieces = n; 
    } else {
        // 处理一般情况
        // 根据观察和模式推导出的公式
        // 1 (初始块) + n (每条线至少增加1块) + n * (k_eff - 1) (交点额外增加的块数)
        pieces = 1 + n + n * (k_eff - 1);
    }
    
    // 输出计算得到的块数
    std::cout << pieces << std::endl;
    
    return 0; // 程序正常结束
}