#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;  // Handle the edge case where nums is empty

        int i = 0;  // Pointer to the last unique element
        int j = 1;  // Pointer to iterate through the array
        int count = 1;  // Number of unique elements

        while (j < nums.size()) {
            if (nums[i] != nums[j]) {
                i++;
                count++;
                nums[i] = nums[j];
            }
            j++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 1, 2};

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
