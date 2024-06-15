#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (maxReach < i) {
                return false;
            }
            maxReach = max(nums[i] + i, maxReach);
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {2, 3, 1, 1, 4};

    // Check if you can jump to the last index
    bool result = sol.canJump(nums);

    // Print the result
    cout << (result ? "Can jump to the last index" : "Cannot jump to the last index") << endl;

    return 0;
}
