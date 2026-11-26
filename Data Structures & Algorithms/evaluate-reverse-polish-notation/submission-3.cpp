class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int> stk;
        
        for (auto token : tokens) {
            if (std::isdigit(token.back())) {
                stk.push_back(std::stoi(token));
            } else {
                int x = stk.back();
                stk.pop_back();
                int y = stk.back();
                stk.pop_back();
                if (token == "+") {
                    stk.push_back(x + y);
                } else if (token == "-") {
                    stk.push_back(y - x);
                } else if (token == "*") {
                    stk.push_back(x * y);
                } else {
                    stk.push_back(y / x);
                }
            }
        }

        return stk.back();
    }
};
