int dp[100002];
class Solution
{
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // your code here
		dp[0] = 1;
		int best = 0;
		for (int i = 1; i < n; i++) {
			dp[i] = 1;
			for (int j = i - 1; j >= 0; j--) {
				if (a[j] > a[i]) {
					continue;
				}
				else if (a[i] > a[j]) {
					int possibleAns = dp[j] + 1;
					if (possibleAns > dp[i]) dp[i] = possibleAns;
					if (dp[i] > best) best = dp[i];
				}
			}
		}
		return best;
    }
};
