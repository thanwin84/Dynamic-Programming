// time: O(allowed * target) and space is also same
long long int dp[31][1001];
class Solution {
public:
    int solve(int dice_value, int allowed, int target){
        if (target == 0 && allowed == 0){
            return 1;
        }
        if (target < 0 || allowed < 0){
            return 0;
        }
        if (dp[allowed][target] != -1){
            return dp[allowed][target] % mod;
        }
        long long int count = 0;
        // we can throw six dice every time
        for (int i = 0; i < dice_value; i++){
            int value = dice_value - i;
            if (value <= target){
                count += solve(dice_value, allowed -1, target - value) % mod;
            }
        }
        return dp[allowed][target] = count % mod;
        
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(k, n, target);
    }
};
