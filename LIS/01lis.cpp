//time: O(n*n) and space: O(n)
int dp[100002];
class Solution
{
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // your code here
        dp[0] = 1;
        int result = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    int possible_ans = dp[j] + 1;
                    dp[i] = max(dp[i], possible_ans);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
//time: O(NlogN)
class Solution {
public:
	int next_greater_element(vector<int>& arr, int target) {
		int low = 0;
		int high = arr.size();
		int index = 0;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] >= target) {
				index = mid;
				// we can get better ans before mid
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		return index;
	}
	int lengthOfLIS(vector<int>& arr) {
		vector<int> li;
		li.push_back(arr[0]);
		for (int i = 1; i < arr.size(); i++) {
            // if last index of li is less than arr[i], we can push arr[i] to li
            // which will make LIS
			if (li.back() < arr[i]) li.push_back(arr[i]);
			else if (li.back() > arr[i]) {
				int next_greater_index = next_greater_element(li, arr[i]);
				li[next_greater_index] = arr[i];
			}
		}
		return li.size();
	}
};
