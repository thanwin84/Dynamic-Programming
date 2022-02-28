// ***************top down approach*******
long long int palindrones[1002][1002];
class Solution {
    long long int mod = 1000000007;
public:
    /*You are required to complete below method */
    long long int solve(string& s, int i, int j) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (palindrones[i][j] != -1) {
            return palindrones[i][j];
        }
        //if first and last character is same, check for the rest subsequences
        // + adding 1 to the result for the current palindrone subsequence
        //we are not substracting the common part here, cause the other common part may contribute to make palindrone with current palindrone
        if (s[i] == s[j]) {
            return palindrones[i][j] = ((solve(s, i + 1, j) % mod + (solve(s, i, j - 1) + 1) % mod)) % mod;
        }
        else {
            //else we check for the rest subsequences - remove the common part since we are counting twice
            return palindrones[i][j] = (mod + (solve(s, i + 1, j) % mod + solve(s, i, j - 1) % mod) - solve(s, i + 1, j - 1) % mod) % mod;
        }
    }
    long long int  countPS(string str)
    {
        //Your code here
        memset(palindrones, -1, sizeof(palindrones));

        return solve(str, 0, str.size() - 1);
    }

};
//time: O(n^2) and space: O(n^2)

// *******iterative approach*********
//using gap strategy to treverse
long long int palindrones[1002][1002];
class Solution {
    long long int mod = 1000000007;
public:
    long long int  countPS(string str)
    {
        //Your code here
        for (int gap = 0; gap < str.size(); gap++) {
            for (int i = 0, j = gap; j < str.size(); i++, j++) {
                if (gap == 0) {
                    palindrones[i][j] = 1;
                }
                else if (gap == 1) {
                    if (str[i] == str[j]) {
                        palindrones[i][j] = 3;
                    }
                    else {
                        palindrones[i][j] = 2;
                    }
                }
                else {
                    long long int without_first_char = palindrones[i + 1][j];
                    long long int without_last_char = palindrones[i][j - 1];
                    if (str[i] == str[j]) {
                        palindrones[i][j] = without_first_char + without_last_char + 1;
                    }
                    else {
                        palindrones[i][j] = without_first_char + without_last_char - palindrones[i+ 1][j - 1];
                    }
                }
                palindrones[i][j] += mod;
                palindrones[i][j] %= mod;

            }
        }
        return palindrones[0][str.size() -1];
    }

};

//same time complexity
