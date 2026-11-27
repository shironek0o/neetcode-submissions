class TimeMap {
public:
    TimeMap() {
        time_map.clear();
    }
    
    void set(string key, string value, int timestamp) {
        time_map[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (!time_map.contains(key)) {
            return "";
        }
        auto &vec = time_map[key];
        auto it = std::ranges::upper_bound(
                vec, timestamp, {}, &std::pair<int, std::string>::first  
            );
        if (it == vec.begin()) {
            return "";
        }
        return std::prev(it)->second;
    }
private:
    std::unordered_map<std::string, 
        std::vector<std::pair<int, std::string>>> time_map;
};