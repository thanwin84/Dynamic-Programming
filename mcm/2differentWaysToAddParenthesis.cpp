unordered_map<string, vector<int>> dp;
class Solution {
public:
	vector<int> diffWaysToCompute(string expression) {
		if (dp.count(expression)) {
			return dp[expression];
		}
		vector<int> result, left, right;
		int num = 0;
		int size = expression.size();
		for (int i = 0; i < size; i++) {
			char c = expression[i];
			if (c != '*' and c != '+' and c != '-') {
				num = num * 10 + c - '0';
			}
			else {
				if (dp.count(expression.substr(0, i))) {
					left = dp[expression.substr(0, i)];
				}
				else {
					left = diffWaysToCompute(expression.substr(0, i));
				}
				if (dp.count(expression.substr(i + 1))) {
					right = dp[expression.substr(i + 1)];
				}
				else {
					right = diffWaysToCompute(expression.substr(i + 1));
				}
				for (auto l : left) {
					for (auto r : right) {
						if (c == '*') result.push_back(l * r);
						else if (c == '+') result.push_back(l + r);
						else if (c == '-') result.push_back(l - r);
					}
				}
			}
		}
		if (result.size() == 0) {
			result.push_back(num);
		}
		dp[expression] = result;
		return result;

	}
};
