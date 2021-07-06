//recursive
class Solution {
public:
    int Solve(int arr[], int i, int j) {
        if (i >= j) {
            return 0;
        }
        int _min = INT_MAX;
        for (int k = i; k < j; k++) {
            int left = Solve(arr, i, k);
            int right = Solve(arr, k + 1, j);
            int cost = arr[i - 1] * arr[k] * arr[j];
            int temp_ans = left + right + cost;
            _min = min(temp_ans, _min);
        }
        return _min;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i = 1;
        int j = N - 1;
        int result = Solve(arr, i, j);
        return result;
    }
};
