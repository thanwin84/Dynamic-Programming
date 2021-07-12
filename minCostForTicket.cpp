int dp[367];
class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i) {
        if (dp[i] != -1) {
            return dp[i];
        }
        if (i >= days.size()) {
            return 0;
        }
        int opt1 = costs[0] + solve(days, costs, i + 1);
        int k = i;
        for (; k < days.size(); k++) {
            if (days[k] >= days[i] + 7) {
                break;
            }
        }
        int opt2 = costs[1] + solve(days, costs, k);
        int k1 = i;
        for (; k1 < days.size(); k1++) {
            if (days[k1] >= days[i] + 30) {
                break;
            }
        }
        int opt3 = costs[2] + solve(days, costs, k1);
        return dp[i] = min(opt1, min(opt2, opt3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        int i = 0;
        return solve(days, costs, i);
    }
};
