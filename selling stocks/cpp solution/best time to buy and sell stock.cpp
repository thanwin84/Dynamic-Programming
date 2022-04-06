 // algorithm: If I wanna sell at ith day, that means I need to buy the chapest stock from 0 to i - 1th day. This will make sure that we get the maximum profit.
 // time: O(n) and space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int _min = prices[0];
        for (auto curr: prices){
            ans = max(ans, curr - _min);
            // update _min if current price is cheaper 
            _min = min(_min, curr);
        }
        return ans;
    }
};
