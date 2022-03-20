// time: O(n * m) and space: O(n * m)
int dp[2001][2001];
class Solution {
public:
    bool solve(string &s, string &p, int i, int j){
        if (i < 0 && j < 0){
            return true;
        }
        if (i >= 0 && j < 0){
            return false;
        }
        if (i < 0 && j >= 0){
            for (int c = 0; c <= j; c++){
                if (p[c] != '*'){
                    return false;
                }
            }
            return true;
        }
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        if (s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(s, p, i - 1, j - 1);
        }
        if (p[j] == '*'){
            return dp[i][j] = solve(s, p, i - 1, j) || solve(s, p, i, j -1);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(s, p, s.size() -1, p.size() -1);
    }
};
// iterative approach
int dp[2001][2001];
class Solution {
public:
    bool isMatch(string s, string p) {
        dp[0][0] = true;
        for (int i = 1; i <= s.size(); i++) dp[i][0] = false;
        for (int i = 1; i <= p.size(); i++){
            bool flag = true;
            for (int j = 1; j <= i; j++){
                if (p[j -1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][i] = flag;
        }
        for (int i = 1; i <= s.size(); i++){
            for (int j = 1; j <= p.size(); j++){
                if (s[i - 1] == p[j -1] || p[j -1] == '?'){
                    dp[i][j] = dp[i - 1][j -1];
                }
                else if (p[j -1] == '*'){
                    dp[i][j] = dp[i - 1][j] || dp[i][j -1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
// space pptimized to 1d
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<int> curr(p.size()+ 1), prev(p.size() + 1);
        prev[0] = true;
        for (int i = 1; i <= p.size(); i++){
            bool flag = true;
            for (int j = 1; j <= i; j++){
                if (p[j -1] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[i] = flag;
        }
        for (int i = 1; i <= s.size(); i++){
            curr[0] = false;
            for (int j = 1; j <= p.size(); j++){
                if (s[i - 1] == p[j -1] || p[j -1] == '?'){
                    curr[j] = prev[j -1];
                }
                else if (p[j -1] == '*'){
                    curr[j] = prev[j] || curr[j -1];
                }
                else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[p.size()];
    }
};
