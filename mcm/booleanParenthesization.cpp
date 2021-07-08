//recursive
class Solution {
public:
    int solve(string s, int i, int j, bool isTrue) {
        if (i > j) {
            return false;
        }
        if (i == j) {
            if (isTrue) {
                return s[i] == 'T';
            }
            else {
                return s[i] == 'F';
            }
        }
        int ans = 0;
        for (int k = i + 1; k < j; k += 2) {
            int l_t = solve(s, i, k - 1, true);
            int l_f = solve(s, i, k - 1, false);
            int r_t = solve(s, k + 1, j, true);
            int r_f = solve(s, k + 1, j, false);
            if (s[k] == '&') {
                if (isTrue) {
                    ans = ans + l_t * r_t;
                }
                else {
                    ans = ans + l_t * r_f + l_f * r_t + l_f * r_f;
                }
            }
            else if (s[k] == '|') {
                if (isTrue) {
                    ans = ans + l_t * r_t + l_t * r_f + l_f * r_t;
                }
                else {
                    ans = ans + l_f * r_f;
                }
            }
            else if(s[k] == '^') {
                if (isTrue) {
                    ans = ans + l_t * r_f + l_f * r_t;
                }
                else {
                    ans = ans + l_t * r_t + l_f * r_f;
                }
            }
        }
        return ans;
    }
    int countWays(int N, string S) {
        // code here
        int i = 0; 
        int j = N - 1;
        // we need to evaluate to true
        return solve(S, i, j, true);
    }
};
//opmized memoization
int dp[201][201][3];
class Solution {
public:
    int solve(string s, int i, int j, bool isTrue) {
        if (dp[i][j][isTrue] != -1) {
            return dp[i][j][isTrue];
        }
        if (i > j) {
            return false;
        }
        if (i == j) {
            if (isTrue) {
                dp[i][j][isTrue] = s[i] == 'T';
            }
            else {
                dp[i][j][isTrue] = s[i] == 'F';
            }
            return dp[i][j][isTrue];
        }
        int ans = 0;
        int l_t, l_f, r_t, r_f;
        for (int k = i + 1; k < j; k += 2) {
            if (dp[i][k - 1][true] != -1) {
                l_t = dp[i][k - 1][true];
            }
            else {
                l_t = solve(s, i, k - 1, true);
            }
            if (dp[i][k - 1][false] != -1) {
                l_f = dp[i][k - 1][false];
            }
            else {
                l_f = solve(s, i, k - 1, false);
            }
            if (dp[k + 1][j][true] != -1) {
                r_t = dp[k + 1][j][true];
            }
            else {
                r_t = solve(s, k + 1, j, true);
            }
            if (dp[k + 1][j][false] != -1) {
                r_f = dp[k + 1][j][false];
            }
            else {
                r_f = solve(s, k + 1, j, false);
            }

            if (s[k] == '&') {
                if (isTrue) {
                    ans = ans + l_t * r_t;
                }
                else {
                    ans = ans + l_t * r_f + l_f * r_t + l_f * r_f;
                }
            }
            else if (s[k] == '|') {
                if (isTrue) {
                    ans = ans + l_t * r_t + l_t * r_f + l_f * r_t;
                }
                else {
                    ans = ans + l_f * r_f;
                }
            }
            else if(s[k] == '^') {
                if (isTrue) {
                    ans = ans + l_t * r_f + l_f * r_t;
                }
                else {
                    ans = ans + l_t * r_t + l_f * r_f;
                }
            }
        }
        
        return dp[i][j][isTrue] = ans % 1003;
    }
    int countWays(int N, string S) {
        // code here
        int i = 0; 
        int j = N - 1;
        // we need to evaluate to true
        memset(dp, -1, sizeof(dp));
        return solve(S, i, j, true) % 1003;
    }
};

