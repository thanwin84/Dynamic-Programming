#define mod 1000000007
using namespace std;
long long int dp[1002];
class Solution {
public:
    long long int countBT(int h) {
        // code here
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= h; i++) {

            dp[i] = (dp[i - 1] * ((2 * dp[i - 2]) % mod + dp[i - 1]) % mod) % mod;
        }
        return dp[h];
    }
};
