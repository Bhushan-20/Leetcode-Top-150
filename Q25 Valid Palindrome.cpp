#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Move left index to the next alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move right index to the previous alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            // Compare characters, ignoring case
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution sol;
    string input = "A man, a plan, a canal: Panama";
    bool result = sol.isPalindrome(input);
    cout << "Is palindrome: " << (result ? "true" : "false") << endl;
    return 0;
}
