class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int lo = -1, hi = m * n;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (matrix[mid / n][mid % n] <= target) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        
        if (lo == -1 or matrix[lo / n][lo % n] != target) {
            return false;
        }
        return true;
    }
};
