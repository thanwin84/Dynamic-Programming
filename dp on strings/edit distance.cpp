///////////////////memoization///////////////////////////

int dp[501][501];
class Solution {
public:
    int solve(string &word1, string &word2, int i, int j){
        // if the first string is empty, the only option left 
        // is to insert all characters from second string
        if (i == 0) return j;
        // if the second string empty, then we have to delete all the chars
        // in the first string
        if (j == 0) return i;
        
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        // if both character is same, there is nothing to do
        // just solve the remaining part
        if (word1[i - 1] == word2[j - 1]){
            return solve(word1, word2, i - 1, j - 1);
        }
        else {
            // if not same, we can try any of these 3 operations
            int insertion = 1 + solve(word1, word2, i, j- 1);
            int deletion = 1 + solve(word1, word2, i - 1, j);
            int replace = 1 + solve(word1, word2, i - 1, j - 1);
            return dp[i][j] = min(insertion, min(deletion, replace));
        }
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, word1.size(), word2.size());
    }
};
// Time Complexity: O(n *m)
// space: O(n * m)
/////////////////////////// TOP DOWN APPROACH /////////

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++){
            for (int j = 0; j <= word2.size(); j++){
                if (i == 0) dp[i][j] = j;
                else if (j == 0) dp[i][j] = i;
                else if (word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int insertion = 1 + dp[i][j - 1];
                    int deletion = 1 + dp[i - 1][j];
                    int replace = 1 + dp[i - 1][j - 1];
                    dp[i][j] = min(insertion, min(deletion, replace));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
//////// 1d space solution////////////
// space: O(len(str2)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word2.size();
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        for (int i = 0; i <= n; i++) prev[i] = i;
        for (int i = 1; i <= word1.size(); i++){
            curr[0] = i;
            for (int j = 1; j <= word2.size(); j++){
                if (word1[i - 1] == word2[j - 1]){
                    curr[j] = prev[j - 1];
                }
                else {
                    int insertion = 1 + curr[j - 1];
                    int deletion = 1 + prev[j];
                    int replace = 1 + prev[j - 1];
                    curr[j] = min(insertion, min(deletion, replace));
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};
