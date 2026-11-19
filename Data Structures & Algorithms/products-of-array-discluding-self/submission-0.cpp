class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int cnt_zero = 0, zero_index = -1, prod = 1;        
        for (int i = 0; i < n; i++) {
            cnt_zero += nums[i] == 0;
            if (nums[i] != 0) {
                prod *= nums[i];
            } else {
                zero_index = i;
            }
        }
        if (cnt_zero >= 2) {
            return std::vector<int>(n, 0);
        }
        if (cnt_zero == 1) {
            std::vector<int> res(n, 0);
            res[zero_index] = prod;
            return res; 
        }
        std::vector<int> res(n, prod);
        for (int i = 0; i < n; i++) {
            res[i] /= nums[i];
        }
        return res;
    }
};
