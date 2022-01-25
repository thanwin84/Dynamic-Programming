//time: O(n2) and space: O(n)
//TLE
class Solution {
public:
    int minJumps(int arr[], int n) {
        // Your code here
        vector<int> dp(n, n + 2);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] >= i - j) {
                    int possible_step = dp[j] + 1;
                    dp[i] = min(possible_step, dp[i]);
                }
            }
        }
        if (dp[n - 1] == n + 2){
            return -1;
        }
        return dp[n - 1];

    }
};
//time: O(n) and space: O(1)
class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1) {
			return 0;
		}
		int ladder = nums[0]; // keep track of the largest ladder that you have
		int stairs = nums[0]; // Also keep track of the stairs in the ladder
		int jumps = 1;
		for (int level = 1; level < nums.size(); level++) {
			// if we are at the last stair, we don't need to jump 
			if (level == nums.size() - 1) {
				return jumps;
			}
			//if we get a larger ladder, save it for later
			if (level + nums[level] > ladder) {
				//constructing the ladder
				ladder = level + nums[level];
			}
			stairs--;
			if (stairs == 0) {
				jumps++;
				// set new stairs
				stairs = ladder - level;
			}

		}
		return jumps;
	}
};
