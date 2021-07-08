#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    int solve(string s, int i, int j) {
        if (i == j) {
            return s[i] - '0';
        }
        int min_value = INT_MAX;
        int max_value = INT_MIN;
        int temp;
        for (int k = i + 1; k < j; k += 2) {
            int left = solve(s, i, k - 1);
            int right = solve(s, k + 1, j);
            if (s[k] == '+') {
                temp = left + right;
            }
            else if (s[k] == '*') {
                temp = left * right;
            }
            min_value = min(temp, min_value);
        }
        return min_value;
    }
    int min_value(string s) {
        int i = 0;
        int j = s.size() - 1;
        return solve(s, i, j);
    }
};
int main() {
    string a = "1+2*3+4*5";
    Solution obj;
    cout << obj.min_value(a) << endl;
    return 0;
}
