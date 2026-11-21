class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), res = 0;

        std::vector<int> max_right = prices;
        for (int i = n - 2; i >= 0; i--) {
            max_right[i] = std::max(max_right[i], max_right[i + 1]);
        }

        for (int i = 0; i < n - 1; i++) {
            res = std::max(res, max_right[i + 1] - prices[i]);   
        }
        
        return res;
    }
};
