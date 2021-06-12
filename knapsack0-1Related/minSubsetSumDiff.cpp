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
int const D = 10000;
bool dp[1000][1000];
class Solution {
public:
    vector<int> subsetSum(int N, vector<int> arr, int sum) {
        for (int i = 0; i <= N; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= sum; i++) {
            dp[0][i] = false;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        vector<int> subSum;
        for (int i = 0; i <= sum / 2; i++) {
            if (dp[N][i] == true) {
                subSum.push_back(i);
            }
        }
        return subSum;
    };
    int minSubDiff(vector<int>& arr) {
        int range = 0;
        for (auto i : arr) range += i;
        vector<int> subsets = subsetSum(arr.size(), arr, range);
        int result = INT_MAX;
        for (auto i: subsets) {
            result = min(result, abs(range - 2 * i));
        }
        return result;
    }
};
int main() {
    vector<int> arr = { 3, 1, 4, 2, 2, 1 };
    Solution obj;
    cout << obj.minSubDiff(arr)<< endl;
	return 0;
}
