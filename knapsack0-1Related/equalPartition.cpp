//top down
int const D = 10000;
bool dp[D][D];
class Solution {
public:
    bool subsetSum(int N, vector<int> arr, int sum) {
        for (int i = 0; i <= N; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= sum; i++) {
            dp[0][i] = false;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[N][sum];
    };
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return 0;
        }
        return subsetSum(N, nums, sum / 2);
        
        
    }
};
