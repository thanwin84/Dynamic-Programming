class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, n);
        dp[0] = 0;
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                // we can reach
                if (nums[j] >= i - j){
                    int possibleAns = 1 + dp[j];
                    dp[i] = min(possibleAns, dp[i]);
                }
            }
        }
        return dp[n - 1];
    }
};
