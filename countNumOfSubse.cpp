int solve(vector<int> &arr, int indx, int p, int prod) {
	if (indx >= arr.size() and prod >= 0 and prod <= p) {
		return 1;
	}
	if (indx >= arr.size()) return 0;
	int count = 0;
	if (prod == -1) {
		count += solve(arr, indx + 1, p, arr[indx]);
	}
	else {
		count += solve(arr, indx + 1, p, prod * arr[indx]);
	}
	count += solve(arr, indx + 1, p, prod);
	return count;
}
int countSubsequences(vector < int >& a, int n, int p) {
	// Write your code here.
	
	return solve(a, 0, p, -1);
}
