class Solution {
public:
    string countAndSay(int n) {
        n--;

        string s = "1";

        while (n != 0) {
            string t;

            for (int i = 0; i < s.size(); ) {
                int j = i + 1;
                while ((j < s.size()) && (s[j] == s[i])) {
                    j++;
                }

                t += to_string(j - i);
                t += s[i];

                i = j;
            }

            s = t;
            n--;
        }

        return s;
    }
};
