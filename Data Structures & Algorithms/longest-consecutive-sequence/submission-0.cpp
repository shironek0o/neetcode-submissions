class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        std::unordered_set<int> S(nums.begin(), nums.end());
        for (auto num : nums) {
            if (!S.contains(num - 1)) {
                int cur = 1;
                while (S.contains(num + 1)) {
                    cur++;
                    num++;
                }
                res = std::max(res, cur);
            }
        }
        return res;
    }
};
