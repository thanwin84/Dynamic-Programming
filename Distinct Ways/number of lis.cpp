// time: O(n^2) and space: O(n)
struct Pair {
    int lis;
    int count_of_lis;
    Pair(int lis, int count_of_lis) {
        this->lis = lis;
        this->count_of_lis = count_of_lis;
    }
};
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<Pair> dp(size, Pair(1, 1));
        int max_lis = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    int possible_lis = dp[j].lis + 1;
                    // we've got new length of LIS
                    if (possible_lis > dp[i].lis) {
                        dp[i].lis = possible_lis;
                        // current element: nums[j]
                        // since current element will help to make new LIS with nums[i], the total count of new LIS will be
                        // equal to the number of current element's LIS
                        dp[i].count_of_lis = dp[j].count_of_lis;
                    }
                    // it means, we've already seen this lenght
                    // so just increase the "count_of_lis"
                    else if (possible_lis == dp[i].lis) {
                        dp[i].count_of_lis += dp[j].count_of_lis;
                    }
                }
            }
            max_lis = max(max_lis, dp[i].lis);
        }
        int number_of_lis = 0;
        // sum up all the LIS
        for (int i = 0; i < size; i++) {
            if (dp[i].lis == max_lis) number_of_lis += dp[i].count_of_lis;
        }
        return number_of_lis;
    }
};
// One pass solution
struct Pair {
    int lis;
    int count_of_lis;
    Pair(int lis, int count_of_lis) {
        this->lis = lis;
        this->count_of_lis = count_of_lis;
    }
};
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<Pair> dp(size, Pair(1, 1));
        int max_lis = 1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    int possible_lis = dp[j].lis + 1;
                    // we've got new length of LIS
                    if (possible_lis > dp[i].lis) {
                        dp[i].lis = possible_lis;
                        // current element: nums[j]
                        // since current element will help to make new LIS with nums[i], the total count of new LIS will be
                        // equal to the number of current element's LIS
                        dp[i].count_of_lis = dp[j].count_of_lis;
                    }
                    // it means, we've already seen this lenght
                    // so just increase the "count_of_lis"
                    else if (possible_lis == dp[i].lis) {
                        dp[i].count_of_lis += dp[j].count_of_lis;
                    }
                }
            }
            // if we get new lis, update max_lis to new lis and update count
            if (max_lis < dp[i].lis){
                max_lis = dp[i].lis;
                count = dp[i].count_of_lis;
            }
            // if we've seen before, just increase the counter
            else if (max_lis == dp[i].lis){
                count += dp[i].count_of_lis;
            }
        }
        
        return count;
    }
};
