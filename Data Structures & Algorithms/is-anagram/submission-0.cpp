class Solution {
public:
    bool isAnagram(string s, string t) {
        std::multiset<int> S[2];
        for (auto c : s) {
            S[0].insert(c);
        }
        for (auto c : t) {
            S[1].insert(c);
        }
        return S[0] == S[1];
    }
};
