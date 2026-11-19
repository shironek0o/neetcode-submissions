class Solution {
public:

    string encode(vector<string>& strs) {
        std::string res;
        for (auto &str : strs) {
            res += ssize(str);
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        std::vector<std::string> res;
        for (int i = 0; i < ssize(s); i++) {
            int len = (unsigned char)s[i];
            res.push_back(s.substr(i + 1, len));
            i += len;
        }        
        return res;
    }
};
// first time know that char in C++ is negative
// the range of char in string: -128 ~ 127
// use unsigned to get the value will fix this