class Solution {
public:
    int superEggDrop(int e, int f) {
        if (e == 1) {
            return f;
        }
        if (f == 0 || f == 1) {
            return f;
        }
        int min_attemp = INT_MAX;
        for (int k = 1; k <= f; k++) {
            int brk = 1 + superEggDrop(e -1, k -1);
            int no_brk = 1 + superEggDrop(e, f - k);
            int temp = max(brk, no_brk);
            min_attemp = min(temp, min_attemp);
        }
        return min_attemp;
    }
};
// memoization and time:O(nk^2)
using namespace std;
int dp[102][10002];
class Solution {
public:
    int solve(int e, int f) {
        if (dp[e][f] != -1) {
            return dp[e][f];
        }
        if (e == 1) {
            return f;
        }
        if (f == 0 || f == 1) {
            return f;
        }
        int min_attemp = INT_MAX;
        for (int k = 1; k <= f; k++) {
            int brk = 1 + solve(e -1, k - 1);
            int no_brk = 1 + solve(e, f - k);
            int temp = max(brk, no_brk);
            min_attemp = min(temp, min_attemp);
        }
        return dp[e][f] = min_attemp;
    }
    int superEggDrop(int e, int f) {
        memset(dp, -1, sizeof(dp));
        return solve(e, f);
    }
};
// time: O(K*N*logN)
// dp with binary search0
int dp[102][10002];
class Solution {
public:
    int solve(int e, int f) {
        if (dp[e][f] != -1) {
            return dp[e][f];
        }
        if (e == 1) {
            dp[e][f] = f;
            return f;
        }
        if (f == 0 || f == 1) {
            dp[e][f] = f;
            return f;
        }
        int min_attemp = INT_MAX;
        int brk, no_brk;
        int low = 1;
        int high = f;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (dp[e - 1][mid - 1] != -1) {
                brk = dp[e - 1][mid - 1];
            }
            brk = 1 + solve(e - 1, mid - 1);
            if (dp[e][f - mid] != -1) {
                no_brk = dp[e][f - mid];
            }
            no_brk = 1 + solve(e, f - mid);
            int temp = max(brk, no_brk);
            min_attemp = min(temp, min_attemp);
            if (brk > no_brk) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return dp[e][f] = min_attemp;
    }
    int superEggDrop(int e, int f) {
        memset(dp, -1, sizeof(dp));
        return solve(e, f);
    }
};

