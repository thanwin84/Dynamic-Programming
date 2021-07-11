bool dp[10000][10000];
class Solution{

  public:
      vector<int> isSubsetSum(int N, int arr[], int sum) {
          // code here 
          for (int i = 0; i <= N; i++) dp[i][0] = true;
          for (int i = 1; i <= sum; i++) dp[0][i] = false;
          for (int i = 1; i <= N; i++) {
              for (int j = 1; j <= sum; j++) {
                  if (arr[i - 1] <= j) {
                      dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                  }
                  else {
                      dp[i][j] = dp[i - 1][j];
                  }
              }
          }
          vector<int> output;
          for (int i = 0; i <= sum / 2; i++) {
              if (dp[N][i] == true) {
                  output.push_back(i);
              }
          }
          return output;
      }
    int minDifference(int arr[], int n) {
        // Your code goes here
        if (n == 1){
            return arr[0];
        }
        int result = INT_MAX;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        vector<int> sum_list = isSubsetSum(n, arr, sum);
        for (auto i : sum_list) {
            result = min(result, abs(sum - 2 * i));
        }
        return result;
    }
};
