// time and space: O(s * t)
int dp[1001][1001];
class Solution {
public:
    int solve(string &s, string &t, int i, int j){
        // we already searched all characters of string "t"
        if (j <= 0) {
            return 1;
        }
        // we are left with 0 elements
        if (i <= 0){
            return 0;
        }
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        if (s[i - 1] == t[j - 1]){
            return dp[i][j] = solve(s, t, i - 1, j - 1) + solve(s, t, i - 1, j);
        }
        else {
            return dp[i][j] = solve(s, t, i -1, j);
        }
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return solve(s, t, s.size(), t.size());
    }
};
// iterative approach
unsigned long long int dp[1001][1001];
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= m; j++){
                dp[i][j] = 0;
                if (j == 0){
                    dp[i][j] = 1;
                }
                else if (i == 0){
                    dp[i][j] = 0;
                }
                else if (s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};
// space optimized Om)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long int> prev(n + 1, 0), curr(m + 1, 0);
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= m; j++){
                if (j == 0){
                    curr[j] = 1;
                }
                else if (i == 0){
                    curr[j] = 0;
                }
                else if (s[i - 1] == t[j - 1]){
                    curr[j] = prev[j - 1] + prev[j];
                }
                else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
// using only 1d array
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long int> dp(m + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = m;  j >= 1; j--){
                if (s[i - 1] == t[j - 1]){
                    dp[j] = dp[j - 1] + dp[j];
                }
            }
        }
        return dp[m];
    }
};
