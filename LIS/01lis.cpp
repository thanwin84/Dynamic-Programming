// memoization 
int dp[2501];
class Solution {
public:
    int _max;
    int solve(vector<int> &nums, int curr){
        if (curr == 1){
            return 1;
        }
        if (dp[curr] != -1){
            return dp[curr];
        }
        int ans = 1;
        for (int i = 1; i < curr; i++){
            int possibleAns = 1 + solve(nums, i);
            if (nums[curr - 1] > nums[i - 1]){
                ans = max(ans, possibleAns);
            }
            
        }
        _max = max(_max, ans);
        return dp[curr] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
    _max = 1;
    memset(dp, -1, sizeof(dp));
    solve(nums, nums.size());
    return _max;
    
        
    }
};
//time: O(n*n) and space: O(n)


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        int _max = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = 1;
            for (int j = 1; j < i; j++){
                if (nums[i - 1] > nums[j - 1]){
                    int possibleAns = 1 + dp[j];
                    dp[i] = max(dp[i], possibleAns);
                }
            }
            _max = max(_max, dp[i]);
        }
        return _max;
    }
};
//time: O(NlogN)
class Solution {
public:
    int nextGreaterElement(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int ind = 0;
        while (low <= high){
            int mid = (low + high) / 2;
            if (nums[mid] >= target){
                ind = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ind;

    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++){
            if (temp.back() < nums[i]) temp.push_back(nums[i]);
            else if (temp.back() > nums[i]){
                int ind = nextGreaterElement(temp, nums[i]);
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};
