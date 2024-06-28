#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int count = 0;
        int total = row * col;
        int srow = 0, scol = 0, erow = row - 1, ecol = col - 1;

        while (count < total) {
            for (int i = scol; i <= ecol && count < total; i++) {
                ans.push_back(matrix[srow][i]);
                count++;
            }
            srow++;
            for (int i = srow; i <= erow && count < total; i++) {
                ans.push_back(matrix[i][ecol]);
                count++;
            }
            ecol--;
            for (int i = ecol; i >= scol && count < total; i--) {
                ans.push_back(matrix[erow][i]);
                count++;
            }
            erow--;
            for (int i = erow; i >= srow && count < total; i--) {
                ans.push_back(matrix[i][scol]);
                count++;
            }
            scol++;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = sol.spiralOrder(matrix);

    cout << "The matrix in spiral order is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
