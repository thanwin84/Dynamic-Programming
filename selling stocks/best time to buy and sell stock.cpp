class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int _min = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            _min = min(_min, prices[i]);
            profit = max(profit, prices[i] - _min);
        }
        return profit;
    }
};
