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
//Algorithm: Palindrone cane be made with odd number of character or even number.
// the idea is to move to left and right from center and check if it's palindrone or not.

// time: O(n^2) and space: O(1)
class Solution {
public:
    pair<int, int> expand_around_center(string& s, int mid, int left, int right) {
        int n = s.size();
        int _max = INT_MIN;
        int start = left;
        int end = right;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > _max) {
                start = left;
                end = right;
                // updating new langht of palindrone
                _max = right - left + 1;
            }
            left--;
            right++;
        }
        return {start, _max};
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int _max = 1;
        // checking for odd number palindrone
        for (int mid = 0; mid < n; mid++) {
            // checking for odd number palindrone
            pair<int, int> odd_palindrone = expand_around_center(s, mid, mid, mid);
            // checking for even number palindrone
            pair<int, int> even_palindrone = expand_around_center(s, mid, mid, mid + 1);
            if (odd_palindrone.second > _max) {
                _max = odd_palindrone.second;
                start = odd_palindrone.first;
            }
            if (even_palindrone.second> _max) {
                _max = even_palindrone.second;
                start = even_palindrone.first;
            }
        }
        string result = s.substr(start, _max);
        return result;
    }
};
