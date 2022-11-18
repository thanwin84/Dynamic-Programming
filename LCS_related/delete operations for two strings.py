class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        l1 = len(word1)
        l2 = len(word2)
        dp = [[0 for i in range(l2 + 1)] for i in range(l1 + 1)]
        for i in range(1, l1 + 1):
            dp[i][0] = i
        for i in range(1, l2 + 1):
            dp[0][i] = i
        for i in range(1, l1 + 1):
            for j in range(1, l2 + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    deleting_left = 1 + dp[i - 1][j]
                    deleting_right = 1 + dp[i][j - 1]
                    dp[i][j] = min(deleting_left, deleting_right)
        return dp[l1][l2]
