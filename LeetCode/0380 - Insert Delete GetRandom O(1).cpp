class RandomizedSet {
private:
    vector<int> entries;
    unordered_map<int, int> mapping;

    random_device rd;
    mt19937 gen;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mapping.find(val) != mapping.end()) {
            return false;
        }
        mapping.insert({val, entries.size()});
        entries.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        const auto it = mapping.find(val);
        if (it == mapping.end()) {
            return false;
        }
        entries[it->second] = entries.back();
        mapping[entries.back()] = it->second;
        entries.pop_back();
        mapping.erase(it);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        std::uniform_int_distribution<> dist(0, entries.size() - 1);
        return entries[dist(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
