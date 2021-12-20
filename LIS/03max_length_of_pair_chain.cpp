//time: O(n2)
int dp[1002];
class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end());
		dp[0] = 1;
		int best_ans = 1;
		for (int i = 1; i < pairs.size(); i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (pairs[i][0] > pairs[j][1]) {
					int possible_ans = 1 + dp[j];
					dp[i] = max(dp[i], possible_ans);
				}
			}
			best_ans = max(dp[i], best_ans);
		}
		return best_ans;
		
	}
};
//time: O(nlogn)
bool comp(vector<int> &p1, vector<int> &p2){
    return p1[1] < p2[1];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int ans = 0;
        int curr = INT_MIN;
        for (int i = 0; i < pairs.size(); i++){
            if (curr < pairs[i][0]){
                curr = pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};
