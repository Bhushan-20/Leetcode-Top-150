#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;  // Pointer for the end of the elements in nums1
        int j = n - 1;  // Pointer for the end of the elements in nums2
        int k = m + n - 1;  // Pointer for the end of nums1 array
        
        // Merge the arrays starting from the end
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    // Before merging
    cout << "nums1 before merging: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    // Merge nums2 into nums1
    sol.merge(nums1, m, nums2, n);

    // After merging
    cout << "nums1 after merging: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
