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

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        for (int i = 0; i <= str1.size(); i++) dp[i][0] = 0;
        for (int i = 0; i <= str2.size(); i++) dp[0][i] = 0;
        for (int i = 1; i <= str1.size(); i++) {
            for (int j = 1; j <= str2.size(); j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string result;
        int i = str1.size();
        int j = str2.size();
        while (i > 0 and j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--;
                j--;
            }
            else {
                if (dp[i][j - 1] > dp[i - 1][j]) {
                    result += str2[j - 1];
                    j--;
                }
                else {
                    result += str1[i - 1];
                    i--;
                }
            }
        }
        while (i > 0) {
            result += str1[i - 1];
            i--;
        }
        while (j > 0) {
            result += str2[j - 1];
            j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
int main() {
    string a = "abac";
    string b = "cab";
    Solution obj;
    string result = obj.shortestCommonSupersequence(a, b);
    for (auto i : result) {
        cout << i << " ";
    }
    return 0;
}
