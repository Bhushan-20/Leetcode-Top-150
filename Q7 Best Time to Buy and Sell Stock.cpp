#include <iostream>
#include <vector>
#include <algorithm>  // For std::max and std::min

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;  // Edge case: if prices is empty

        int min_price = prices[0];
        int maxprof = 0;

        for (int i = 1; i < prices.size(); i++) {
            maxprof = max(maxprof, prices[i] - min_price);
            min_price = min(prices[i], min_price);
        }

        return maxprof;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Calculate maximum profit
    int profit = sol.maxProfit(prices);

    // Print the maximum profit
    cout << "Maximum profit: " << profit << endl;

    return 0;
}
