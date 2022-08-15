// coding ninja solution
#include<bits/stdc++.h>
using namespace std;
long long int solve(vector<int>& nums, int start, int end) {
    // Write your code here.
    long long int prev = nums[start];
    long long int sprev = 0;
    for (int pos = start + 1; pos <= end; pos++) {
        long long int pick = 0;
        long long int not_pick = 0;
        if (pos - 2 >= 0) {
            pick = nums[pos] + sprev;
        }
        else pick = nums[pos];
        not_pick = prev;
        long long int current = max(pick, not_pick);
        sprev = prev;
        prev = current;
        
    }

    return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    long long int chosing_first_house = solve(valueInHouse, 0, n - 2);
    long long int chosing_last_house = n >= 1 ? solve(valueInHouse, 1, n - 1) : 0;
    return max(chosing_first_house, chosing_last_house);
    
}
