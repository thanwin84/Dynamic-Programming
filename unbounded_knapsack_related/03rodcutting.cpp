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
int dp[1002][1002];
class Solution {
public:
    int rod_cutting(vector<int>& prices, vector<int> &lenghts, int length) {
        int N = prices.size();
        for (int i = 0; i <= length; i++) dp[0][i] = 0;
        for (int i = 0; i <= N; i++) dp[i][0] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= length; j++) {
                if (lenghts[i - 1] <= j) {
                    dp[i][j] = max(prices[i - 1] + dp[i][j - lenghts[i - 1]], dp[i - 1][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[N][N];
    }
};
int main() {
    vector<int> l = { 1, 2, 3, 4, 5 , 6,  7,  8 };
    vector<int> p = { 1, 5, 8, 9, 10, 17, 17, 20 };
    Solution obj;
    cout << obj.rod_cutting(p, l, 8)<< endl;
	return 0;
}
//space optimized solution
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++){
            for (int j = 1; j <= i; j++){
                dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
            }
        }
        return dp[n];
    }
};

