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
int dp[10000][10000];
class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.
    string lcs(int x, int y, string s1, string s2)
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
        string result;
        int i = x; 
        int j = y;
        while (i > 0 and j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                result += s1[i-1];
                i--;
                j--;
            }
            else {
                if (dp[i][j - 1] > dp[i - 1][j]) {
                    j--;
                }
                else {
                    i--;
                }
            }
        }
        return result;
    }
};
int main() {
    string a = "abc";
    string b = "ac";
    Solution obj;
    string result = obj.lcs(3, 2, a, b);
    for (auto i : result) {
        cout << i << " ";
    }
    return 0;
}
