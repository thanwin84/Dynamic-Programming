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
