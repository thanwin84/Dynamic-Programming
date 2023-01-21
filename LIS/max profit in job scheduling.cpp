//time: O(n^2) 
// TLE
class Job {
public:
    int startTime;
    int endTime;
    int profit;
    Job(int startTime, int endTime, int profit) {
        this->startTime = startTime;
        this->endTime = endTime;
        this->profit = profit;
    }
};
bool comp(Job p1, Job p2) {
    return p1.startTime < p2.startTime;
}
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int size = startTime.size();
        vector<int> dp(size, 0);
        vector<Job> jobs;
        for (int i = 0; i < size; i++) {
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }
        // sort according to start time
        sort(jobs.begin(), jobs.end(), comp);
        dp[0] = jobs[0].profit;
        int maxProfit = dp[0];
        for (int i = 1; i < size; i++) {
            dp[i] = jobs[i].profit;
            for (int j = 0; j < i; j++) {
                if (jobs[i].startTime >= jobs[j].endTime) {
                    int possibleProfit = dp[j] + jobs[i].profit;
                    dp[i] = max(possibleProfit, dp[i]);
                }
            }
            maxProfit = max(maxProfit, dp[i]);
        }
        return maxProfit;
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
            int excluding_first_job = dp[i -1];
			dp[i] = max(excluding_first_job, include);
			
		}
		return dp[schedules.size() - 1];
	}
};
