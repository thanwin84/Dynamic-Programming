//recursive solution
class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    int solve(string s, int i, int j) {
        if (i == j) {
            return 0;
        }
        if (isPalindrome(s, i, j)) {
            return 0;
        }
        int result = INT_MAX;
        for (int k = i; k < j; k++) {
            int left = solve(s, i, k);
            int right = solve(s, k + 1, j);
            int temp_ans = 1 + left + right;
            result = min(temp_ans, result);
        }
        return result;
    }
    int palindromicPartition(string str)
    {
        int i = 0;
        int j = str.size() - 1;
        return solve(str, i, j);
    }
};
//memoization 
int dp[1000][1000];
class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    int solve(string s, int i, int j) {
        if (i == j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (isPalindrome(s, i, j)) {
            return 0;
        }
        int result = INT_MAX;
        for (int k = i; k < j; k++) {
            int left = solve(s, i, k);
            int right = solve(s, k + 1, j);
            int temp_ans = 1 + left + right;
            result = min(temp_ans, result);
        }
        dp[i][j] = result;
        return result;
    }
    int palindromicPartition(string str)
    {
        int i = 0;
        int j = str.size() - 1;
        memset(dp, -1, sizeof(dp));
        return solve(str, i, j);
    }
};
//opmized memoization
int dp[1000][1000];
class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    int solve(string s, int i, int j) {
        if (i == j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (isPalindrome(s, i, j)) {
            return 0;
        }
        int result = INT_MAX;
        int left, right;
        for (int k = i; k < j; k++) {
            if (dp[i][k] != -1) {
                left = dp[i][k];
            }
            else {
                left = solve(s, i, k);
                dp[i][k] = left;
            }
            if (dp[k + 1][j] != -1) {
                right = dp[k + 1][j];
            }
            else {
                right = solve(s, k + 1, j);
                dp[k + 1][j] = right;
            }
            int temp_ans = left + 1 +right;
            result = min(temp_ans, result);
        }
        dp[i][j] = result;
        return result;
    }
    int palindromicPartition(string str)
    {
        int i = 0;
        int j = str.size() - 1;
        memset(dp, -1, sizeof(dp));
        return solve(str, i, j);
    }
};

//for leetcode - more optimized 
int dp[2002][2002];
int dp1[2002][2002];
class Solution {
public:
	bool isPalindrome(string& s, int i, int j) {
		if (i >= j) return true;
		if (dp1[i][j] != -1) return dp1[i][j];
		if (s[i] == s[j]) {
			return dp1[i][j] = isPalindrome(s, i + 1, j - 1);
		}
		else {
			return dp1[i][j] = false;
		}
	}
	int solve(string &S, int i, int j) {
		if (dp[i][j] != -1) {
			return dp[i][j];
		}
		if (i == j) {
			return dp[i][j] = 0;
			
		}
		if (isPalindrome(S, i, j)) {
			return dp[i][j] = 0;
		}
		int min_cut = INT_MAX;
		int left, right;
		for (int k = i; k < j; k++) {
			/*An Optimization: We will make the partition only if the string till the partition
		(till Kth position) is a valid palindrome. Because the question states that all
		partition must be a valid palindrome. If we dont check this, we will have to
		perform recursion on the left subproblem too (solve(str, i, k)) and	we will waste
		a lot of time on subproblems that is not required.*/
			if (isPalindrome(S, i, k)) {
				if (dp[k + 1][j] != -1) {
					right = dp[k + 1][j];
				}
				else {
					right = solve(S, k + 1, j);
					dp[k + 1][j] = right;
				}
			}
			int temp =  1 + right;
			min_cut = min(min_cut, temp);
		}

		return dp[i][j] =  min_cut;
	}
	int minCut(string s) {
		int i = 0;
		int j = s.size() - 1;
		memset(dp, -1, sizeof(dp));
		memset(dp1, -1, sizeof(dp1));
		int result = solve(s, i, j);
		return result;

	}
};
//space optimized
// when we are storing the minimum cuts in dp, the end is always same. so we can avoid using 2d array for dp
int dp[2002];
int dp1[2002][2001];
class Solution {
public:
	bool isPalindrome(string& s, int i, int j) {
		if (i >= j) return true;
		if (dp1[i][j] != -1) return dp1[i][j];
		if (s[i] == s[j]) {
			return dp1[i][j] = isPalindrome(s, i + 1, j - 1);
		}
		else {
			return dp1[i][j] = false;
		}
	}
	int solve(string &S, int i, int j) {
		if (dp[i] != -1) {
			return dp[i];
		}
		if (i == j) {
			return dp[i]= 0;
			
		}
		if (isPalindrome(S, i, j)) {
			return dp[i] = 0;
		}
		int min_cut = INT_MAX;
		int left, right;
		for (int k = i; k < j; k++) {
			/*An Optimization: We will make the partition only if the string till the partition
		(till Kth position) is a valid palindrome. Because the question states that all
		partition must be a valid palindrome. If we dont check this, we will have to
		perform recursion on the left subproblem too (solve(str, i, k)) and	we will waste
		a lot of time on subproblems that is not required.*/
			if (isPalindrome(S, i, k)) {
				if (dp[k + 1] != -1) {
					right = dp[k + 1];
				}
				else {
					right = solve(S, k + 1, j);
					dp[k + 1] = right;
				}
			}
			int temp =  1 + right;
			min_cut = min(min_cut, temp);
		}

		return dp[i] =  min_cut;
	}
	int minCut(string s) {
		int i = 0;
		int j = s.size() - 1;
		memset(dp, -1, sizeof(dp));
		memset(dp1, -1, sizeof(dp1));
		int result = solve(s, i, j);
		return result;

	}
};
