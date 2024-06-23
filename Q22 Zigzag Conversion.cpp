#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Vector of strings to hold characters for each row
        vector<string> rows(numRows);
        
        int idx = 0;
        int direction = 1; // 1 for down, -1 for up

        // Traverse the string and place characters in respective rows
        for (char c : s) {
            rows[idx] += c;
            if (idx == 0) {
                direction = 1;
            } else if (idx == numRows - 1) {
                direction = -1;
            }
            idx += direction;
        }

        // Concatenate all rows to form the final result
        string result;
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example input
    string input = "PAYPALISHIRING";
    int numRows = 3;

    // Convert the string
    string result = sol.convert(input, numRows);

    // Print the result
    cout << "Converted string: " << result << endl;

    return 0;
}
