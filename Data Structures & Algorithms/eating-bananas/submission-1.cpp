using i64 = long long;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {        
        i64 lo = 0, hi = std::reduce(piles.begin(), piles.end(), 0LL) + 1;
        while (hi - lo > 1) {
            i64 m = (lo + hi) / 2;
            if ([&](int m) -> bool {
                int total = 0;
                for (auto pile : piles) {
                    total += (pile + m - 1) / m;
                }
                return total <= h;
            }(m)) {
                hi = m;
            } else {
                lo = m;
            }
        }
        return hi;
    }
};
