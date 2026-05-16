#include <vector>

using namespace std;

class Solution
{
    static void rec(vector<vector<int>>& res, vector<int>& combination,
                    const vector<int>& candidates, int idx, int target)
    {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            res.push_back(combination);
            return;
        }

        if (idx >= candidates.size()) {
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            combination.push_back(candidates[i]);
            rec(res, combination, candidates, i, target - candidates[i]);
            combination.pop_back();
        }
    }

  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        if (candidates.empty()) {
            return {};
        }

        vector<int> combination;

        vector<vector<int>> res{};
        rec(res, combination, candidates, 0, target);

        return res;
    }
};

int main()
{
    Solution s;

    vector<int> candidates = {2, 3, 6, 7};

    s.combinationSum(candidates, 7);
}
