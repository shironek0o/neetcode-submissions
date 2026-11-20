bool chmax(auto &a, auto b) { return (a < b and (a = b, true)); }

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;
        
        int res = 0;
        while (l < r) {
            chmax(res, std::min(heights[l], heights[r]) * (r - l));
            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};
