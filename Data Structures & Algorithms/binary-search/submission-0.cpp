class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = -1, hi = ssize(nums);
        while (hi - lo > 1) {
            int m = (lo + hi) / 2;
            if (nums[m] <= target) {
                lo = m;
            } else {
                hi = m;
            }
        }
        if (lo == -1 or nums[lo] != target) {
            return -1;
        }
        return lo;
    }
};
