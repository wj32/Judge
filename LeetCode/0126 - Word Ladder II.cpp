class Solution {
public:
    struct Node {
        Node* prev;
        string word;
    };

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        const auto n = beginWord.size();
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<Node*> q;
        int level = 1;
        int remainingInLevel = 1;
        vector<string> wordsToRemove;

        q.push(new Node{nullptr, beginWord});

        while (!q.empty()) {
            if (q.front()->word == endWord) {
                break;
            }

            for (int i = 0; i < n; i++) {
                const char c = q.front()->word[i];
                for (int j = 0; j < 26; j++) {
                    q.front()->word[i] = 'a' + j;
                    const auto it = wordSet.find(q.front()->word);
                    if (it != wordSet.end()) {
                        q.push(new Node{q.front(), *it});
                        wordsToRemove.push_back(*it);
                    }
                }
                q.front()->word[i] = c;
            }

            q.pop();

            remainingInLevel--;
            if (remainingInLevel == 0) {
                level++;
                remainingInLevel = q.size();

                for (const auto& s : wordsToRemove) {
                    wordSet.erase(s);
                }
                wordsToRemove.clear();
            }
        }

        vector<vector<string>> r;

        while (remainingInLevel != 0) {
            if (q.front()->word == endWord) {
                vector<string> v(level);
                auto node = q.front();
                for (int i = level - 1; i >= 0; i--) {
                    v[i] = node->word;
                    node = node->prev;
                }
                r.push_back(v);
            }

            q.pop();
            remainingInLevel--;
        }

        return r;
    }
};
