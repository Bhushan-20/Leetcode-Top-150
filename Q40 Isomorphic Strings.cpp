#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mpp;
        unordered_map<char, char> reverse_mpp;
        
        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            if (mpp.find(s[i]) != mpp.end()) {
                if (mpp[s[i]] != t[i]) {
                    return false;
                }
            } else {
                if (reverse_mpp.find(t[i]) != reverse_mpp.end() && reverse_mpp[t[i]] != s[i]) {
                    return false;
                }
                mpp[s[i]] = t[i];
                reverse_mpp[t[i]] = s[i];
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "egg";
    string t = "add";

    if (sol.isIsomorphic(s, t)) {
        cout << "The strings are isomorphic." << endl;
    } else {
        cout << "The strings are not isomorphic." << endl;
    }

    return 0;
}
