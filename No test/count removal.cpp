using namespace std;
int count_removal(vector<int>& arr, int i, int j, int k) {
	if (i >= j) {
		return 0;
	}
	if (arr[j] - arr[i] < k) {
		return 0;
	}
	else if (arr[j] - arr[i] >= k) {
		int remove_from_left = 1 + count_removal(arr, i + 1, j, k);
		int remove_from_right = 1 + count_removal(arr, i, j - 1, k);
		return min(remove_from_left, remove_from_right);
	}

}
int main() {
	vector<int> arr = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
	sort(arr.begin(), arr.end());
	cout << count_removal(arr, 0, arr.size() - 1, 4);
    
	return 0;
}
