class MyHashMap {
private:
    struct Bucket {
        int key;
        int val : 29;
        int state : 3;
        shared_ptr<vector<pair<int, int>>> vec;
    };

    vector<Bucket> buckets;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        buckets.resize(10000, Bucket{0, 0, 0, {}});
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        auto& bucket = buckets[key % buckets.size()];
        if (bucket.state == 0) {
            bucket.key = key;
            bucket.val = value;
            bucket.state = 1;
        }
        else {
            if (bucket.state == 1) {
                if (!bucket.vec) {
                    bucket.vec = make_shared<vector<pair<int, int>>>();
                }
                bucket.vec->push_back({bucket.key, bucket.val + 0});
                bucket.key = 0;
                bucket.val = 0;
                bucket.state = 2;
            }
            const auto it = lower_bound(bucket.vec->begin(), bucket.vec->end(), key, [&](const auto& a, int b) {
                return a.first < b;
            });
            if ((it != bucket.vec->end()) && (it->first == key)) {
                it->second = value;
                return;
            }
            bucket.vec->insert(it, {key, value});
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto& bucket = buckets[key % buckets.size()];
        if (bucket.state == 0) {
            return -1;
        }
        else if (bucket.state == 1) {
            if (bucket.key == key) {
                return bucket.val;
            }
            else {
                return -1;
            }
        }
        else {
            const auto it = lower_bound(bucket.vec->begin(), bucket.vec->end(), key, [&](const auto& a, int b) {
                return a.first < b;
            });
            if ((it == bucket.vec->end()) || (it->first != key)) {
                return -1;
            }
            return it->second;
        }
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto& bucket = buckets[key % buckets.size()];
        if (bucket.state == 1) {
            if (bucket.key == key) {
                bucket.key = 0;
                bucket.val = 0;
                bucket.state = 0;
            }
        }
        else if (bucket.state == 2) {
            const auto it = lower_bound(bucket.vec->begin(), bucket.vec->end(), key, [&](const auto& a, int b) {
                return a.first < b;
            });
            if (it == bucket.vec->end()) {
                return;
            }
            if (it->first != key) {
                return;
            }
            bucket.vec->erase(it);
            if (bucket.vec->size() == 1) {
                bucket.key = bucket.vec->front().first;
                bucket.val = bucket.vec->front().second;
                bucket.vec->clear();
                bucket.state = 1;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
