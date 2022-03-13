# O(n^2) and space: O(n)
# TLE
class Solution:
    def numSquares(self, n: int) -> int:
        perfect_squares = [n for i in range(n + 1)]
        perfect_squares[0] = 0
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                if (j * j) <= i:
                    possible_ans = 1 + perfect_squares[i - (j * j)]
                    perfect_squares[i] = min(possible_ans, perfect_squares[i])
                else:
                    break
        return perfect_squares[n]
