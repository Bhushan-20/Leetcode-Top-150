#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        // Find the smallest length string in the vector
        int smallestLen = strs[0].length();
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].length() < smallestLen) {
                smallestLen = strs[i].length();
            }
        }

        bool matching = true;
        int prefixLen = 0;
        while (matching && (prefixLen < smallestLen)) {
            for (int i = 1; i < strs.size(); i++) {
                if (strs[0][prefixLen] != strs[i][prefixLen]) {
                    matching = false;
                    break;
                }
            }
            if (matching) {
                prefixLen++;
            }
        }

        return strs[0].substr(0, prefixLen);
    }
};

int main() {
    Solution sol;

    // Example input
    vector<string> input = {"flower", "flow", "flight"};

    // Find the longest common prefix
    string result = sol.longestCommonPrefix(input);

    // Print the result
    cout << "The longest common prefix is: " << result << endl;

    return 0;
}
