class Solution {
    int dp[50];
public:
    int solve(int n, int pos){
        if (pos > n){
            return 0;
        }
        if (pos == n){
            return 1;
        }
        if (dp[pos] != -1){
            return dp[pos];
        }
        int first = solve(n, pos + 1);
        int second = solve(n, pos + 2);
        return dp[pos] = first + second;
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0);
    }
};
//iterative approach
class Solution {
    int dp[50];
public:
    int climbStairs(int n) {
        if (n == 1){
            return 1;
        }
        if (n == 2){
            return 2;
        }
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};
