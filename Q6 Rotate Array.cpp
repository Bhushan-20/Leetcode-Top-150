#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);

        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;  // Copy the rotated elements back to nums
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    // Before rotation
    cout << "nums before rotation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Rotate the array
    sol.rotate(nums, k);

    // After rotation
    cout << "nums after rotation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
