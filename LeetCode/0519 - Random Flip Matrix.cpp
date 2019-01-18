class Solution {
private:
    random_device rd;
    mt19937 gen;
    int nrow;
    int ncol;
    unordered_map<int, int> m;
    int remaining;

public:
    Solution(int n_rows, int n_cols) :
        gen(rd()), nrow(n_rows), ncol(n_cols) {
        remaining = nrow * ncol;
    }

    vector<int> flip() {
        assert(remaining != 0);
        remaining--;
        uniform_int_distribution dist(0, remaining);

        int lastIndex = remaining;
        const auto it = m.find(lastIndex);
        if (it != m.end()) {
            lastIndex = it->second;
            m.erase(it);
        }

        int index = dist(gen);
        if (index != remaining) {
            auto it = m.find(index);
            if (it != m.end()) {
                index = it->second;
            }
            else {
                it = m.insert({index, -1}).first;
            }
            it->second = lastIndex;
        }
        else {
            index = lastIndex;
        }
        return {index / ncol, index % ncol};
    }

    void reset() {
        m.clear();
        remaining = nrow * ncol;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
