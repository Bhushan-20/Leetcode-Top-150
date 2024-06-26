#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1}; // In case there is no solution
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(numbers, target);

    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}
