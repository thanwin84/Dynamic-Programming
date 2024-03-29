//time: O(n2)
int dp[100002][2];
class Solution {
public:
	int AlternatingaMaxLength(vector<int>& nums) {
		// Code here
		dp[0][0] = 1; //larger than previous
		dp[0][1] = 1; // smaller than previous
		int _max = 1;
		for (int i = 1; i < nums.size(); i++) {
			dp[i][0] = 1;
			dp[i][1] = 1;
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j] and dp[i][0] < dp[j][1] + 1) dp[i][0] = dp[j][1] + 1;
				else if (nums[i] < nums[j] and dp[i][1] < dp[j][0] + 1) dp[i][1] = dp[j][0] + 1;
				
			}
			_max = max(_max, max(dp[i][0], dp[i][1]));
		}
		return _max;
	}

};
// Optimized approach
// intuition: finding the number of peak
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		    int increasing = 1;
		    int decreasing = 1;
		    for (int i = 1; i < nums.size(); i++){
		        if (nums[i - 1] < nums[i]) increasing = decreasing + 1;
		        else if (nums[i - 1] > nums[i]) decreasing = increasing + 1;
		    }
		    return max(increasing, decreasing);
		}

};


//time complexity: O(n) and space: O(1)
