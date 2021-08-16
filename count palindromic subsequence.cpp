#define mod 1000000007
using namespace std;
long long int dp[1001][10001];
class Solution {
public:
	long long int  countPS(string s) {
		int n = s.size();
		for (int g = 0; g < n; g++) {
			for (int i = 0, j = g; j < n; i++, j++) {
				if (g == 0) {
					dp[i][j] = 1;
				}
				else if (g == 1 and s[i] != s[j]) {
					dp[i][j] = 2;
				}
				else if (g == 1 and s[i] == s[j]) {
					dp[i][j] = 3;
				}
				else {
					if (s[i] == s[j]) {
						dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1;
					}
					else {
						dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] ;
					}
				}
				dp[i][j] += mod;
				dp[i][j] %= mod;
			}
		}
		return dp[0][n - 1];
	}
};
