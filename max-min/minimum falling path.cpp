// time: O(n * n) and space: O(1)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int currRow = n - 2; currRow >= 0; currRow--){
            for (int currCol = 0; currCol < n; currCol++){
                int downward = INT_MAX, ldiagonal = INT_MAX, rdiagonal = INT_MAX;
                downward = matrix[currRow + 1][currCol];
                if (currCol - 1 >= 0) ldiagonal = matrix[currRow + 1][currCol - 1];
                if (currCol + 1 < n) rdiagonal = matrix[currRow + 1][currCol + 1];
                matrix[currRow][currCol] += min(downward, min(ldiagonal, rdiagonal));
                
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++){
            ans = min(ans, matrix[0][i]);
        }
        return ans;
    }
};
