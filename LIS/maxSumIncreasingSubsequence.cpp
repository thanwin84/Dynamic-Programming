# time: O(n2)
int dp[10003];
class Solution
{
public:
	
	int maxSumIS(int a[], int n)
	{
		// your code here
		vector<int> output;
		for (int i = 0; i < n; i++) output.push_back(a[i]);
		dp[0] = 1;
		int result = output[0];
		for (int i = 1; i < n; i++) {
			dp[i] = 1;
			int temp_sum = 0;
			for (int j = 0; j < i; j++) {
				if (a[j] > a[i]) continue;
				else if (a[i] > a[j]) {
					temp_sum = a[i] + output[j];
					output[i] = max(temp_sum, output[i]);
					int possible_ans = dp[j] + 1;
					if (dp[i] < possible_ans) {
						dp[i] = possible_ans;
					}
					
				}
			}
			//keeping track of max sum of [0---i]
			result = max(result, output[i]);
		}
		return result;
	}
};

