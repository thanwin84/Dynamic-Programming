//time: O(n * m)
int dp[501][502];
class Solution {
public:
    int solve(string &word1, string &word2, int i, int j){
        if (i == 0){
            return j;
        }
        if(j == 0){
            return i;
        }
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        if (word1[i - 1] == word2[j - 1]){
            return dp[i][j] = solve(word1, word2, i - 1, j - 1);
        }
        else {
            return dp[i][j] = 1 + min(solve(word1, word2, i - 1, j), solve(word1, word2, i, j -1));
        }
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, word1.size(), word2.size());
    }
};
//time: O(n *m)
int dp[501][501];
class Solution {
public:
    int minDistance(string word1, string word2) {
        for (int i = 0; i <= word1.size(); i++){
            for (int j = 0; j <= word2.size(); j++){
                if (i == 0){
                    dp[i][j] = j;
                }
                else if (j == 0){
                    dp[i][j] = i;
                }
                else if (word1[i -1] == word2[j -1]){
                    dp[i][j] = dp[i -1][j -1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i -1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
