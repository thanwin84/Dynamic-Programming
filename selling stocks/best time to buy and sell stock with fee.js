//************javascript Solution***********************

var maxProfit = function(prices, fee) {
    let dp = [];
    for (let i = 0; i <= prices.length; i++){
        dp[i] = [];
        for (let j = 0; j <= 2; j++){
            dp[i][j] = -1;
        }
    }
    
    function solve(prices, pos, fee, bought){
        if (pos == prices.length){
            return 0;
        }
        if (dp[pos][bought] != -1){
            return dp[pos][bought];
        }
        var skip = solve(prices, pos + 1,fee, bought);
        if (bought){
            var buy = -prices[pos] + solve(prices, pos + 1, fee, 0);
            dp[pos][bought] = Math.max(buy, skip);
            return  dp[pos][bought];
        }
        else {
            var sell = (prices[pos] - fee) + solve(prices, pos + 1, fee, 1);
             dp[pos][bought] = Math.max(sell, skip);
            return dp[pos][bought];
        }
    }
    var result = solve(prices, 0, fee, 1);
    return result;
};
var arr = [1,3,2,8,4,9];
maxProfit(arr, 2);
