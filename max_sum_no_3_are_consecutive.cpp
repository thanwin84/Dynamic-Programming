#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
#define mod 1000000007
using namespace std;

class Solution {
public:
	int solve(vector<int>& arr, int n) {
		if (n <= 0) {
			return 0;
		}
		if (n == 1) {
			return arr[n - 1];
		}
		if (n == 2) {
			return arr[n - 1] + arr[n - 2];
		}
		int included = arr[n - 1] + arr[n -2] + solve(arr, n -3);
		int not_included = solve(arr, n - 1);
		return max(included, not_included);
	}
};
int main() {
	vector<int> arr = { 2, 6, 1, 4, 3, 2};
	Solution ob;
	cout << ob.solve(arr, 6);
	
	
	return 0;
}
