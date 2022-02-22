//memoization 
//time and space:  O(n * m)
int dp[502][502];
class Solution {
public:
    int solve(string &word1, string &word2, int i, int j){
        if (i == 0){
            return j;
        }
        if (j == 0){
            return i;
        }
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        if (word1[i-1] == word2[j -1]){
            return dp[i][j] = solve(word1, word2, i-1, j -1);
        }
        else {
            int insert = 1 + solve(word1, word2, i, j - 1);
            int _delete = 1 + solve(word1, word2, i - 1, j);
            int transition = 1 + solve(word1, word2, i - 1, j - 1);
            return dp[i][j] = min(min(insert, _delete), transition);
        }
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, word1.size(), word2.size());
    }
};
int dp[10000][10000];

class Solution {
public:
    int minDistance(string word1, string word2) {
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int i = 0; i <= word2.size(); i++) dp[0][i] = i;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int add = dp[i][j - 1] + 1;
                    int deletion = dp[i - 1][j] + 1;
                    int transition = dp[i - 1][j - 1] + 1;
                    dp[i][j] = min(add, min(deletion, transition));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
