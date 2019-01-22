class MagicDictionary {
private:
    map<string, int> m;

public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        m.clear();
        for (const auto& word : dict) {
            string s = word;
            for (int i = 0; i < word.size(); i++) {
                const char old = s[i];
                s[i] = '.';
                m[s] |= 1 << (word[i] - 'a');
                s[i] = old;
            }
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        string s = word;
        for (int i = 0; i < word.size(); i++) {
            const char old = s[i];
            s[i] = '.';
            const auto it = m.find(s);
            if ((it != m.end()) && ((it->second & ~(1 << (word[i] - 'a'))) != 0)) {
                return true;
            }
            s[i] = old;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
