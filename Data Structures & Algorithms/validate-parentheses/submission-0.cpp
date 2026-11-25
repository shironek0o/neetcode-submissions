class Solution {
public:
    bool isValid(string s) {
        std::vector<char> stk;

        for (auto &c : s) {
            if (c == '(' or c == '[' or c == '{') {
                stk.push_back(c);
            }
            if (c == ')') {
                if (stk.empty() or stk.back() != '(') {
                    return false;
                }
                stk.pop_back();
            }
            if (c == ']') {
                if (stk.empty() or stk.back() != '[') {
                    return false;
                }
                stk.pop_back();
            }
            if (c == '}') {
                if (stk.empty() or stk.back() != '{') {
                    return false;
                }
                stk.pop_back();
            }
        }

        return stk.empty();
    }
};
