#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();  // Handle edge cases where the size is 0 or 1

        int j = 1;  // Pointer to the position where the next unique element (or allowed duplicate) should be placed
        for (int i = 1; i < nums.size(); i++) {
            if (j == 1 || nums[i] != nums[j - 2]) {  // Check if we can place the current element
                nums[j++] = nums[i];
            }
        }
        return j;  // Return the new length of the array
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    // Before removing duplicates
    cout << "nums before removing duplicates: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Remove duplicates
    int newLength = sol.removeDuplicates(nums);

    // After removing duplicates
    cout << "nums after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // New length
    cout << "New length: " << newLength << endl;

    return 0;
}
