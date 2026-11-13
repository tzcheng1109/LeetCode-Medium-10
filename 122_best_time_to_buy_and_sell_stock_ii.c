/*
 * 題目：122. Best Time to Buy and Sell Stock II
 * 解題思路：
 * 採用貪婪演算法 (Greedy)。因為可以無限次買賣，不需要找絕對的最低或最高點。
 * 只要「今天的價格」比「昨天的價格」高，我們就假裝昨天買入、今天賣出，把所有上漲的價差都收集起來。
 * 
 * 時間複雜度：O(N)，只需掃描陣列一次。
 * 空間複雜度：O(1)，只用到一個變數 max_profit。
 */

int maxProfit(int* prices, int pricesSize) {
    int max_profit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1]) {
            max_profit += (prices[i] - prices[i - 1]);
        }
    }

    return max_profit;
}