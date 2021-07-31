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
