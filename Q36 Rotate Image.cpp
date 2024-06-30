#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverse(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n / 2; i++) {
            swap(arr[i], arr[n - 1 - i]);
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> a(n, vector<int>(n));
        
        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[j][i] = matrix[i][j];
            }
        }

        // Reverse each row of the transposed matrix
        for (int i = 0; i < n; i++) {
            reverse(a[i]);
        }

        // Copy the result back to the original matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = a[i][j];
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    sol.rotate(matrix);

    cout << "Rotated matrix:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
