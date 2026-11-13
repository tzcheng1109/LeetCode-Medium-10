/*
 * 題目：238. Product of Array Except Self
 * 解題思路：
 * 題目要求不能使用除法。我們將結果拆成兩個部分：
 * 1. 數字左邊所有元素的乘積
 * 2. 數字右邊所有元素的乘積
 * 
 * 步驟一：先從左掃到右，把每個位置「左邊的乘積」算出來並存入結果陣列。
 * 步驟二：從右掃到左，用一個變數 right_product 記錄目前累積的「右邊的乘積」，
 *         邊算邊乘回剛剛的結果陣列裡。
 * 
 * 時間複雜度：O(N)，掃描陣列兩次。
 * 空間複雜度：O(1)，除了題目規定要回傳的陣列外，只用到一個額外變數。
 */

#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    // 步驟一：計算每個數字「左邊」的乘積
    // 第一個數字左邊沒有東西，所以預設為 1
    result[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        // 目前格子的左邊乘積 = 上一格的左邊乘積 * 上一格原本的數字
        result[i] = result[i - 1] * nums[i - 1];
    }
    
    // 步驟二：從右邊掃回來，乘上每個數字「右邊」的乘積
    // 最右邊的數字右邊沒有東西，所以初始為 1
    int right_product = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        // 結果 = (已經存在裡面的左邊乘積) * (右邊乘積)
        result[i] = result[i] * right_product;
        // 更新右邊乘積給下一格用
        right_product *= nums[i];
    }
    
    return result;
}