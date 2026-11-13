/*
 * 題目：74. Search a 2D Matrix
 * 解題思路：
 * 把整個 2D 矩陣當作一個攤平的 1D 陣列來思考。
 * 總共有 M * N 個元素，索引值 (index) 從 0 到 M * N - 1。
 * 套用標準的二分搜尋法 (Binary Search)，每次切一半。
 * 
 * 關鍵的座標轉換公式：
 * row = index / 總欄數 (n)
 * col = index % 總欄數 (n)
 * 
 * 時間複雜度：O(log(M * N))，每次都砍掉一半的範圍，非常快。
 * 空間複雜度：O(1)，只用到 left, right, mid 三個指標。
 */

#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize;          // 總列數 (row)
    int n = matrixColSize[0];    // 總欄數 (col)
    
    int left = 0;
    int right = m * n - 1;
    
    while (left <= right) {
        // 避免 left + right 太大導致整數溢位的好習慣寫法
        int mid = left + (right - left) / 2; 
        
        // 將 1D 的 index 轉回 2D 的座標
        int row = mid / n;
        int col = mid % n;
        int mid_value = matrix[row][col];
        
        if (mid_value == target) {
            return true;        // 找到了
        } else if (mid_value < target) {
            left = mid + 1;     // 目標在右半邊
        } else {
            right = mid - 1;    // 目標在左半邊
        }
    }
    
    return false; // 找完整個陣列都沒看到
}