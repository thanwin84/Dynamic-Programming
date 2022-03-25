// time: O(n * n) and space: O(1)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row =matrix.size();
        int col = matrix[0].size();
        for (int r = row -2; r >= 0; r--){
            for (int c = 0; c < col; c++){
                int down = INT_MAX, down_left = INT_MAX, down_right = INT_MAX;
                down = matrix[r + 1][c];
                if (c - 1 >= 0) down_left = matrix[r + 1][c - 1];
                if (c + 1 < col) down_right = matrix[r + 1][c + 1];
                matrix[r][c] =matrix[r][c] +  min(down, min(down_left, down_right));
            }
        }
        int ans = INT_MAX;
        for (int c = 0; c < row; c++){
            ans = min(matrix[0][c], ans);
        }
        return ans;
    }
};
