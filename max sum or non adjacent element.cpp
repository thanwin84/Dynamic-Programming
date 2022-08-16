#include <bits/stdc++.h>

using namespace std;
int maximumNonAdjacentSum(vector<int>& nums) {
    // Write your code here.
    vector<int> dp(nums.size() + 1, 0);
    dp[0] = nums[0];
    for (int pos = 1; pos < nums.size(); pos++) {
        int pick = 0;
        int not_pick = 0;
        if (pos - 2 >= 0) {
            pick = nums[pos] + dp[pos - 2];
        }
        else pick = nums[pos];
        not_pick = dp[pos - 1];
        dp[pos] = max(pick, not_pick);
    }

    return dp[nums.size() - 1];
}
// space optmized solution
#include <bits/stdc++.h>

using namespace std;
int maximumNonAdjacentSum(vector<int>& nums) {
    // Write your code here.
    int prev = nums[0];
    int sprev = 0;
    for (int pos = 1; pos < nums.size(); pos++) {
        int pick = 0;
        int not_pick = 0;
        if (pos - 2 >= 0) {
            pick = nums[pos] + sprev;
        }
        else pick = nums[pos];
        not_pick = prev;
        int current = max(pick, not_pick);
        sprev = prev;
        prev = current;
        
    }

    return prev;
}
