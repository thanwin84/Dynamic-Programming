//time: O(n^2) and space: O(n^2)
long long int dp[1002][1002];
class Solution{
    long long int mod = 1000000007;
    public:
        /*You are required to complete below method */
        long long int solve(string& s, int i, int j) {
            if (i > j) {
                return 0;
            }
            if (i == j) {
                return 1;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            if (s[i] == s[j]) {
                return dp[i][j] = ((solve(s, i + 1, j) % mod + (solve(s, i, j - 1) + 1) % mod)) % mod;
            } 
            else {
                return dp[i][j] = (mod + (solve(s, i + 1, j) % mod + solve(s, i, j - 1) % mod) - solve(s, i + 1, j - 1) % mod) % mod;
            }
        }
        long long int  countPS(string str)
        {
            //Your code here
            memset(dp, -1, sizeof(dp));
            
            return solve(str, 0, str.size() - 1);
         }

};
