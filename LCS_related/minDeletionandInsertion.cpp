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
    pair<int, int> minDeletionInsertion(string S, string s2) {
        // code here
        reverse(S.begin(), S.end());
        for (int i = 0; i <= S.size(); i++) dp[i][0] = 0;
        for (int i = 0; i <= s2.size(); i++) dp[0][i] = 0;
        for (int i = 1; i <= S.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (S[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int deletions = S.size() - dp[S.size()][s2.size()];
        int insertions = s2.size() - dp[S.size()][s2.size()];
        return { deletions, insertions };
    }
};

int main() {
    string a = "heap";
    string b = "pea";
    Solution obj;
    pair<int, int> result =  obj.minDeletionInsertion(a, b);
    cout << result.first << " " << result.second << endl;
    return 0;
}
