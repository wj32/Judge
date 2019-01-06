class LFUCache {
private:
    struct Node {
        int frequency;
        list<int> keys;
    };

    struct Entry {
        int value;
        bool valid;
        list<Node>::iterator node;
        list<int>::iterator key;
    };

    int capacity;
    unordered_map<int, Entry> m;
    list<Node> a;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    void incrementFrequency(int key, Entry* entry) {
        int frequency = 0;
        list<Node>::iterator next = a.end();
        if (entry->valid) {
            frequency = entry->node->frequency;
            entry->node->keys.erase(entry->key);
            if (entry->node->keys.empty()) {
                next = a.erase(entry->node);
            }
            else {
                next = entry->node;
            }
        }
        frequency++;
        const auto node = [&] {
            if ((next != a.begin()) && (std::prev(next)->frequency == frequency)) {
                return std::prev(next);
            } else {
                return a.insert(next, {frequency, {}});
            }
        }();
        entry->valid = true;
        entry->node = node;
        entry->key = node->keys.insert(node->keys.begin(), key);
    }

    int get(int key) {
        const auto it = m.find(key);
        if (it != m.end()) {
            incrementFrequency(key, &it->second);
            return it->second.value;
        }
        else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        auto it = m.find(key);
        if (it == m.end()) {
            if (m.size() == capacity) {
                const auto lastKey = prev(a.end());
                m.erase(m.find(lastKey->keys.back()));
                lastKey->keys.pop_back();
                if (lastKey->keys.empty()) {
                    a.erase(lastKey);
                }
            }
            const auto result = m.insert({key, {0, false, {}, {}}});
            assert(result.second);
            it = result.first;
        }
        it->second.value = value;
        incrementFrequency(key, &it->second);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
