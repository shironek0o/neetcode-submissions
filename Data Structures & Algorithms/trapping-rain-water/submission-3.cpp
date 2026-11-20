auto chmax(auto &a, auto b) { return (a < b and (a = b, true)); }

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int res = 0;
        int l = 0, r = n - 1, left_max = height[l], right_max = height[r];
        while (l < r) {
            if (left_max < right_max) {
                l++;
                chmax(left_max, height[l]);
                res += left_max - height[l];
            } else {
                r--;
                chmax(right_max, height[r]);
                res += right_max - height[r];
            }
        }
        return res;
    }
};
