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

class Solution {
public:
    bool isMatch(string s, string p) {
        int p_size = p.size();
        int s_size = s.size();
        vector<vector<int>> dp(p_size + 1, vector<int>(s_size + 1, 0));
        for (int i = 0; i <= p_size; i++){
            for (int j = 0; j <= s_size; j++){
                 // both strings are empty
                // that means two string are same
                if (i == 0 && j == 0){
                    dp[i][j] = true;
                }
                // patern is empty and other string is not empty
                // that means this patter doesn't match other string
                else if (i == 0 && j > 0){
                    dp[i][j] = false;
                }
                // if all the character in pattern is *
                // then we can match the empty string with this pattern
                // if any character in this pattern is not equal to *, then 
                // we can't match
                else if (j == 0 && i > 0){
                    bool flag = true;
                    for (int c = 1; c <= i; c++){
                        if (p[c - 1] != '*'){
                            flag = false;
                            break;
                        }
                    }
                    dp[i][j] = flag;
                }
                // if both character is same, we can match
            // if last char of patter is ?, then we can match with single character
                else if (p[i - 1] == s[j - 1] || p[i - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // we can match with 0 characters or more
                else if (p[i - 1] == '*'){
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else dp[i][j] = false;
            }
        }
        return dp[p_size][s_size];
    }
};
//////////////////////////space pptimized to 1d

class Solution {
public:
    bool isMatch(string s, string p) {
        int p_size = p.size();
        int s_size = s.size();
        vector<int> prev(s_size + 1, 0), curr(s_size + 1, 0);
        for (int i = 0; i <= p_size; i++){
            for (int j = 0; j <= s_size; j++){
                 // both strings are empty
                // that means two string are same
                if (i == 0 && j == 0){
                    curr[j] = true;
                }
                // patern is empty and other string is not empty
                // that means this patter doesn't match other string
                else if (i == 0 && j > 0){
                    curr[j] = false;
                }
                // if all the character in pattern is *
                // then we can match the empty string with this pattern
                // if any character in this pattern is not equal to *, then 
                // we can't match
                else if (j == 0 && i > 0){
                    bool flag = true;
                    for (int c = 1; c <= i; c++){
                        if (p[c - 1] != '*'){
                            flag = false;
                            break;
                        }
                    }
                    curr[j] = flag;
                }
                // if both character is same, we can match
                 // if last char of patter is ?, then we can match with single character
                else if (p[i - 1] == s[j - 1] || p[i - 1] == '?'){
                    curr[j] = prev[j - 1];
                }
                // we can match with 0 characters or more
                else if (p[i - 1] == '*'){
                    curr[j] = prev[j] || curr[j - 1];
                }
                else curr[j] = false;
            }
            prev = curr;
        }
        return curr[s_size];
    }
};
