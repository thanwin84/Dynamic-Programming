int dp[10000][10000];

class Solution{
    public:
        int LongestRepeatingSubsequence(string str) {
            // Code here
            string s2 = str;
            for (int i = 0; i <= str.size(); i++) dp[0][i] = 0;
            for (int i = 0; i <= str.size(); i++) dp[i][0] = 0;
            for (int i = 1; i <= str.size(); i++) {
                for (int j = 1; j <= str.size(); j++) {
                  // we need cross matching 
                    if (str[i - 1] == s2[j - 1] and i != j) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[str.size()][str.size()];
        }

};
