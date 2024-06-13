#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> numC;
        for (int i = 0; i < nums.size(); i++) {
            numC[nums[i]]++;
            if (numC[nums[i]] > nums.size() / 2) {
                return nums[i];
            }
        }
        return -1; // This line is never reached because the problem guarantees a majority element
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    // Find the majority element
    int majority = sol.majorityElement(nums);

    // Print the majority element
    cout << "The majority element is: " << majority << endl;

    return 0;
}
