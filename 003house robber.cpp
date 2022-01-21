//****top down****/
int dp[101];
class Solution {
public:
    int solve(vector<int> &nums, int i){
        if (i < 0){
            return 0;
        }
        if (dp[i] != -1){
            return dp[i];
        }
        int including = nums[i] + solve(nums, i - 2);
        int excluding = solve(nums, i - 1);
        return dp[i] = max(including, excluding);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, nums.size() -1);
    }
};
//time: O(n) and space: O(n)

//*********iterative appraoch*****//
int dp[101];
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++){
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};
