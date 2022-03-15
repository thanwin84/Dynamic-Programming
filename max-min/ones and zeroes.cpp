// memoization solution
//time and space: O(s * n * m)
int dp[601][101][101];
class Solution {
public:
    pair<int, int> countZeroesOnes(string &str){
        int n = str.size();
        int zeroes = 0;
        for (int i = 0; i < n; i++){
            if (str[i] == '0') zeroes++;
        }
        return {zeroes, n - zeroes};
    }
    int solve(vector<string>&strs, int currentInd, int zeroes, int ones){
        // if we are left with zero elements, we can't make subset
        
        if (currentInd < 0){
            return 0;
        }
        if (dp[currentInd][zeroes][ones] != -1){
            return dp[currentInd][zeroes][ones];
        }
        pair<int, int> p =  countZeroesOnes(strs[currentInd]);
        int including = 0, excluding = 0;
        excluding = solve(strs, currentInd - 1, zeroes, ones);
        if (zeroes - p.first >= 0 && ones - p.second >= 0){
            including = 1 + solve(strs, currentInd - 1, zeroes - p.first, ones - p.second);
        }
        return dp[currentInd][zeroes][ones] = max(including, excluding);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(strs, strs.size() -1, m, n);
    }
};
// top down 
int dp[601][101][101];
class Solution {
public:
    pair<int, int> countZeroesOnes(string &str){
        int n = str.size();
        int zeroes = 0;
        for (int i = 0; i < n; i++){
            if (str[i] == '0') zeroes++;
        }
        return {zeroes, n - zeroes};
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        for (int currentInd = 1; currentInd <= strs.size(); currentInd++){
            pair<int, int> p = countZeroesOnes(strs[currentInd-1]);
            for (int zeroes = 0; zeroes <= m; zeroes++){
                for (int ones = 0; ones <= n; ones++){
                    dp[currentInd][zeroes][ones] = 0;
                    int including = 0;
                    int excluding = dp[currentInd - 1][zeroes][ones];
                    if (zeroes - p.first >= 0 && ones - p.second >= 0){
                        including = 1 + dp[currentInd - 1][zeroes - p.first][ones - p.second];
                    }
                    dp[currentInd][zeroes][ones] = max(including, excluding);
                }
            }
        }
        
        return dp[strs.size()][m][n];
    }
};
