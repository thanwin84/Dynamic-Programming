int dp[201][201];
class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col){
        if (row >= triangle.size() || col >= triangle[row].size()){
            return 0;
        }
        if (row == triangle.size() - 1 && col < triangle[row].size() && col >= 0){
            return triangle[row][col];
        }
        if (dp[row][col] != -1){
            return dp[row][col];
        }
        int current_ind = solve(triangle, row + 1, col);
        int next_ind = solve(triangle, row + 1, col + 1);
        return dp[row][col] = triangle[row][col] + min(current_ind, next_ind);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp, -1, sizeof(dp));
        return solve(triangle, 0, 0);
    }
};
// time: O(n + m) and space: O(row * col)

//iterative approach with same time and space complexity
int dp[201][201];
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int last_row = triangle.size();
        int last_row_col = triangle[last_row - 1].size();
        for (int i = 0; i < last_row_col; i++) dp[last_row -1][i] = triangle[last_row -1][i];
        for (int row = last_row - 2; row >= 0; row--){
            for (int col = 0; col < triangle[row].size(); col++){
                dp[row][col] = triangle[row][col] + min(dp[row + 1][col], dp[row + 1][col + 1]);
            }
        }
        return dp[0][0];
    }
};

// O(1) space solution

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        for (int currRow = rows - 2; currRow >= 0; currRow--){
            for (int currCol = 0; currCol < triangle[currRow].size(); currCol++){
                int nextRow = currRow + 1;
                int downward = triangle[nextRow][currCol];
                int diagonal = triangle[nextRow][currCol + 1];
                triangle[currRow][currCol] = triangle[currRow][currCol] + min(downward, diagonal);
                
            }
        }
        
        return triangle[0][0];
    }
};
