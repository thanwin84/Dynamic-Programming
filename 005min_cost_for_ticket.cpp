//time: O(n)
int dp[367];
class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i) {

        if (i >= days.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        //single day pass
        int single_day = costs[0] + solve(days, costs, i + 1);
        int k = i;
        for (;k < days.size(); k++) {
            if (days[k] >= days[i] + 7) {
                break;
            }
        }
        int one_week = costs[1] + solve(days, costs, k);
        int k2 = i;
        for (; k2 < days.size(); k2++) {
            if (days[k2] >= days[i] + 30) {
                break;
            }
        }
        int one_month = costs[2] + solve(days, costs, k2);
        return dp[i] = min(single_day, min(one_week, one_month));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return solve(days, costs, 0);
    }
};
