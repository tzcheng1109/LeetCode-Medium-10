/*
 * 題目：73. Set Matrix Zeroes
 * 解題思路：
 * 為了避免「把某行/某列變成 0 後，影響到後續的判斷」，我們採用先標記、後修改的策略。
 * 1. 建立兩個布林(或整數)陣列 row_zero 和 col_zero 來當作「記號本」。
 * 2. 第一次走訪整個矩陣：只要遇到 0，就把對應的 row_zero[i] 和 col_zero[j] 打勾 (設為 1)。
 * 3. 第二次走訪整個矩陣：只要目前的座標 (i, j) 對應的記號本上有打勾，就把這格變成 0。
 * 
 * 時間複雜度：O(M * N)，走訪矩陣兩次。
 * 空間複雜度：O(M + N)，額外宣告了兩個一維陣列來存記號 (極度好懂且安全的作法)。
 */

#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    
    // 動態配置兩個「記號本」陣列，並初始化為 0 (calloc 會自動補 0)
    int* row_zero = (int*)calloc(m, sizeof(int));
    int* col_zero = (int*)calloc(n, sizeof(int));
    
    // 第一次掃描：作記號
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row_zero[i] = 1; // 標記第 i 列需要變 0
                col_zero[j] = 1; // 標記第 j 行需要變 0
            }
        }
    }
    
    // 第二次掃描：根據記號本，把格子變成 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 只要它所在的列，或是所在的行被標記了，它就要變成 0
            if (row_zero[i] == 1 || col_zero[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // 釋放記憶體是 C 語言的好習慣
    free(row_zero);
    free(col_zero);
}