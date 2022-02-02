//time: O(n) and space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mes = 0; //max ending so far
        int _max = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            mes += nums[i];
            if (mes < nums[i]) mes = nums[i];
            _max = max(_max, mes);
        }
        return _max;
    }
};
