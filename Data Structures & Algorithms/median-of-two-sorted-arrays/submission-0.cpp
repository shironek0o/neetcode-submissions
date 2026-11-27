constexpr int inf = 1E9;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (ssize(nums1) > ssize(nums2)) {
            std::swap(nums1, nums2);
        }
        
        int n = nums1.size(), m = nums2.size();

        int lo = -1, hi = n;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            int a = nums1[mid];
            int b = nums2[(n + m + 1) / 2 - mid - 1];
            if (a <= b) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        
        int x = lo, y = (n + m + 1) / 2 - x - 2;
        int A = x >= 0 ? nums1[x] : -inf;
        int B = x + 1 <= n - 1 ? nums1[x + 1] : inf;
        int C = y >= 0 ? nums2[y] : -inf;
        int D = y + 1 <= m - 1 ? nums2[y + 1] : inf;

        if ((n + m) % 2) {
            return std::max(A, C);
        }
        return (std::max(A, C) + std::min(B, D)) / 2.0;
    }
};
