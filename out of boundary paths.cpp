//time and space: O(n^3)
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
