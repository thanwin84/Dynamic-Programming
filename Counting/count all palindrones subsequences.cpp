long long int palindrones[1002][1002];
class Solution {
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
        if (palindrones[i][j] != -1) {
            return palindrones[i][j];
        }
        //if first and last character is same, check for the rest subsequences
        // + adding 1 to the result for the current palindrone subsequence
        //we are not substracting the common part here, cause the other common part may contribute to make palindrone with current palindrone
        if (s[i] == s[j]) {
            return palindrones[i][j] = ((solve(s, i + 1, j) % mod + (solve(s, i, j - 1) + 1) % mod)) % mod;
        }
        else {
            //else we check for the rest subsequences - remove the common part since we are counting twice
            return palindrones[i][j] = (mod + (solve(s, i + 1, j) % mod + solve(s, i, j - 1) % mod) - solve(s, i + 1, j - 1) % mod) % mod;
        }
    }
    long long int  countPS(string str)
    {
        //Your code here
        memset(palindrones, -1, sizeof(palindrones));

        return solve(str, 0, str.size() - 1);
    }

};
