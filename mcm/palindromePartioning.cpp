//recursive solution
class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    int solve(string s, int i, int j) {
        if (i == j) {
            return 0;
        }
        if (isPalindrome(s, i, j)) {
            return 0;
        }
        int result = INT_MAX;
        for (int k = i; k < j; k++) {
            int left = solve(s, i, k);
            int right = solve(s, k + 1, j);
            int temp_ans = 1 + left + right;
            result = min(temp_ans, result);
        }
        return result;
    }
    int palindromicPartition(string str)
    {
        int i = 0;
        int j = str.size() - 1;
        return solve(str, i, j);
    }
};
//memoization 
int dp[1000][1000];
class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    int solve(string s, int i, int j) {
        if (i == j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (isPalindrome(s, i, j)) {
            return 0;
        }
        int result = INT_MAX;
        for (int k = i; k < j; k++) {
            int left = solve(s, i, k);
            int right = solve(s, k + 1, j);
            int temp_ans = 1 + left + right;
            result = min(temp_ans, result);
        }
        dp[i][j] = result;
        return result;
    }
    int palindromicPartition(string str)
    {
        int i = 0;
        int j = str.size() - 1;
        memset(dp, -1, sizeof(dp));
        return solve(str, i, j);
    }
};
//opmized memoization
int dp[1000][1000];
class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    int solve(string s, int i, int j) {
        if (i == j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (isPalindrome(s, i, j)) {
            return 0;
        }
        int result = INT_MAX;
        int left, right;
        for (int k = i; k < j; k++) {
            if (dp[i][k] != -1) {
                left = dp[i][k];
            }
            else {
                left = solve(s, i, k);
                dp[i][k] = left;
            }
            if (dp[k + 1][j] != -1) {
                right = dp[k + 1][j];
            }
            else {
                right = solve(s, k + 1, j);
                dp[k + 1][j] = right;
            }
            int temp_ans = left + 1 +right;
            result = min(temp_ans, result);
        }
        dp[i][j] = result;
        return result;
    }
    int palindromicPartition(string str)
    {
        int i = 0;
        int j = str.size() - 1;
        memset(dp, -1, sizeof(dp));
        return solve(str, i, j);
    }
};

