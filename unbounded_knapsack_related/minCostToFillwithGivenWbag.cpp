int dp[10000][10000];
class Solution {

public:
    int minimumCost(int cost[], int N, int W)
    {
        // Your code goes here
        vector<int> wt, val;
        int size = 0;
        for (int i = 1; i <= N; i++) {
            if (cost[i-1] != -1){
                val.push_back(cost[i-1]);
                wt.push_back(i);
                size += 1;
            }
            
        }
        for (int i = 0; i <= W; i++) dp[0][i] = 999999999;
        for (int i = 1; i <= size; i++) dp[i][0] = 0;
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= W; j++) {
                if (wt[i - 1] <= j) {
                    dp[i][j] = min(dp[i][j - wt[i - 1]] + val[i - 1], dp[i - 1][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[size][W] == 999999999) {
            return -1;
        }
        return dp[size][W];
    }
};
