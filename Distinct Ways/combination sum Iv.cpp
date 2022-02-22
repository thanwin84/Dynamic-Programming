//top down
class Solution {
    unordered_map<int, int> lookup;
public:
    int solve(vector<int>& nums, int target) {
        if (target == 0) {
            return 1;
        }
        int ans = 0;
        if (lookup.count(target)) {
            return lookup[target];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (target - nums[i] >= 0) {
                ans += solve(nums, target - nums[i]);
            }
        }
        lookup[target] = ans;
        return ans;
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        int result = solve(nums, target);
        return result;
    }
};
//time: O(T*N) and space: O(T) where T is the value of target and N is the size of given array
//iterative approach
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            long long int ans = 0;
            for (int j = 0; j < nums.size(); j++) {
                int current = nums[j];
                if (i >= current) {
                    ans += dp[i - current];
                }
            }
            dp[i] = ans;
           
        }
        return dp[target];
    }
};

