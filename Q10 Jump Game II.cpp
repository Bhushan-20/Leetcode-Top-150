#include <iostream>
#include <vector>
#include <algorithm>  // For std::max

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;  // If the array has 1 or no element, no jumps are needed

        int L = 0, R = 0, steps = 0;
        while (R < n - 1) {
            int maxi = 0;
            for (int i = L; i <= R; i++) {
                maxi = max(maxi, i + nums[i]);
            }
            L = R + 1;
            R = maxi;
            steps++;
        }
        return steps;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {2, 3, 1, 1, 4};

    // Calculate minimum jumps
    int result = sol.jump(nums);

    // Print the result
    cout << "Minimum jumps: " << result << endl;

    return 0;
}
