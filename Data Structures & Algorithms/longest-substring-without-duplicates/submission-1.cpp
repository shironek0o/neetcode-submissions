class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), res = 0;

        std::array<int, 256> cnt {};
        for (int i = 0, j = 0; j < n; j++) {
            while (cnt[s[j] - '\0'] > 0) {
                cnt[s[i++] - '\0']--;
            }   
            res = std::max(res, j - i + 1);
            cnt[s[j] - '\0']++;
        }
        return res;
    }
};
