#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        int left = 0, right = 0, sum = 0;
        
        while (left < n || right < n) {
            if (sum < target && right < n) {
                sum += nums[right];
                right++;
            } else if (sum >= target && left < n) {
                ans = min(ans, right - left);
                sum -= nums[left];
                left++;
            } else {
                break;
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int result = sol.minSubArrayLen(target, nums);

    cout << "The minimal length of a contiguous subarray with sum at least " << target << " is: " << result << endl;

    return 0;
}
