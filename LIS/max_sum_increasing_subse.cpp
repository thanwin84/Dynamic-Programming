class Solution
{
public:

	int maxSumIS(int a[], int n)
	{
		// your code here
		vector<int> track_sum(n, 0);
		int result = a[0];
		track_sum[0] = result;
		for (int i = 1; i < n; i++) {
			int temp_sum = 0;
			track_sum[i] = a[i];
			for (int j = 0; j < i; j++) {
				if (a[j] > a[i]) continue;
				else if (a[i] > a[j]) {
					temp_sum = a[i] + track_sum[j];
					track_sum[i] = max(temp_sum, track_sum[i]);

				}
			}
			result = max(result, track_sum[i]);
		}
		return result;
	}
};
