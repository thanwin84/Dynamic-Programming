class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        vector<vector<int>> profit(days + 1, vector<int>(2, 0));
        for (int day = days - 1; day >= 0; day--){
            for (int bought = 0; bought <= 1; bought++){
                int skip = profit[day + 1][bought];
                if (bought){
                    int buy = -prices[day] + profit[day + 1][false];
                    profit[day][bought] = max(buy, skip);
                }
                else {
                    int sell = prices[day];
                    if (day + 2 <= days) {
                        sell = prices[day] + profit[day + 2][true];
                    }
                    profit[day][bought] = max(sell, skip);
                }
                
            }
        }
        return profit[0][true];
    }
};

// space optimized solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        vector<int> ahead(2, 0), ahead2(2, 0), current(2, 0);
        for (int day = days - 1; day >= 0; day--){
            for (int bought = 0; bought <= 1; bought++){
                int skip = ahead[bought];
                if (bought){
                    int buy = -prices[day] + ahead[false];
                    current[bought] = max(buy, skip);
                }
                else {
                    int sell = prices[day];
                    if (day + 2 <= days) {
                        sell = prices[day] + ahead2[true];
                    }
                    current[bought] = max(sell, skip);
                }
                
            }
            ahead2 = ahead;
            ahead = current;
        }
        return ahead[true];
    }
};
