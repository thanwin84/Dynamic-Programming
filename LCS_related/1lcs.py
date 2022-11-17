class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n1 = len(text1)
        n2 = len(text2)
        dp = [[0 for i in range(n2 + 1)] for i in range(n1 + 1)]
        for left in range(1, n1 + 1):
            for right in range(1, n2 + 1):
                if text1[left - 1] == text2[right - 1]:
                    dp[left][right] = 1 + dp[left - 1][right - 1]
                else:
                    dp[left][right] = max(dp[left - 1][right], dp[left][right - 1])
        return dp[n1][n2]
