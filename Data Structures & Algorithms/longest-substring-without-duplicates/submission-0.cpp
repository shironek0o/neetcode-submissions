class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), res = 0;

        std::unordered_set<int> seen;
        for (int i = 0, j = 0; j < n; j++) {
            while (seen.contains(s[j])) {
                seen.erase(s[i++]);
            }   
            res = std::max(res, j - i + 1);
            seen.insert(s[j]);
        }
        return res;
    }
};
