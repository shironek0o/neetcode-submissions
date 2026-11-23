class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        std::vector<int> res;
        std::deque<std::pair<int, int>> dq;

        for (int i = 0; i < n; i++) {
            while (!dq.empty() and dq.back().second <= nums[i]) {
                dq.pop_back();
            }
            while (!dq.empty() and i - dq.front().first >= k) {
                dq.pop_front();
            }
            dq.push_back({i, nums[i]});
            if (i >= k - 1) {
                res.push_back(dq.front().second);
            }
        }

        return res;
    }
};
