class Solution {
public:
    string pushDominoes(string dominoes) {
        int lastIndex = -1;
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] != '.') {
                if (lastIndex == -1) {
                    if (dominoes[i] == 'L') {
                        fill(dominoes.begin(), dominoes.begin() + i, 'L');
                    }
                }
                else if (lastIndex + 1 < i) {
                    if (dominoes[lastIndex] == dominoes[i]) {
                        fill(dominoes.begin() + lastIndex + 1, dominoes.begin() + i, dominoes[i]);
                    }
                    else if (dominoes[lastIndex] == 'R') {
                        assert(dominoes[i] == 'L');
                        const int halfWidth = (i - (lastIndex + 1)) / 2;
                        fill(dominoes.begin() + lastIndex + 1, dominoes.begin() + lastIndex + 1 + halfWidth, 'R');
                        fill(dominoes.begin() + i - halfWidth, dominoes.begin() + i, 'L');
                    }
                }
                lastIndex = i;
            }
        }
        if ((lastIndex != -1) && (dominoes[lastIndex] == 'R')) {
            fill(dominoes.begin() + lastIndex + 1, dominoes.end(), 'R');
        }
        return dominoes;
    }
};
