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
		int best = 0;
		for (int i = 1; i < n; i++) {
			dp[i] = 1;
			for (int j = i - 1; j >= 0; j--) {
				if (a[j] > a[i]) {
					continue;
				}
				else if (a[i] > a[j]) {
					int possibleAns = dp[j] + 1;
					if (possibleAns > dp[i]) dp[i] = possibleAns;
					if (dp[i] > best) best = dp[i];
				}
			}
		}
		return best;
    }
};
//time: O(NlogN)
class Solution
{
public:
	//Function to find length of longest increasing subsequence.
	int bs(vector<int> &arr, int X) {
		int low = 0;
		int high = arr.size() - 1;
		int index = 0;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] >= X) {
				index = mid;
				high = mid - 1;

			}
			else {
				low = mid + 1;
			}
		}
		return index;
	}
	int longestSubsequence(int n, int a[])
	{
		// your code here
		vector<int> lis;
		lis.push_back(a[0]);
		for (int i = 1; i < n; i++) {
			// if the last element in lis is smaller than a[i],
			//then a[i] will make longest increasing subsequence with lis
			if (lis.back() < a[i]) {
				lis.push_back(a[i]);
			}
			// if a[i] is bigger than lis[back], search for the next greater element than a[i]
			// after that replace with a[i]
			else if(lis.back() > a[i]) {
				int index = bs(lis, a[i]);
				lis[index] = a[i];
			}
		}
		return lis.size();
	}
};
