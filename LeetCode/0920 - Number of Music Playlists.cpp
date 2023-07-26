class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int prime = 1000000007;
        vector<vector<long>> r(n + 1, vector<long>(goal + 1, 0));
        r[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= goal; ++j) {
                // The last k + 1 songs must be unique. So there must be i - k choices if we want to repeat a song.
                r[i][j] = ((r[i - 1][j - 1] * i) % prime + (j > i ? (r[i][j - 1] * max(i - k, 0)) % prime : 0)) % prime;
            }
        }
        return r[n][goal];
    }
};