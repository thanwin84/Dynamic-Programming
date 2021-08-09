# using backtracking - O(2^n)
class Solution:
    def __init__(self):
        self.output = []
        self.dp = {}
    def helper(self, start, end,  n, result, table, s):
        if (start, end) in self.dp:
            return self.dp[(start, end)]
        if end == n:
            self.output.append(result)
            self.dp[(start, end)] = result 
            return

        for index in range(start, n+1):
            if s[start:index] in table:
                self.dp[(start, end)] = self.helper(index, index,  n, result + s[start: index] + ' ',table,  s)
        return False
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        table = {}
        for word in wordDict:
            table[word] = 1
        self.helper(0, 0,  len(s), "", table, s)
        if self.output:
            return True
        return False
