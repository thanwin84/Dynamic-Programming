#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
#define mod 1000000007
using namespace std;
int dp[201][10002];
class Solution {
public:
    int count_subset(vector<int>& nums, int sum) {
      
        
        for (int i = 0; i <= sum; i++) dp[0][i] = 0;
	// we can always make empty set 
        for (int i = 0; i <= nums.size(); i++) dp[i][0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= sum ; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[nums.size()][sum];

    }
};
int main() {
	Solution ob;
    vector<int> nums = { 1, 2, 3, 3};
    cout << ob.count_subset(nums, 6);
   
	return 0;
}
