//time and space: O(row * col * moves)
// Top down approach
#define mod 1000000007
long long int moves[51][51][51];
class Solution {
public:
    int solve(int row, int col, int maxMove, int startRow, int startColumn){
        if ((startRow < 0 && maxMove >= 0) || (startRow >= row && maxMove >= 0) ||
           (startColumn < 0 && maxMove >= 0) || (startColumn >= col && maxMove >= 0)){
            return 1;
        }
        if (maxMove < 0){
            return 0;
        }
        if (moves[startRow][startColumn][maxMove] != -1){
            return moves[startRow][startColumn][maxMove];
        }
        long long int left = solve(row, col,  maxMove - 1, startRow, startColumn -1);
        long long int right = solve(row, col,  maxMove - 1, startRow, startColumn + 1);
        long long int up = solve(row, col, maxMove - 1, startRow - 1, startColumn);
        long long int down = solve(row, col, maxMove - 1, startRow + 1, startColumn);
        return moves[startRow][startColumn][maxMove] = (left + right + up + down) % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(moves, -1, sizeof(moves));
        return solve(m, n, maxMove, startRow, startColumn);
    }
};
// iterative approach
//time and space: O(row * col * moves)
#define mod 1000000007
long long int moves[51][51][51];
class Solution {
public:
    bool out_of_boundary(int r, int c, int row, int col){
        return r < 0 || r >= row || c  < 0 || c >= col;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(moves, 0, sizeof(moves));
        long long int up = 0, down = 0, left = 0, right = 0;
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int move = 1; move <= maxMove; move++){
            for (int row  = 0; row < m; row++){
                for (int col = 0; col < n; col++){
                    for (int d = 0; d < 4; d++){
                        int next_row = row + directions[d][0];
                        int next_col = col + directions[d][1];
                        // check for all directions
                        if (out_of_boundary(next_row, next_col, m, n)){
                            moves[move][row][col] += 1 % mod;
                        }
                        else {
                            moves[move][row][col] += moves[move -1][next_row][next_col] % mod;
                        }
                    }
                }
            }
        }
        return moves[maxMove][startRow][startColumn] % mod;
    }
};
