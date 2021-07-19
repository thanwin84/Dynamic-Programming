int dp[20];
class Solution {
public:
	int solve(int n) {
		if (dp[n] != -1) {
			return dp[n];
		}
		if (n == 1 or n == 0) {
			dp[n] = 1;
			return 1;
		}
		int result = 0;
		int first, second;
		for (int i = 0; i < n; i++) {
			if (dp[i] != -1) {
				first = dp[i];
			}
			else {
				first = numTrees(i);
				dp[i] = first;
			}
			if (dp[n - i - 1] != -1) second = dp[n - i - 1];
			else {
				second = numTrees(n - i - 1);
				dp[n - i - 1] = second;
			}
			result += first * second;
		}
		return dp[n] = result;
	}
	int numTrees(int n) {
		memset(dp, -1, sizeof(dp));
		return solve(n);

	}
};
//top down
int dp[30];
class Solution {
public:
	
	int numTrees(int n) {
		
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
            dp[i] = 0;
			for (int j = 0; j < i; j++) {
				dp[i] += (dp[j] * dp[i - j - 1]);
			}
		}
		return dp[n];

	}
};
