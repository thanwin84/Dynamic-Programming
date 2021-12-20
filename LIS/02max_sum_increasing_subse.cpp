class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> track_sum(n, 0);
	    track_sum[0] = arr[0];
	    int result = arr[0];
	    for (int i = 1; i < n; i++){
	        track_sum[i] = arr[i];
	        for (int j = 0; j < i; j++){
	            if (arr[i] > arr[j]){
	                int possible_sum = track_sum[j] + arr[i];
	                track_sum[i] = max(possible_sum, track_sum[i]);
	            }
	        }
	        result = max(result, track_sum[i]);
	    }
	    return result;
	}  
};
