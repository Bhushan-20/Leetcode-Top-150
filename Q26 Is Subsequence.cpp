#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k = 0; // Index for the current position in t
        bool flag; // Flag to check if a character from s is found in t

        for (int i = 0; i < s.length(); i++) {
            flag = false;
            for (int j = k; j < t.length(); j++) {
                if (t[j] == s[i]) {
                    k = j + 1; // Move k to the next position in t
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                return false; // If any character in s is not found in t in order
            }
        }
        return true; // If all characters in s are found in t in order
    }
};

int main() {
    Solution sol;
    string s = "abc";
    string t = "ahbgdc";
    bool result = sol.isSubsequence(s, t);
    cout << "Is subsequence: " << (result ? "true" : "false") << endl;
    return 0;
}
