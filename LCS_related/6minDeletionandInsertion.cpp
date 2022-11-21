class Solution{
	public:
	int lcs(string &text1, string &text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int left = 1; left <= n1; left++){
            for (int right = 1; right <= n2; right++){
                if (text1[left - 1] == text2[right - 1]){
                    dp[left][right] = 1 + dp[left - 1][right - 1];
                }
                else {
                    dp[left][right] = max(dp[left - 1][right], dp[left][right - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int l1 = str1.size();
	    int l2 = str2.size();
	    int result = lcs(str1, str2);
        int deletion = l1 - result;
        int insertion = l2 - resultl
	    return deletion + insertion;
	    
	    
	} 
};
