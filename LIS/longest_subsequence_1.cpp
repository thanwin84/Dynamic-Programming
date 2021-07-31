class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        // code here
        vector<int> dp(N, 0);
        int ans = 1;
        dp[0] = 1;
        for (int i = 1; i < N; i++){
            dp[i] = 1;
            for (int j = 0; j < i; j++){
                if (abs(A[j] - A[i]) > 1){
                    continue;
                }
                else if (abs(A[j] - A[i]) == 1){
                    int possible_ans = dp[j] + 1;
                    dp[i] = max(possible_ans, dp[i]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    
};
