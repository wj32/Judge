class RandomizedCollection {
public:
    vector<pair<int, int>> entries;
    unordered_map<int, vector<int>> mapping;

    random_device rd;
    mt19937 gen;

    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto it = mapping.find(val);
        const auto present = (it != mapping.end());
        if (!present) {
            it = mapping.insert({val, {}}).first;
        }
        it->second.push_back(entries.size());
        entries.push_back({val, it->second.size() - 1});
        return !present;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        const auto it = mapping.find(val);
        if (it == mapping.end()) {
            return false;
        }

        const int removeIndex = it->second.back();
        it->second.pop_back();

        const auto lastEntry = entries.back();
        entries.pop_back();

        if (removeIndex != entries.size()) {
            entries[removeIndex] = lastEntry;
            mapping[lastEntry.first][lastEntry.second] = removeIndex;
        };

        if (it->second.empty()) {
            mapping.erase(it);
        }

        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        std::uniform_int_distribution<> dist(0, entries.size() - 1);
        return entries[dist(gen)].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
