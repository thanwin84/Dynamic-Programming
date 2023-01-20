//time: O(n2)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int> dp(n, 1);
        dp[0] = 1;
        // sort based on first index
        sort(pairs.begin(), pairs.end());
        int _max = 1;
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (pairs[j][1] < pairs[i][0]){
                    int possibleAns = 1 + dp[j];
                    dp[i] = max(possibleAns, dp[i]);
                }
            }
            _max = max(_max, dp[i]);
        }
        return _max;
        
    }
};
//time: O(nlogn)
// greedy approach
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
