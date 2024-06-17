#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);

        // Calculate left products
        for (int i = 1; i < n; ++i) {
            output[i] = output[i - 1] * nums[i - 1];
        }

        // Calculate right products and update output
        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            output[i] *= right;
            right *= nums[i];
        }

        return output;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3, 4};

    // Calculate product except self
    vector<int> result = sol.productExceptSelf(nums);

    // Print the result
    cout << "Product except self: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
