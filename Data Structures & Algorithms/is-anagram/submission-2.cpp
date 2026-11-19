class Solution {
public:
    bool isAnagram(string s, string t) {
        std::array<std::array<int, 26>, 2> cnt {};
        for (auto c : s) {
            cnt[0][c - 'a']++;
        }
        for (auto c : t) {
            cnt[1][c - 'a']++;
        }
        return cnt[0] == cnt[1];
    }
};
