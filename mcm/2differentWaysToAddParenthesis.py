class Solution:
    def __init__(self):
        self.dp = {}
    def diffWaysToCompute(self, expression):
        if expression in self.dp:
            return self.dp[expression]
        else:
            result = []
            num = 0
            for i in range(len(expression)):
                c = expression[i]
                if c != '*' and c != '-' and c != '+':
                    num = num * 10 + int(c)
                else:
                    if expression[: i] in self.dp:
                        left = self.dp[expression[: i]]
                    else:
                        left = self.diffWaysToCompute(expression[: i])
                    if expression[i + 1:] in self.dp:
                        right = self.dp[expression[i + 1:]]
                    else:
                        right = self.diffWaysToCompute(expression[i + 1:])
                    for l in left:
                        for r in right:
                            if c == '*':
                                result.append(l * r)
                            elif c == '+':
                                result.append(l + r)
                            else:
                                result.append(l - r)
            if len(result) == 0:
                result.append(num)
                self.dp[expression] = result
            return result
