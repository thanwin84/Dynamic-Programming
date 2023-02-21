/////////memoization/////////////////
int dp[2001][2001];
class Solution {
public:
    bool solve(string &p, string &s, int i, int j){
        // both strings are empty
        // that means two string are same
        if (i == 0 && j == 0){
            return true;
        }
        // patern is empty and other string is not empty
        // that means this patter doesn't match other string
        if (i == 0 && j > 0){
            return false;
        }
        if (i > 0 && j == 0){
            // if all the character in pattern is *
            // then we can match the empty string with this pattern
            // if any character in this pattern is not equal to *, then 
            // we can't match
            for (int c = 1; c <= i; c++){
                if (p[c - 1] != '*'){
                    return false;
                }
            }
            // all characters in pattern is *
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        // if both character is same, we can match
        // if last char of patter is ?, then we can match with single character
        if (p[i - 1] == s[j - 1] || p[i - 1] == '?'){
            return dp[i][j] = solve(p, s, i - 1, j - 1);
        }
        if (p[i - 1] == '*'){
            // we can match with 0 characters or more
            return dp[i][j] = solve(p, s, i - 1, j) || solve(p, s, i, j - 1);
        }
        return false;

    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(p, s, p.size(), s.size());
    }
};

// time: O(n *m) and space: O(n * m)

///////////////////////iterative approach/////////////////////
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
