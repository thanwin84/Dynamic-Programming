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
int dp[1000][1000];
class Solution {
public:
    int  countSubset(vector<int>& nums, int sum) {
        for (int i = 0; i <= nums.size(); i++) dp[0][i] = 0;
        for (int i = 0; i <= sum; i++) dp[i][0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[nums.size()][sum];
    }
    int count_of_subset_with_given_sum(vector<int>& arr, int diff) {
        int sum = 0;
        for (auto i : arr) sum += i;
        int sum1 = (diff + sum) / 2;
        return countSubset(arr, sum1);
    }
};
int main() {
    vector<int> arr = {1, 1, 2, 3};
    Solution obj;
    cout << obj.count_of_subset_with_given_sum(arr, 1)<< endl;
	return 0;
}
