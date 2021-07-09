unordered_map<string, bool> lookup;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        string key = s1 + " " + s2;
        if (lookup.count(key)) {
            return lookup[key];
        }
        if (s1.compare(s2) == 0) {
            lookup[key] = true;
            return true;
        }
        if (s1.size() <= 1 or s2.size() <= 1) {
            lookup[key] = false;
            return false;
        }
        bool flag = false;
        int n = s1.size();
        for (int k = 1; k <= n - 1; k++) {
            bool swap = isScramble(s1.substr(0, k), s2.substr(n - k, k)) and isScramble(s1.substr(k), s2.substr(0, n - k));
            bool no_swap = isScramble(s1.substr(0, k), s2.substr(0, k)) and isScramble(s1.substr(k), s2.substr(k));
            if (swap || no_swap) {
                flag = true;
                break;
            }
        }
        return lookup[key] = flag;
    }
};
