class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (ssize(s1) > ssize(s2)) {
            return false;
        }

        std::array<int, 26> cnt_s1 {};
        for (auto &c : s1) {
            cnt_s1[c - 'a']++;
        }

        int n = s2.size();
        std::array<int, 26> cnt {};
        for (int i = 0, j = 0; j < n; j++) {
            cnt[s2[j] - 'a']++;
            while (i <= j and cnt[s2[j] - 'a'] > cnt_s1[s2[j] - 'a']) {

                cnt[s2[i++] - 'a']--;
            }
            if (cnt == cnt_s1) {
                return true;
            }
        }
        return false;
    }
};
