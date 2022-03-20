class Solution {
    unordered_map<string, int> seen;
    int dp[1001][1001];
public:
    int solve(int n, int i, int j){
        if (i > n){
            return  INT_MAX -2;
        }
        if (i == n){
            return 0;
        }
        string key = to_string(i) + "-" + to_string(j);
        if (seen.count(key)) return INT_MAX -2;
        seen[key] = 1;
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        int copy = solve(n, i, i);
        int paste = solve(n, i + j, j);
        return  dp[i][j] = 1 + min(copy, paste);
    }
    int minSteps(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 1, 0);
    }
};
