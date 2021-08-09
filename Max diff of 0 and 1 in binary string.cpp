class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    vector<int> arr;
	    for (int i = 0; i < S.size(); i++){
	        if (S[i] == '0') arr.push_back(1);
	        else arr.push_back(-1);
	    }
	    int max_ending_here = 0;
        int max_so_far = INT_MIN;
        for (int i = 0; i < arr.size(); i++){
            max_ending_here += arr[i];
            if (max_ending_here < arr[i]){
                max_ending_here = arr[i];
            }
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
	}
};
