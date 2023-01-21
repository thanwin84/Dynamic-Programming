#include <bits/stdc++.h> 
int longestBitonicSequence(vector<int>& arr, int n) {
	  // Write your code here.	
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
        _max = max(_max, dp1[i] + dp2[i] - 1);
    }
    
    return _max;
} 
