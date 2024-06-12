#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    // Before removal
    cout << "nums before removal: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Remove element
    int newLength = sol.removeElement(nums, val);

    // After removal
    cout << "nums after removal: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // New length
    cout << "New length: " << newLength << endl;

    return 0;
}
