class Solution:
    def solve(self, nums, i, j, chance, dp):
        if (dp[i][j] != -1):
            return dp[i][j]
        if (i > j):
            return 0
        if chance == 0:
            dp[i][j] = max(nums[i] + self.solve(nums, i + 1, j, 1, dp), 
                       nums[j] + self.solve(nums, i, j -1, 1, dp))
        else: 
            dp[i][j] = min(self.solve(nums, i + 1, j, 0, dp), 
                       self.solve(nums, i, j -1, 0, dp))
        return dp[i][j]
    def PredictTheWinner(self, nums: List[int]) -> bool:
        two = sum(nums)
        dp = [[-1 for i in range(len(nums) + 1)]for j in range(len(nums) + 1)]
        one = self.solve(nums, 0, len(nums)-1, 0, dp)
        two -= one
        return one >= two
        
