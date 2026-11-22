class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int max_freq = 0, res = 0;
        std::array<int, 26> cnt {};
        for (int i = 0, j = 0; j < n; j++) {
            max_freq = std::max(max_freq, ++cnt[s[j] - 'A']);       
            while (i < j and max_freq + k < j - i + 1) {
                cnt[s[i++] - 'A']--;
                max_freq = std::max(max_freq, ranges::max(cnt));
            }
            res = std::max(res, j - i + 1);
        }
        return res;
    }
};
