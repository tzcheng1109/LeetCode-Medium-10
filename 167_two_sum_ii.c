/*
 * 題目：167. Two Sum II - Input Array Is Sorted
 * 解題思路：
 * 採用雙指標 (Two Pointers)。因為陣列已經從小到大排序好，
 * 我們把左指標放在最前面，右指標放在最後面，把兩個數字加起來。
 * 如果「加總」太大，代表右邊的數字太大了，所以右指標往左移 (right--)；
 * 如果「加總」太小，代表左邊的數字太小了，所以左指標往右移 (left++)。
 * 
 * 時間複雜度：O(N)，最多只要把陣列掃描一次。
 * 空間複雜度：O(1)，只用到 left 和 right 兩個變數 (不計回傳陣列的空間)。
 */

#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    // 題目規定回傳兩個數字，動態配置記憶體
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    int left = 0;
    int right = numbersSize - 1;
    
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        
        if (sum == target) {
            // 題目要求回傳的 index 是 1-indexed (從 1 開始數)，所以要 +1
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        } else if (sum < target) {
            left++;  // 加總太小，左指標往右找大一點的數字
        } else {
            right--; // 加總太大，右指標往左找小一點的數字
        }
    }
    
    return result;
}