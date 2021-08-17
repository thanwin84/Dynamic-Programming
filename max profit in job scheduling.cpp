//time: O(n^2)
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
//time: O(nlogn)
int dp[100000];
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
			schedules.push_back(Pair(endTime[i], startTime[i], profit[i]));
		}
		sort(schedules.begin(), schedules.end(), comp);
		dp[0] = schedules[0].profit;
		int max_profit = dp[0];
		for (int i = 1; i < schedules.size(); i++) {
			int low = 0;
			int high = i-1;
			int last = -1;
			int include = schedules[i].profit;
			while (low <= high) {
				int mid = low + (high - low) / 2;
				if (schedules[mid].end_time <= schedules[i].start_time) {
					last = mid;
					low = mid + 1;
				}
				else {
					high = mid - 1;
				}
			}
			if (last != -1) {
				include += dp[last];
			}
			dp[i] = max(dp[i - 1], include);
			
		}
		return dp[schedules.size() - 1];
	}
};

