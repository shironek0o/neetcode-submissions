class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        std::vector<int> result(n);
        std::vector<std::pair<int, int>> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() and stk.back().second <= temperatures[i]) {
                stk.pop_back();
            } 
            result[i] = stk.empty() ? 0 : stk.back().first - i;
            stk.emplace_back(i, temperatures[i]);
        }
        
        return result;
    }
};
