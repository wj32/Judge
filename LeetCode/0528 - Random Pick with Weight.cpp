class Solution {
private:
    map<int, int> m;
    int sum = 0;
    random_device rd;
    mt19937 gen;

public:
    Solution(vector<int> w) : gen(rd()) {
        for (int i = 0; i < w.size(); i++) {
            m.insert({sum, i});
            sum += w[i];
        }
    }

    int pickIndex() {
        uniform_int_distribution dist(0, sum - 1);
        return prev(m.upper_bound(dist(gen)))->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
