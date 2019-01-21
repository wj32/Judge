class Solution {
public:
    int recurse(const string& ring, const string& key, const array<vector<int>, 26>& indicesByChar, int keyIndex, int position, vector<vector<int>>& cache) {
        if (keyIndex == key.size()) {
            return 0;
        }
        const auto cacheEntry = &cache[keyIndex][position];
        if (*cacheEntry == -1) {
            *cacheEntry = [&] {
                if ((keyIndex != 0) && (key[keyIndex] == key[keyIndex - 1])) {
                    return recurse(ring, key, indicesByChar, keyIndex + 1, position, cache) + 1;
                }

                const auto& indices = indicesByChar[key[keyIndex] - 'a'];
                const auto it = lower_bound(indices.begin(), indices.end(), position);

                const int rightPosition = (it == indices.end()) ? indices.front() : *it;
                int rightDistance = rightPosition - position;
                if (rightDistance < 0) {
                    rightDistance += ring.size();
                }

                const int leftPosition = (it == indices.begin()) ? indices.back() : *prev(it);
                int leftDistance = position - leftPosition;
                if (leftDistance < 0) {
                    leftDistance += ring.size();
                }

                return min(recurse(ring, key, indicesByChar, keyIndex + 1, leftPosition, cache) + leftDistance + 1,
                           recurse(ring, key, indicesByChar, keyIndex + 1, rightPosition, cache) + rightDistance + 1);
            }();
        }
        return *cacheEntry;
    }

    int findRotateSteps(string ring, string key) {
        array<vector<int>, 26> indicesByChar;
        for (int i = 0; i < ring.size(); i++) {
            indicesByChar[ring[i] - 'a'].push_back(i);
        }
        vector<vector<int>> cache(key.size(), vector<int>(ring.size(), -1));
        return recurse(ring, key, indicesByChar, 0, 0, cache);
    }
};
