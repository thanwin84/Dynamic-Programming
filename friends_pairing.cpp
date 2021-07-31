//recursive
//hint: In how many we ways can divide n into two groups. Avoid double counting
//time: O(n) and space: O(n)
long long int dp[1000002];

class Solution
{
public:
	long long int  solve(long long int n) {
		if (dp[n] != -1) {
			return dp[n];
		}
		if (n <= 2) {
			dp[n] = n;
			return n;
		}
		return dp[n] =(( solve(n - 1) % 1000000007) + ((n - 1)% 1000000007) * solve(n - 2) % 1000000007) % 1000000007;
	}
	int countFriendsPairings(int n)
	{
		// code here
		memset(dp, -1, sizeof(dp));
		return solve(n) % 1000000007 ;

	}
};
//top down
long long int dp[1000002];
class Solution
{
public:
	long long int solve(long long int n) {
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] % 1000000007 + (i - 1) * dp[i - 2] % 1000000007;
		}
		return dp[n] % 1000000007;
	}
	int countFriendsPairings(int n)
	{
		// code here
		return solve(n);

	}
};
