//time complecity: O(n^2) and space complexity: O(n)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);
        int _max = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (arr[i] > arr[j]){
                    int possibleAns = 1 + dp1[j];
                    dp1[i] = max(possibleAns, dp1[i]);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--){
            for (int j = n - 1; j > i; j--){
                if (arr[i] > arr[j]){
                    int possibleAns = 1 + dp2[j];
                    dp2[i] = max(possibleAns, dp2[i]);
                } 
            }
	    // we have to make sure that at every peak index we have mountain array
            if (dp1[i] > 1 && dp2[i] > 1){
                _max = max(_max, dp1[i] + dp2[i] - 1);
            }
            
        }
        return n - _max;
    }
};
//time: O(nlogn) and space complexity: O(n)
class Solution {
public:
    int nextGreaterIndex(vector<int> &nums, int target){
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
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> v1;
        // store lis here
        vector<int> lis(n, 1);
        v1.push_back(nums[0]);
	// increasing to backward
        for (int i = 1; i < n; i++){
            if (nums[i] > v1.back()) v1.push_back(nums[i]);
            else {
                int ind = nextGreaterIndex(v1, nums[i]);
                v1[ind] = nums[i];
            }
            lis[i] = v1.size();
        }
        vector<int> v2;
        v2.push_back(nums[n - 1]);
        int ans = 0;
	// increasing to forward
        for (int i = n - 2; i >= 0; i--){
            if (nums[i] > v2.back()) v2.push_back(nums[i]);
            else {
                int ind = nextGreaterIndex(v2, nums[i]);
                v2[ind] = nums[i];
                int lis = v2.size();
            }
            if (lis[i] > 1 && v2.size() > 1){
                int possibleAns = lis[i] + v2.size() - 1;
                ans = max(ans, possibleAns);
            }
        }
        return n - ans;
    }
};

