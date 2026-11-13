/*
 * 題目：53. Maximum Subarray
 * 解題思路：
 * 採用 Kadane's Algorithm (動態規劃概念)。
 * 核心精神是「及時停損」：我們從頭開始把數字加起來，
 * 如果前面累積的總和 (current_sum) 已經小於 0 了，那它加上目前的數字只會讓結果更小。
 * 所以我們就果斷放棄前面的總和，把 current_sum 重新設定為目前的數字。
 * 過程中用 max_sum 隨時紀錄出現過的最高紀錄。
 * 
 * 時間複雜度：O(N)，迴圈只跑一次。
 * 空間複雜度：O(1)，只用到兩個變數。
 */

int maxSubArray(int* nums, int numsSize) {
    // 一開始先把第一個數字當作最大值與目前總和
    int max_sum = nums[0];
    int current_sum = nums[0];
    
    // 從第二個數字 (index 1) 開始往後走
    for (int i = 1; i < numsSize; i++) {
        // 如果前面的總和是負的 (拖油瓶)，就重新從現在這個數字開始算
        if (current_sum < 0) {
            current_sum = nums[i];
        } else {
            // 否則就繼續累積
            current_sum += nums[i];
        }
        
        // 隨時更新歷史最大值
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    return max_sum;
}