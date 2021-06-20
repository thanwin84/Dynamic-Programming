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
int dp[10000][10000];
class Solution
{
public:
    int solve(int x, int y, string &s1, string &s2) {
        if (x == 0 || y == 0) {
            return 0;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        else {
            if (s1[x - 1] == s2[y - 1]) {
                dp[x][y] =  1 + lcs(x - 1, y - 1, s1, s2);
            }
            else {
                dp[x][y] = max(lcs(x - 1, y, s1, s2), lcs(x, y - 1, s1, s2));
            }
            return dp[x][y];
        }
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= y; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(x, y, s1, s2);
    }
};
//top down approach
int dp[10000][10000];
class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        for (int i = 0; i <= x; i++) dp[0][i] = 0;
        for (int i = 0; i <= y; i++) dp[i][0] = 0;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[x][y];
    }
};
