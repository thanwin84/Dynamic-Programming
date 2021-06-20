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
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s1, string s2, int x, int y)
    {
        //code here
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
        return (s1.size() + s2.size()) - dp[x][y];
    }
};
