//time: O(n^2) and space: O(n)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);
        int _max = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (arr[i] > arr[j]){
                    int possibleAns = 1 + dp1[j];
                    dp1[i] = max(possibleAns, dp1[i]);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--){
            for (int j = n - 1; j > i; j--){
                if (arr[i] > arr[j]){
                    int possibleAns = 1 + dp2[j];
                    dp2[i] = max(possibleAns, dp2[i]);
                } 
            }
	    // we have to make sure that at every peak index we have mountain array
            if (dp1[i] > 1 && dp2[i] > 1){
                _max = max(_max, dp1[i] + dp2[i] - 1);
            }
            
        }
        return n - _max;
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

