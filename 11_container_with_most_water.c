/*
 * 題目：11. Container With Most Water
 * 解題思路：
 * 採用雙指標 (Two Pointers)。左指標在最左邊，右指標在最右邊。
 * 每次計算當前的裝水量 (寬度 * 比較短的高)。
 * 為了找到可能更大的水量，我們必須移動「比較短」的那根柱子，
 * 因為移動比較高的那根，受限於短柱，水量絕對不可能變大。
 * 
 * 時間複雜度：O(N)，左右指標往中間靠攏，最多掃描一次。
 * 空間複雜度：O(1)，只用到幾個變數存面積與指標。
 */

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;
    
    while (left < right) {
        // 計算目前的寬度
        int width = right - left;
        // 計算目前的面積 (寬度 * 兩邊較短的高度)
        int current_area = width * MIN(height[left], height[right]);
        
        // 更新最大面積
        max_area = MAX(max_area, current_area);
        
        // 貪婪選擇：移動比較短的那根柱子
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_area;
}