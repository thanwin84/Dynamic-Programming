// top down solution
#include<bits/stdc++.h>
using namespace std;

int dp[100001];
int solve(int n, vector<int>& heights) {
    if (n == 0) return 0;
    int left = INT_MAX;
    int right = INT_MAX;
    if (dp[n] != -1) return dp[n];
    left = abs(heights[n] - heights[n - 1]) + solve(n - 1, heights);
    if (n > 1) {
        right = abs(heights[n] - heights[n - 2]) + solve(n - 2, heights);
    }
    return dp[n] = min(left, right);
}
int frogJump(int n, vector<int>& heights)
{
    // Write your code here.
    memset(dp, -1, sizeof(dp));
    return solve(n - 1, heights);

}
// bottom up solution
#include<bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int>& heights)
{
    // Write your code here.
    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++){
        int first_step = INT_MAX;
        int second_step = INT_MAX;
        first_step = abs(heights[i] - heights[i - 1]) + dp[i - 1];
        if (i > 1) second_step = abs(heights[i] - heights[i - 2]) + dp[i - 2];
        dp[i] = min(first_step, second_step);
    }
    return dp[n - 1];

}
// space optized solution
#include<bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int>& heights)
{
    // Write your code here.
    int prev = 0, sprev = 0;
    for (int i = 1; i < n; i++){
        int first_step = INT_MAX;
        int second_step = INT_MAX;
        first_step = abs(heights[i] - heights[i - 1]) + prev;
        if (i > 1) second_step = abs(heights[i] - heights[i - 2]) + sprev;
        int current = min(first_step, second_step);
        sprev = prev;
        prev = current;
    }
    return prev;

}
