#include <iostream>
#include <vector>
#include <algorithm>  // For std::max and std::min

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        int buy = prices[0];
        
        for (int i = 1; i < n; i++) {
            if (prices[i] > buy) {
                maxi += prices[i] - buy;
            }
            buy = prices[i];
        }
        
        return maxi;
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
