# time: O(N^2*K) and space: O(n^2)
class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        self.directions = [[-2, -1], [-2, 1], [-1, 2], [1, 2 ], [2, 1], [2, -1], [1, -2], [-1, -2]];
        self.curr = [[0 for i in range(27)] for j in range(27)];
        self.next = [[0 for i in range(27)] for j in range(27)];
        ans = 0.0
        self.curr[row][column] = 1
        for move in range(k):
            for r in range(n):
                for c in range(n):
                    for direction in range(8):
                        nextRow = r + self.directions[direction][0]
                        nextCol = c + self.directions[direction][1]
                        if nextRow >= 0 and nextRow < n and nextCol >= 0 and nextCol < n:
                            self.next[nextRow][nextCol] += self.curr[r][c] / 8
            self.curr = self.next
            self.next = [[0 for i in range(27)] for j in range(27)];
        
        for i in range(n):
            for j in range(n):
                ans += self.curr[i][j]
                
        return ans
        
