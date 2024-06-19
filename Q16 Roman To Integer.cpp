#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int a = 0;
        vector<int> res(128);
        res['I'] = 1;
        res['V'] = 5;
        res['X'] = 10;
        res['L'] = 50;
        res['C'] = 100;
        res['D'] = 500;
        res['M'] = 1000;
        
        for (int i = 0; i + 1 < s.length(); ++i) {
            if (res[s[i]] < res[s[i + 1]])
                a -= res[s[i]];
            else
                a += res[s[i]];
        }
        return a + res[s.back()];
    }
};

int main() {
    Solution sol;

    // Example input
    string roman = "MCMXCIV";

    // Convert Roman numeral to integer
    int result = sol.romanToInt(roman);

    // Print the result
    cout << "The integer value of the Roman numeral " << roman << " is: " << result << endl;

    return 0;
}
