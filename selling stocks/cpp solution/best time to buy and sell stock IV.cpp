// time: O(n * K) and space: O(k * 2)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(101, vector<int>(2, 0));
        vector<vector<int>> current(101, vector<int>(2, 0));
        for (int currDay = n; currDay >= 0; currDay--){
            for (int trans = 0; trans <= k; trans++){
                for (int bought = 0; bought <= 1; bought++){
                    if (currDay == n || trans == k){
                        current[trans][bought] = 0;
                        
                    }
                    else if (bought){
                        int buy = -prices[currDay] + ahead[trans][false];
                        int skip = ahead[trans][bought];
                        current[trans][bought] = max(buy, skip);
                    }
                    else {
                        int sell = prices[currDay] + ahead[trans + 1][true];
                        int skip = ahead[trans][bought];
                        current[trans][bought] = max(sell, skip);
                    }
                }
            }
            ahead = current;
        }
        return current[0][true];
    }
};
