class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        const auto n = beginWord.size();
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        int level = 1;
        int remainingInLevel = 1;

        q.push(beginWord);

        while (!q.empty()) {
            if (q.front() == endWord) {
                return level;
            }

            for (int i = 0; i < n; i++) {
                const char c = q.front()[i];
                for (int j = 0; j < 26; j++) {
                    q.front()[i] = 'a' + j;
                    const auto it = wordSet.find(q.front());
                    if (it != wordSet.end()) {
                        q.push(*it);
                        wordSet.erase(it);
                    }
                }
                q.front()[i] = c;
            }

            q.pop();

            remainingInLevel--;
            if (remainingInLevel == 0) {
                level++;
                remainingInLevel = q.size();
            }
        }

        return 0;
    }
};
