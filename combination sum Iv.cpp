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
//time: O(n^2) and space: O(T) where T is the value of target
