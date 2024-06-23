#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        
        // Process the string to remove extra spaces and reverse each word
        while (i < n) {
            // Skip spaces
            while (i < n && s[i] == ' ') {
                ++i;
            }
            if (i < n) {
                // Add a space before the next word if it's not the first word
                if (j != 0) {
                    s[j++] = ' ';
                }
                // Find the end of the word
                int k = i;
                while (k < n && s[k] != ' ') {
                    s[j++] = s[k++];
                }
                // Reverse the word
                reverse(s.begin() + j - (k - i), s.begin() + j);
                // Move to the next word
                i = k;
            }
        }
        
        // Remove any extra characters from the end of the string
        s.erase(s.begin() + j, s.end());
        
        // Reverse the entire string to get the final result
        reverse(s.begin(), s.end());
        
        return s;
    }
};

int main() {
    Solution sol;
    string input = "  the sky  is blue ";
    string result = sol.reverseWords(input);
    cout << "Reversed words: \"" << result << "\"" << endl;
    return 0;
}
