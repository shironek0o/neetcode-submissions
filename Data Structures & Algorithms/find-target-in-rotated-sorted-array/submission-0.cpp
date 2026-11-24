class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto binary_search = [&](int lo, int hi) {
            lo--;
            hi++;
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
        };

        int lo = -1, hi = ssize(nums);
        while (hi - lo > 1) {
            int m = (lo + hi) / 2;
            if (nums[m] >= nums[0]) {
                lo = m;
            } else {
                hi = m;
            }
        }

        if (hi == ssize(nums)) {
            hi = 0;
        }

        int res = binary_search(hi, ssize(nums) - 1);
        if (res == -1 and hi - 1 >= 0) {
            res = binary_search(0, hi - 1);
        }
        return res;
    }
};
