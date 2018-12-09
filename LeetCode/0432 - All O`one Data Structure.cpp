class AllOne {
private:
    unordered_map<string, int> k;
    map<int, unordered_set<string>> v;

public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        const auto it = k.find(key);
        if (it != k.end()) {
            auto& s = v[it->second];
            s.erase(key);
            if (s.empty()) {
                v.erase(it->second);
            }
            it->second++;
            v[it->second].insert(key);
        }
        else {
            k[key] = 1;
            v[1].insert(key);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        const auto it = k.find(key);
        if (it != k.end()) {
            auto& s = v[it->second];
            s.erase(key);
            if (s.empty()) {
                v.erase(it->second);
            }
            it->second--;
            if (it->second != 0) {
                v[it->second].insert(key);
            }
            else {
                k.erase(it);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return !v.empty() ? *prev(v.end())->second.begin() : "";
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return !v.empty() ? *v.begin()->second.begin() : "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
