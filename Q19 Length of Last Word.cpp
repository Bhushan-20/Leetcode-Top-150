#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int index = s.size() - 1;

        // Skip trailing spaces
        while (index >= 0 && s[index] == ' ') {
            index--;
        }

        // Count the length of the last word
        while (index >= 0 && s[index] != ' ') {
            length++;
            index--;
        }

        return length;
    }
};

int main() {
    Solution sol;

    // Example input
    string input = "Hello World  ";

    // Calculate the length of the last word
    int result = sol.lengthOfLastWord(input);

    // Print the result
    cout << "The length of the last word is: " << result << endl;

    return 0;
}
