//recursive approach
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
using namespace std;
class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        if (x == 0 || y == 0) {
            return 0;
        }
        if (s1[x - 1] == s2[y - 1]) {
            return 1 + lcs(x - 1, y - 1, s1, s2);
        }
        else {
            return max(lcs(x - 1, y, s1, s2), lcs(x, y - 1, s1, s2));
        }
    }
};
//memoization
int dp[1001][1001];
class Solution {
public:
    int solve(string &text1, string &text2, int left, int right){
        // either one string is empty
        if (left == 0 || right == 0){
            return 0;
        }
        if (dp[left][right] != -1) return dp[left][right];
        // we've found a match
        if (text1[left - 1] == text2[right - 1]){
            return dp[left][right] = 1 + solve(text1, text2, left - 1, right - 1);
        }
        return dp[left][right] =max(solve(text1, text2, left -1, right), solve(text1, text2, left, right - 1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int left = text1.size();
        int right = text2.size();
        memset(dp,-1, sizeof(dp));
        return solve(text1, text2, left, right);
    }
};
//top down approach
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int left = 1; left <= n1; left++){
            for (int right = 1; right <= n2; right++){
                if (text1[left - 1] == text2[right - 1]){
                    dp[left][right] = 1 + dp[left - 1][right - 1];
                }
                else {
                    dp[left][right] = max(dp[left - 1][right], dp[left][right - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};
