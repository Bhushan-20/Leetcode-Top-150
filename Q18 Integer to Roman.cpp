#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        for (int i = 0; i < 13; ++i) {
            while (num >= values[i]) {
                ans += roman[i];
                num -= values[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    int number = 1994;

    // Convert integer to Roman numeral
    string result = sol.intToRoman(number);

    // Print the result
    cout << "The Roman numeral of " << number << " is: " << result << endl;

    return 0;
}
