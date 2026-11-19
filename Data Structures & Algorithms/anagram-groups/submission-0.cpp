class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, 
            std::vector<std::string>> groups;
        for (auto &s : strs) {
            auto t = s;
            ranges::sort(t);
            groups[t].push_back(s);   
        }
        std::vector<std::vector<std::string>> res;
        for (auto &[_, group] : groups) {
            res.push_back(group);
        }
        return res;
    }
};
