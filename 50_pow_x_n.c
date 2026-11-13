/*
 * 題目：50. Pow(x, n)
 * 解題思路：
 * 採用快速冪 (Fast Power) 演算法，核心精神是 Divide and Conquer。
 * 不用土法煉鋼乘 N 次，而是每次把次方數砍半。
 * 例如 2^10 = (2^5)^2。如果遇到奇數次方，就多乘一次底數。
 * 
 * 陷阱防禦：n 可能是整數最小值 -2147483648，如果直接變正數會超出 int 上限 (Overflow)，
 * 所以一開始必須先把它存進 long long 型態的變數 N 裡面。
 * 
 * 時間複雜度：O(log N)，因為次方數每次都除以 2。
 * 空間複雜度：O(log N)，遞迴呼叫所佔用的系統堆疊深度。
 */

// 輔助函式：專門處理正數次方的快速冪
double fastPow(double x, long long n) {
    // 任何數的 0 次方都是 1
    if (n == 0) {
        return 1.0;
    }
    
    // 把問題切一半
    double half = fastPow(x, n / 2);
    
    // 如果次方數是偶數
    if (n % 2 == 0) {
        return half * half;
    } 
    // 如果次方數是奇數 (要把剛剛砍半時漏掉的那一次乘回來)
    else {
        return half * half * x;
    }
}

double myPow(double x, int n) {
    long long N = n; // 轉成 long long 避免負數轉正時溢位
    
    // 如果是負次方，就把底數變倒數，次方變正數
    if (N < 0) {
        x = 1.0 / x;
        N = -N;
    }
    
    return fastPow(x, N);
}