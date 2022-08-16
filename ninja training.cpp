//time: O(n * 4) * 3 and space: O(n * 4) and stack space is: O(N)
#include<bits/stdc++.h>
using namespace std;
int dp[100001][3];
int solve(vector<vector<int>> &points, int currDay, int lastDayTask){
    if (currDay == 0){
        int _max = 0;
        for (int task = 0; task < 3; task++){
           if (lastDayTask != task){
               _max = max(points[0][task], _max);
           }
       }
        return dp[currDay][lastDayTask] = _max;
    }
    if (dp[currDay][lastDayTask] != -1) return dp[currDay][lastDayTask];
    int _max = 0;
    for (int task = 0; task < 3; task++){
        if (lastDayTask != task){
            int point = points[currDay][task] + solve(points, currDay - 1, task);
            _max = max(_max, point);
        }
    }
    return dp[currDay][lastDayTask] = _max;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    memset(dp, -1, sizeof(dp));
    return solve(points, n - 1, 3);
    
}
// bottom up solution
#include<bits/stdc++.h>
using namespace std;
int dp[100001][4];
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][2], points[0][0]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    for (int currDay = 1; currDay < n; currDay++){
        for(int lastTask = 0; lastTask <= 3; lastTask++){
            int _max = 0;
            for (int task = 0; task < 3; task++){
                if (lastTask != task){
                    int point = points[currDay][task] + dp[currDay - 1][task];
                    _max = max(point, _max);
                }
            }
            dp[currDay][lastTask] = _max;
        }
    }
    return dp[n - 1][3];
    
}
// space otimized to O(4)
#include<bits/stdc++.h>
using namespace std;
int dp[100001][4];
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int> curr(4, 0);
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][2], points[0][0]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    for (int currDay = 1; currDay < n; currDay++){
        for(int lastTask = 0; lastTask <= 3; lastTask++){
            int _max = 0;
            for (int task = 0; task < 3; task++){
                if (lastTask != task){
                    int point = points[currDay][task] + prev[task];
                    _max = max(point, _max);
                }
            }
            curr[lastTask] = _max;
        }
        prev = curr;
    }
    return prev[3];
    
}
