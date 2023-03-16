class Solution {
    unordered_map<string, vector<int>> seen;
public:
    vector<int> diffWaysToCompute(string expression){
        if (seen.count(expression)) return seen[expression];
        // we have only single number
        vector<int> result, left, right;
        int num = 0;
        for (int i = 0; i < expression.size(); i++){
            char ch = expression[i];
            if (ch != '+' && ch != '-' && ch != '*'){
                num = (num * 10) + ch - '0';
            }
            else {
                left = diffWaysToCompute(expression.substr(0, i));
                right = diffWaysToCompute(expression.substr(i + 1));
            }
            for (auto l: left){
                for (auto r: right){
                    if (ch == '+') result.push_back(l + r);
                    else if (ch == '*') result.push_back(l * r);
                    else if (ch == '-') result.push_back(l - r);
                }
            }
        }
        // base case
	// single number
        if (result.size() == 0){
            result.push_back(num);
        }
        seen[expression] = result;
        return result;
    }
};
