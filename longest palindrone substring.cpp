int palindrones[1001][1001];
int dp[1001];
class Solution {
    int _max = 0;
    int start = 0, end = 0;
public:
    bool is_palindrone(string& s, int i, int j) {
        if (i >= j) return true;
        if (palindrones[i][j] != -1) return palindrones[i][j];
        if (s[i] == s[j]) {
            return palindrones[i][j] = is_palindrone(s, i + 1, j - 1);
        }
        else {
            return palindrones[i][j] = false;
        }
    }
    int solve(string& s, int i, int j) {
        if (i == j) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        if (is_palindrone(s, i, j)) {
            if (j - i + 1 > _max){
                start = i;
                end = j;
                _max = j - i + 1;
            }
            return 0;
        }
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            if (is_palindrone(s, i, k)) {
                int temp = 1 + solve(s, k + 1, j);
                ans = min(temp, ans);
                if (k - i + 1 > _max) {
                    _max = k - i + 1;
                    start = i;
                    end = k;
                }

            }
        }
        return dp[i] = ans;
    }
    string longestPalindrome(string s) {
        if (s.size() == 1){
            return s;
        }
        memset(palindrones, -1, sizeof(palindrones));
        memset(dp, -1, sizeof(dp));
        int res = solve(s, 0, s.size() - 1);
        string longest_palindrone = s.substr(start, _max);
        return longest_palindrone;
    }
};
//time: O(n^2) and space: O(n^2)

//space optimized solution
// time: O(n^2) and space: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int end = 0;
        int _max = 1;
        for (int m = 0; m < n; m++) {
            int i = m;
            int j = m;
            while (i >= 0 && j < n && s[i] == s[j]) {
                if (j - i + 1 > _max) {
                    start = i;
                    end = j;
                    _max = j - i + 1;
                }
                i--;
                j++;
            }
        }
        for (int m = 0; m < n; m++) {
            int i = m;
            int j = m + 1;
            while (i >= 0 && j < n && s[i] == s[j]) {
                if (j - i + 1 > _max) {
                    start = i;
                    end = j;
                    _max = j - i + 1;
                }
                i--;
                j++;
            }
        }
        string result = s.substr(start, _max);
        return result;
    }
};
