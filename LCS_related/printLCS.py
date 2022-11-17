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
        return dp
    def printLCS(self, text1, text2):
        i = len(text1)
        j = len(text2)
        commonString = ""
        dp = self.longestCommonSubsequence(text1, text2)
        while i > 0 and j > 0:
            if text1[i -1] == text2[j - 1]:
                commonString += text1[i - 1]
                i -= 1
                j -= 1
            else:
                if dp[i - 1][j] >= dp[i][j-1]:
                    i -= 1
                else:
                    j -= 1
        return commonString[::-1]
    
ob = Solution()
X = "AGGTAB"
Y = "GXTXAYB"
print(ob.printLCS(X, Y))

            
