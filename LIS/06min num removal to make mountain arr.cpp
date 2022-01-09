//time: O(n^2) and space: O(n)
using namespace std;
class Solution {
public:
	vector<int> LIS(vector<int> &arr)
	{
		// your code here
		int n = arr.size();
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		int best = 0;
		for (int i = 1; i < n; i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (arr[j] > arr[i]) {
					continue;
				}
				else if (arr[i] > arr[j]) {
					int possibleAns = dp[j] + 1;
					if (possibleAns > dp[i]) dp[i] = possibleAns;
					if (dp[i] > best) best = dp[i];
				}
			}
		}
		return dp;
	}
	int minimumMountainRemovals(vector<int>& arr) {
		vector<int> reversed_arr;
		for (int i = arr.size() - 1; i >= 0; i--) reversed_arr.push_back(arr[i]);
		vector<int> dp1 = LIS(arr);
		vector<int> dp2 = LIS(reversed_arr);
		int ans = INT_MIN;
		for (int i = 1; i < arr.size() - 1; i++) {
            if (dp1[i] > 1 and dp2[arr.size() - i -1] > 1){
                int temp =dp1[i] + dp2[arr.size() - i - 1] - 1;
			    ans = max(ans, temp);
            }
		}
		return arr.size() - ans;
	}
	
};
//time: O(nlogn)
class Solution {
public:
    int next_greater_element_index(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size();
        int index = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                index = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return index;
    }
    vector<int> LIS(vector<int>& arr) {
        vector<int> seq;
        vector<int> dp;
        dp.push_back(1);
        seq.push_back(arr[0]);
        for (int i = 1; i < arr.size(); i++) {
            if (seq.back() < arr[i]) {
                seq.push_back(arr[i]);
            }
            else if (seq.back() > arr[i]) {
                int indx = next_greater_element_index(seq, arr[i]);
                seq[indx] = arr[i];
            }
            dp.push_back(seq.size());
        }
        return dp;
    }
    int minimumMountainRemovals(vector<int>& arr) {
        vector<int> reversed_arr;
        for (int i = arr.size() - 1; i >= 0; i--) reversed_arr.push_back(arr[i]);
        vector<int> dp1 = LIS(arr);
        vector<int> dp2 = LIS(reversed_arr);
        int ans = INT_MIN;
        for (int i = 1; i < arr.size() - 1; i++) {
            if (dp1[i] > 1 and dp2[arr.size() - i - 1] > 1) {
                int temp = dp1[i] + dp2[arr.size() - i - 1] - 1;
		// take max increasing subsequene 
                ans = max(ans, temp);
            }
        }
	// if we subtract the max LIS from array size, we will get min number of removal
        return arr.size() - ans;
    }

};

