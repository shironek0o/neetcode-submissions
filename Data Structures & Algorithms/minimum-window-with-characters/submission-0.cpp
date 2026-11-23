auto chmin(auto &a, auto b) { return (b < a and (a = b, true)); }

constexpr int inf = 2E9;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) {
            return "";
        }

        auto get = [&](char c) -> int {
            if (std::islower(c)) {
                return c - 'a';
            }
            return c - 'A' + 26;
        };

        std::array<int, 52> cnt_t {}, cnt_s {};
        for (auto &c : t) {
            cnt_t[get(c)]++; 
        }

        auto satisfied = [&]() -> bool {
            for (int i = 0; i < 52; i++) {
                if (cnt_t[i] > cnt_s[i]) {
                    return false;
                }
            }
            return true;
        };

        int min_len = inf, l = -1, r = -1;
        for (int i = 0, j = 0; j < n; j++) {
            cnt_s[get(s[j])]++;
            while (i < j and satisfied()) {
                cnt_s[get(s[i])]--;
                i++;
                if (!satisfied()) {
                    i--;
                    cnt_s[get(s[i])]++;
                    break;
                }
            }
            if (satisfied() and chmin(min_len, j - i + 1)) {
                l = i, r = j;
            }
        }
        
        if (min_len == inf) {
            return "";
        }
        return s.substr(l, r - l + 1);
    }
};
