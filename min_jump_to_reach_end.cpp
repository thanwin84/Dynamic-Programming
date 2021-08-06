//time: O(n2)
class Solution {
public:

    long long int solve(vector<int>& nums, int curr, vector<int>& dp)
    {
        if (curr >= nums.size() - 1) {
            return 0;
        }
        if (dp[curr] != -1) return dp[curr];
        long long int tmp = INT_MAX;
        for (int i = 1; i <= nums[curr]; i++)
        {
            tmp = min(tmp, 1 + solve(nums, curr + i,  dp));
        }
        dp[curr] = tmp;
        return tmp;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0,  dp);
    }
};
//dynamic approach
//similar to LIS
class Solution {
public:
    int jump(vector<int>& nums) {
		vector<int> track(nums.size() + 1, INT_MAX);
		track[0] = 0;
		int result = INT_MAX;
		for (int i = 1; i <= nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				int possible_ans = 0;
                // checking if we can reach at ith posible from j
				if (j + nums[j] >= i) {
					possible_ans = 1 + track[j];
					track[i] = min(possible_ans, track[i]);
                    break; // the first index will give minimum value
				}
			}
		}
		return track[nums.size() -1];
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
