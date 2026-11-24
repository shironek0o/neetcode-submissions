class Solution {
public:
    int findMin(vector<int> &nums) {
        int lo = -1, hi = ssize(nums);
        while (hi - lo > 1) {
            int m = (lo + hi) / 2;
            if (nums[m] >= nums[0]) {
                lo = m;
            } else {
                hi = m;
            }
        }
        return hi == ssize(nums) ? nums[0] : nums[hi];
    }
};

