class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        std::vector<int> pre = height;
        for (int i = 1; i < n; i++) {
            pre[i] += pre[i - 1];
        }

        auto get = [&](int l, int r) {
            l--;
            return pre[r] - (l >= 0 ? pre[l] : 0);
        };

        int res = 0;
        for (int i = 0; i < n;) {
            int j = i;
            while (j + 1 < n and height[j + 1] < height[i]) {
                j++;
            }
            j++;
            if (j < n and height[j] >= height[i]) {
                res += height[i] * (j - i - 1) - get(i + 1, j - 1);
            }
            i = j;
        }

        for (int i = n - 1; i >= 0;) {
            int j = i;
            while (j - 1 >= 0 and height[j - 1] <= height[i]) {
                j--;
            }
            j--;
            if (j >= 0 and height[j] > height[i]) {
                res += height[i] * (i - j - 1) - get(j + 1, i - 1);
            }
            i = j;
        }
        return res;
    }
};
