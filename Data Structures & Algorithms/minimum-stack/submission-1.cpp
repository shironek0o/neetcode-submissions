class MinStack {
public:
    MinStack() {
        index = 0;
        stk.clear();
        min_stk.clear();
    }
    
    void push(int val) {
        stk.push_back(val);
        if (min_stk.empty() or val <= min_stk.back()) {
            min_stk.push_back(val);
        }
    }
    
    void pop() {
        int val = stk.back();
        stk.pop_back();
        if (!min_stk.empty() and min_stk.back() == val) {
            min_stk.pop_back();
        } 
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return min_stk.back();
    }
private:
    int index = 0;
    std::vector<int> stk, min_stk;
};
