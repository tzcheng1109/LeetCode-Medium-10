/*
 * 題目：75. Sort Colors
 * 解題思路：
 * 採用荷蘭國旗問題解法 (Three Pointers)。
 * 因為只有 0, 1, 2 三種數字，我們用三個指標來整理：
 * low：指向左邊，準備放下一個 0 的位置
 * high：指向右邊，準備放下一個 2 的位置
 * curr：當前正在掃描的指標
 * 
 * 遇到 0 就跟 low 交換，遇到 2 就跟 high 交換，遇到 1 就直接往前走。
 * 
 * 時間複雜度：O(N)，只掃描陣列一次。
 * 空間複雜度：O(1)，直接在原陣列進行交換，不需額外空間。
 */

// 自己寫一個交換函式，讓主程式看起來更乾淨
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int low = 0;
    int curr = 0;
    int high = numsSize - 1;
    
    while (curr <= high) {
        if (nums[curr] == 0) {
            // 看到 0，把它換到左邊去
            swap(&nums[low], &nums[curr]);
            low++;
            curr++;
        } else if (nums[curr] == 2) {
            // 看到 2，把它換到右邊去
            swap(&nums[curr], &nums[high]);
            high--;
            // 注意：這裡 curr 不往前走！因為從右邊換過來的新數字還沒檢查過，下一輪要再檢查一次
        } else {
            // 看到 1，位置正確，直接往前走
            curr++;
        }
    }
}