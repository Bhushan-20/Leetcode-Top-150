#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLength = 0;
            int j = i;
            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }

            int spaces = maxWidth - lineLength;
            int gaps = j - i - 1;
            string line;

            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.length(), ' ');
            } else {
                int evenSpaces = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += string(evenSpaces + (extraSpaces > 0 ? 1 : 0), ' ');
                        if (extraSpaces > 0) extraSpaces--;
                    }
                }
            }

            res.push_back(line);
            i = j;
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> result = solution.fullJustify(words, maxWidth);
    
    for (const string& line : result) {
        cout << '"' << line << '"' << endl;
    }

    return 0;
}
