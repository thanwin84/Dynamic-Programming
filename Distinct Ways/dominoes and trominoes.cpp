// time: O(n) and space: O(n * 4)
#define mod 1000000007
class Solution {
    int dp[1001][4];
public:
    int make_state(bool t1, bool t2){
        if (t1 && t2) return 0;
        if (!t1 && !t2) return 1;
        if (t1 && !t2) return 2;
        return 3;
    }
    int solve(int pos, bool t1, bool t2, int n){
        if (pos == n){
            return 1;
        }
        int state = make_state(t1, t2);
        if (dp[pos][state] != -1){
            return dp[pos][state] % mod;
        }
        bool t3 = pos + 1 < n;
        bool t4 = pos + 1 < n;
        // counting how many ways to count the current  position
        long long int count = 0;
        // x x
        // x
        if (t1 && t2 && t3) count += solve(pos + 1, false, true, n) % mod;
        // x
        // x x
        if (t1 && t2 && t4) count += solve(pos + 1, true, false, n) % mod;
        // X X
        // # X
        if (t1 && !t2 && t3 && t4) count +=  solve(pos + 1, false, false, n) % mod;
        // # X
        // X X
        if (!t1 && t2 && t3 && t4) count += solve(pos + 1, false, false, n) % mod;
        // X
        // X
        if (t1 && t2) count += solve(pos + 1, true, true, n) % mod;
        // X X
        // #
        if (t1 && !t2 && t3) count += solve(pos + 1, false, true, n) % mod;
        // #
        // X X
        if (!t1 && t2 && t4) count += solve(pos + 1, true, false, n) % mod;
      // #
      // #
        if (!t1 && !t2) count += solve(pos + 1, true, true, n) % mod;
      // X X
      // X X
        if (t1 && t2 && t3 && t4) count += solve(pos + 1, false, false, n) % mod;
        return dp[pos][state] = count % mod;
        
    }
    int numTilings(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, true, true, n);
    }
};

// another approach
#define mod 1000000007
class Solution {
    long long int dp[1001];
public:
    int numTilings(int n) {
        dp[0] = 1;
        dp[1] = 2; 
        dp[2] = 5;
        for (int i = 3; i < n; i++){
            dp[i] = 2 * dp[i - 1] + dp[i -3];
            dp[i] %= mod;
        }
        return dp[n -1];
    }
};
