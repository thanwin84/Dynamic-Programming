int dp[30][30];
class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		for (int g = 0; g < nums.size(); g++) {
			for (int i = 0, j = g; j < nums.size(); i++, j++) {
				if (g == 0) {
					dp[i][j] = nums[i];
				}
				else if (g == 1) {
					dp[i][j] = max(nums[i], nums[j]);
				}
				else {
					int value = nums[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
					int value2 = nums[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
					dp[i][j] = max(value, value2);
				}
			}
		}
		int two = 0;
		for (auto i : nums) two += i;
		int one = dp[0][nums.size() - 1];
		two -= one;
		return one >= two;
	}
};
