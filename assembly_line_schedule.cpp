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
#define num_station 4
using namespace std;
class Solution {
public:
	int carAssembly(int a[][num_station], int T[][num_station], int e[], int exit[]) {
		int T1[num_station];
		int T2[num_station];
		//Entry cost
		T1[0] = e[0] + a[0][0];
		T2[0] = e[1] + a[1][0];
		for (int i = 1; i < num_station; i++) {
			//go to another station in the same line, if we get better cost in second line then go to second line and vice versa
			T1[i] = min(a[0][i] + T1[i - 1], a[0][i] + T2[i - 1] + T[1][i]);
			T2[i] = min(a[1][i] + T2[i - 1], a[1][i] + T1[i - 1] + T[0][i]);
		}
		return min(T1[num_station -1] + exit[0], T2[num_station - 1] + exit[1]);
	}
};

int main() {
	
	Solution ob;
	int a[][4] = { { 4, 5, 3, 2 },
				   { 2, 10, 1, 4 } };
	int t[][4] = { { 0, 7, 4, 5 },
				   { 0, 9, 2, 8 } };
	int e[] = { 10, 12 };
	int x[] = { 18, 7 };
	cout << ob.carAssembly(a, t, e, x);
	return 0;
}
