/*
 * 題目：48. Rotate Image
 * 解題思路：
 * 將 2D 矩陣順時針旋轉 90 度，最直觀且不需額外空間的作法是「兩步走」：
 * 1. 對角線翻轉 (Transpose)：沿著左上到右下的對角線，將 matrix[i][j] 與 matrix[j][i] 互換。
 * 2. 左右反轉 (Reverse)：將每一列的左邊與右邊元素互換。
 * 兩步結合起來，剛好就是順時針旋轉 90 度。
 * 
 * 時間複雜度：O(N^2)，掃描矩陣兩次 (N 為邊長)。
 * 空間複雜度：O(1)，直接在原矩陣上交換，不需要額外陣列。
 */

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    
    // 第一步：沿著主對角線翻轉 (注意內層迴圈 j 從 i 開始，避免重複交換換回來)
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    // 第二步：將每一列進行左右反轉 (這部分又用到了我們最熟悉的雙指標)
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left++;
            right--;
        }
    }
}