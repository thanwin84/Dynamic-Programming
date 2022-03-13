// time: O(n * m ) and space: O(1)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        for (int r = row - 1; r >= 0; r--){
            for (int c = col -1; c >= 0; c--){
                if (c == col - 1 && r == row - 1){
                    dungeon[r][c] = min(0, dungeon[r][c]);
                }
                else if (c == col -1){
                    dungeon[r][c] = min(0, dungeon[r][c] + dungeon[r + 1][c]);
                }
                else if (r == row - 1) {
                    dungeon[r][c] = min(0, dungeon[r][c] + dungeon[r][c + 1]);
                }
                else {
                    dungeon[r][c] = min(0, dungeon[r][c] + max(dungeon[r + 1][c], dungeon[r][c + 1]));
                }
            }
        }
        return abs(dungeon[0][0]) + 1;
        
    }
};
