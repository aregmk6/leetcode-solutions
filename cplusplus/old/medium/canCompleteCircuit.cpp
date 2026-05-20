#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        const int num_stations = gas.size();

        int cur_sum   = 0;
        int counter   = num_stations - 1;
        bool positive = false;

        for (int i = 0, j = 0;; i = (i + 1) % num_stations) {
            if (j > num_stations)
                return -1;

            if (counter <= 0)
                return j;

            cur_sum += gas[i] - cost[i];

            if (cur_sum >= 0 && positive) {
                --counter;
            } else if (cur_sum >= 0 && !positive) {
                counter  = num_stations - 1;
                positive = true;
            } else {
                cur_sum  = 0;
                positive = false;
                j += (num_stations - 1) - counter + 1;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> gas  = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << s.canCompleteCircuit(gas, cost) << endl;

    return 0;
}
