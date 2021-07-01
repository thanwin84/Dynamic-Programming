int dp[10000][10000];

class Solution {
public:
    int minimumNumberOfDeletions(string S) {
        // code here
        string s2 = S;
        reverse(S.begin(), S.end());
        for (int i = 0; i <= S.size(); i++) dp[0][i] = 0;
        for (int i = 0; i <= s2.size(); i++) dp[i][0] = 0;
        for (int i = 1; i <= S.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (S[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return S.size() - dp[S.size()][S.size()];
    }
};
