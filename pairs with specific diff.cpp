//time: O(nlogn) and space: O(1)
class Solution {
public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here   
        sort(arr, arr + N);
        int i = N - 1;
        int sum = 0;
        while (i > 0) {
            if (arr[i] - arr[i - 1] < K) {
                sum += arr[i] + arr[i - 1];
                i -= 2;
            }
            else {
                i--;
            }
        }
        return sum;
    }
};
