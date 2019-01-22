class MyHashSet {
private:
    struct Bucket {
        int val : 29;
        int state : 3;
        shared_ptr<vector<int>> vec;
    };

    vector<Bucket> buckets;

public:
    /** Initialize your data structure here. */
    MyHashSet() {
        buckets.resize(100000, Bucket{0, 0, {}});
    }

    void add(int key) {
        auto& bucket = buckets[key % buckets.size()];
        if (bucket.state == 0) {
            bucket.val = key;
            bucket.state = 1;
        }
        else {
            if (bucket.state == 1) {
                if (!bucket.vec) {
                    bucket.vec = make_shared<vector<int>>();
                }
                bucket.vec->push_back(bucket.val);
                bucket.val = 0;
                bucket.state = 2;
            }
            const auto it = lower_bound(bucket.vec->begin(), bucket.vec->end(), key);
            if ((it != bucket.vec->end()) && (*it == key)) {
                return;
            }
            bucket.vec->insert(it, key);
        }
    }

    void remove(int key) {
        auto& bucket = buckets[key % buckets.size()];
        if (bucket.state == 1) {
            if (bucket.val == key) {
                bucket.val = 0;
                bucket.state = 0;
            }
        }
        else if (bucket.state == 2) {
            const auto it = lower_bound(bucket.vec->begin(), bucket.vec->end(), key);
            if (it == bucket.vec->end()) {
                return;
            }
            if (*it != key) {
                return;
            }
            bucket.vec->erase(it);
            if (bucket.vec->size() == 1) {
                bucket.val = bucket.vec->front();
                bucket.vec->clear();
                bucket.state = 1;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto& bucket = buckets[key % buckets.size()];
        if (bucket.state == 0) {
            return false;
        }
        else if (bucket.state == 1) {
            return bucket.val == key;
        }
        else {
            const auto it = lower_bound(bucket.vec->begin(), bucket.vec->end(), key);
            if (it == bucket.vec->end()) {
                return false;
            }
            return *it == key;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
