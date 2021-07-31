//time: O(n)
#define mod 1000000007
using namespace std;
long long int dp[100002];
class Solution {
public:
	long long countWays(int n, int k) {
		// code here
		dp[0] = 0;
		dp[1] = k;
		dp[2] = k * k;
		for (long long int i = 3; i <= n; i++) {
			dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
		}
		return dp[n] % mod;
	}
};
