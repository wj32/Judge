class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 0) {
            return 0;
        }
        int runStart = 0;
        int runCount = 1;
        int dst = 0;
        for (int i = 1; i <= chars.size(); i++) {
            if ((i < chars.size()) && (chars[i] == chars[runStart])) {
                runCount++;
            }
            else {
                chars[dst] = chars[runStart];
                dst++;
                if (runCount > 1) {
                    const auto s = to_string(runCount);
                    for (const char c : s) {
                        chars[dst] = c;
                        dst++;
                    }
                }
                runStart = i;
                runCount = 1;
            }
        }
        return dst;
    }
};
