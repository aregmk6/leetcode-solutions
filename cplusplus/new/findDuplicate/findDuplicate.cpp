#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int findDuplicate(vector<int>& nums)
    {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main()
{
    vector<int> nums = {3, 2, 3, 1, 4};

    Solution s;
    cout << s.findDuplicate(nums) << endl;
}
