#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isValid(int x, vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        int res = arr.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= x) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        int ele = arr.size() - res;
        return (x <= ele);
    }

public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int l = 0;
        int r = citations[n - 1];
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(mid, citations)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> citations = {3, 0, 6, 1, 5};

    // Calculate h-index
    int hIndex = sol.hIndex(citations);

    // Print the result
    cout << "H-index: " << hIndex << endl;

    return 0;
}
