// time: O(n) and space: O(n * 2)
int dp[100002][2];
class Solution {
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int pos, int prev1, int prev2, int _swap){
        if (pos == nums1.size()){
            return 0;
        }
        if (dp[pos][_swap] != -1){
            return dp[pos][_swap];
        }
        int swap = INT_MAX;
        int no_swap = INT_MAX;
        if (prev1 < nums1[pos] && prev2 < nums2[pos]){
            no_swap = solve(nums1, nums2, pos + 1, nums1[pos], nums2[pos], 0);
        }
        if (prev1 < nums2[pos] && prev2 < nums1[pos]){
            swap = min(no_swap,1 + solve(nums1, nums2, pos + 1, nums2[pos], nums1[pos], 1));
        }
        return dp[pos][_swap] = min(swap, no_swap);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return solve(nums1, nums2, 0, INT_MIN, INT_MIN, 0);
    }
};
// iterative approach
// time: O(n) and space: O(n)
int dp[100002][2];
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int pos = 1; pos < n; pos++){
            int prevA = nums1[pos -1];
            int prevB = nums2[pos -1];
            dp[pos][0] = INT_MAX;
            dp[pos][1] = INT_MAX;
            if (prevA < nums1[pos] && prevB < nums2[pos]){
                // if we have to swap ith postiton, we also have to swap i-1th, cause swapping may disturb the lis format
                // if we don't swap, we also don't have to swap i-1th 
                dp[pos][0] = dp[pos - 1][0];
                dp[pos][1] = dp[pos - 1][1] + 1;
            }
            if (prevB < nums1[pos] && prevA < nums2[pos]){
                // if we don't swap here, we have to swap i-th, cause adjacent element may not help to make lis
                dp[pos][0] = min(dp[pos - 1][1], dp[pos][0]);
                // if we swap, i - 1th doesn't need to be swapped
                dp[pos][1] = min(dp[pos][1], dp[pos -1][0] + 1);
            }
        }
        return min(dp[n -1][0], dp[n -1][1]);
    }
};
