//memoization
//time: O(n) and space: O(n)
int dp1[101];
int dp2[101];
class Solution {
public:
    pair<int, int> solve(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& entry, vector<int>& exit, int i, int n) {
        if (i == 0) {
            return { entry[0] + a[0][0] , entry[1] + a[1][0]};
        }
        int initial_cost = 0;
        int first = 0, second = 0, up = 0, down = 0;

        if (dp1[i] != -1) up = dp1[i];
        else {
            if (i == n - 1) initial_cost = exit[0];
            first = initial_cost + a[0][i] + solve(a, t, entry, exit, i - 1, n).first;
            second = initial_cost + a[0][i] + t[1][i] + solve(a, t, entry, exit, i - 1, n).second;
            up = min(first, second);
            dp1[i] = up;
        }
        if (dp2[i] != -1) down = dp2[i];
        else {
            if (i == n - 1) initial_cost = exit[1];
            first = initial_cost + a[1][i] + solve(a, t, entry, exit, i - 1, n).second;
            second = initial_cost + a[1][i] + t[0][i] + solve(a, t, entry, exit, i - 1, n).first;
            down = min(first, second);
            dp2[i] = down;
        }
        return { up, down };
    }
    int car_asembly(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& entry, vector<int>& exit) {
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        pair<int, int> p = solve(a, t, entry, exit, a[0].size() - 1, a[0].size());
        return min(p.first, p.second);
    }
};
//iterative approach 
//time complexity: O(n) and space: O(1)
class Solution {
public:
    int car_assembly(vector<vector<int>>& a, vector<vector<int>>& t, vector<int> entry, vector<int> exit) {
        int n = a[0].size();
        int first = entry[0] + a[0][0];
        int second = entry[1] + a[1][0];
        for (int i = 1; i < n; i++) {
            int up = min(first + a[0][i], second + a[0][i] + t[1][i]);
            int down = min(second + a[1][i], first + a[1][i] + t[0][i]);
            first = up;
            second = down;
        }
        return min(first + exit[0], second + exit[1]);
    }
};
