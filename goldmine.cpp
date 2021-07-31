//time: O(n *m) and space: O(1)
class Solution {
public:
	int maxGold(int n, int m, vector<vector<int>> &M)
	{
		// The last columm indicate maxgold miner can collect when he starts
		// We will collect max gold for every index moving back column by column(starting from col == n -1)
		int r = M.size() - 1; // row
		int c = M[0].size() - 1; // col
		int right, dright, ddown;
		for (int col = c -1; col >= 0; col--) {
			for (int row = 0; row <= r; row++) {
				//if row is 0, we cannot go diagonally right
				if (row == 0) {
					dright = 0;
				}
				else {
					dright = M[row - 1][col + 1];
				}
				//In the last row, we cannot go diagonally down
				if (row == r) {
					ddown = 0;
				}
				else {
					ddown = M[row + 1][col + 1];
				}
				right = M[row][col + 1];
				M[row][col] = M[row][col] + max(right, max(dright, ddown));
			}
		}
		// The max value collected will be in the first column
		int result = 0;
		for (int i = 0; i <= r; i++) {
			if (M[i][0] > result) result = M[i][0];
		}
		return result;
	}
};
