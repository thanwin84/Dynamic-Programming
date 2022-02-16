//time: O(n2) and space: O(n)
//TLE
class Solution {
public:
    int minJumps(int arr[], int n) {
        // Your code here
        vector<int> dp(n, n + 2);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] >= i - j) {
                    int possible_step = dp[j] + 1;
                    dp[i] = min(possible_step, dp[i]);
                }
            }
        }
        if (dp[n - 1] == n + 2){
            return -1;
        }
        return dp[n - 1];

    }
};
//time: O(n) and space: O(1)
class Solution {
public:
    int minJumps(int arr[], int n) {
        // Your code here
        if (arr[0] == 0 and n > 1) {
            return -1;
        }
        if (n == 1) {
            return 0;
        }
        int jumps = 1;
        int ladder = arr[0]; //keep track of the largest ladder that you have
        int stairs = arr[0]; // keep track of the stairs
        for (int step = 1; step < n; step++) {
            if (step == n - 1) {
                return jumps;
            }
            // if we get a larger ladder, keep it to use later
            if (step + arr[step] > ladder) {
                //constructing the new ladder
                ladder = step + arr[step];
            }
            stairs--;
            if (stairs == 0) {
                //if stairs become 0, we need to jump to another ladder
                jumps++;
                //setting new stairs
                stairs = ladder - step;
            }
            //we can't reach to next step
            if (ladder <= step) {
                return -1;
            }
        }
        return jumps;
    }
};
