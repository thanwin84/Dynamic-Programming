class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    vector<int> arr;
	    bool all_one = true;
	    for (int i = 0; i < S.size(); i++){
	        if (S[i] == '0') all_one = false;
	        if (S[i] == '0') arr.push_back(1);
	        else arr.push_back(-1);
	    }
	    int mes = 0;
	    int _max = 0;
	    for (int i = 0; i < arr.size(); i++){
	        mes += arr[i];
	        if (mes < arr[i]) mes = arr[i];
	        _max = max(_max, mes);
	    }
	    if (all_one){
	        return -1;
	    }
	    return _max;
	}
};
