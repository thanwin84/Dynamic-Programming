class Solution {
public:
	int maxGold(int n, int m, vector<vector<int>> &M)
	{
		// code here
		int r = M.size() - 1; // row
		int c = M[0].size() - 1; // col
		int right, dright, ddown;
		for (int col = c -1; col >= 0; col--) {
			for (int row = 0; row <= r; row++) {
				if (row == 0) {
					dright = 0;
				}
				else {
					dright = M[row - 1][col + 1];
				}
				
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
		int result = 0;
		for (int i = 0; i <= r; i++) {
			//cout << M[i][2] << " ";
			if (M[i][0] > result) result = M[i][0];
		}
		return result;
	}
};
