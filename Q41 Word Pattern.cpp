#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> arr;
        int l = 0;

        // Split the string s into words and store them in arr
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                arr.push_back(s.substr(l, i - l));
                l = i + 1;
            }
        }

        // Check if the size of the pattern matches the number of words in s
        if (arr.size() != pattern.size()) {
            return false;
        }

        unordered_map<char, string> m1;
        unordered_map<string, char> m2;

        // Map pattern characters to words and vice versa
        for (int i = 0; i < pattern.size(); i++) {
            if (m1.find(pattern[i]) != m1.end()) {
                if (m1[pattern[i]] != arr[i]) {
                    return false;
                }
            } else {
                m1[pattern[i]] = arr[i];
            }

            if (m2.find(arr[i]) != m2.end()) {
                if (m2[arr[i]] != pattern[i]) {
                    return false;
                }
            } else {
                m2[arr[i]] = pattern[i];
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    string pattern = "abba";
    string s = "dog cat cat dog";

    if (sol.wordPattern(pattern, s)) {
        cout << "The string follows the pattern." << endl;
    } else {
        cout << "The string does not follow the pattern." << endl;
    }

    return 0;
}
