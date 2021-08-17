int dp[50009];
struct Pair {
	int start_time;
	int end_time;
	int profit;
	Pair(int end_time, int start_time, int profit) {
		this->start_time = start_time;
		this->end_time = end_time;
		this->profit = profit;
	}
};
bool comp(Pair p1, Pair p2) {
	return p1.end_time < p2.end_time;
}
class Solution {
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		vector<Pair> schedules;
		for (int i = 0; i < profit.size(); i++) {
			schedules.push_back(Pair( endTime[i], startTime[i], profit[i]));
		}
		sort(schedules.begin(), schedules.end(), comp);
		dp[0] = schedules[0].profit;
		int max_profit = dp[0];
		for (int i = 1; i < startTime.size(); i++) {
			dp[i] = schedules[i].profit;
			for (int j = 0; j < i; j++) {
				if (schedules[j].end_time <= schedules[i].start_time) {
					int possible_ans = dp[j] + schedules[i].profit;
					dp[i] = max(possible_ans, dp[i]);
				}
			}
			max_profit = max(max_profit, dp[i]);
		}
		return max_profit;
	}
};
