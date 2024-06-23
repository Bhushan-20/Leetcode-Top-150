#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        if (needle.size() > haystack.size()) {
            return -1;
        }

        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            if (haystack.substr(i, needle.size()) == needle) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    // Example inputs
    string haystack = "hello";
    string needle = "ll";

    // Find the index of the first occurrence of needle in haystack
    int result = sol.strStr(haystack, needle);

    // Print the result
    cout << "The index of the first occurrence of '" << needle << "' in '" << haystack << "' is: " << result << endl;

    return 0;
}
