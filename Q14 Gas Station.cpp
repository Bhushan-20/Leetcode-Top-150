#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_cost = 0;
        int left_over_fuel = 0;
        int start_index = 0;

        for (int i = 0; i < n; i++) {
            int balance = gas[i] - cost[i];
            total_cost += balance;
            left_over_fuel += balance;
            if (left_over_fuel < 0) {
                left_over_fuel = 0;
                start_index = i + 1;
            }
        }

        if (total_cost < 0) {
            return -1;
        }
        return start_index;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    // Find the starting gas station index
    int result = sol.canCompleteCircuit(gas, cost);

    // Print the result
    cout << "The starting gas station index is: " << result << endl;

    return 0;
}
