class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> cnt;
        for (auto num : nums) {
            cnt[num]++;
        }
        std::vector freq(n + 1, std::vector<int>());
        for (auto &[num, c] : cnt) {
            freq[c].push_back(num);
        }
        std::vector<int> res;
        for (int i = n; i > 0; i--) {
            for (auto num : freq[i]) {
                res.push_back(num);
                k--;
            }
            if (k == 0) {
                return res;
            }
        }
        return res;
    }
};
