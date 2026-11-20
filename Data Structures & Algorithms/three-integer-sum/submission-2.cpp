class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> res;

        std::unordered_set<int> seen;
        std::set<std::vector<int>> S;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int need = -(nums[i] + nums[j]);
                if (seen.contains(need)) {
                    std::vector<int> cur = {need, nums[i], nums[j]};
                    ranges::sort(cur);
                    res.push_back(cur);
                }
            }
            seen.insert(nums[i]);
        }
        ranges::sort(res);
        res.erase(ranges::unique(res).begin(), res.end());
        return res;
    }
};
