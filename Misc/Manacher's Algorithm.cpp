#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        vector<int> r(s.size(), 0);
        int center = 0;
        int span = 0;
        int i = 1;

        const auto print = [&](char desc) {
            for (const int m : r) {
                cout << setw(2) << m * 2 + 1 << " ";
            }
            cout << endl;
            for (int j = 0; j < i; j++) {
                cout << "   ";
            }
            cout << " " << desc;
            cout << endl;
        };

        while (i < s.size()) {
            const int right = center + span + 1;
            if (i < right) {
                const int j = center - (i - center);
                r[i] = j - max(j - r[j], center - span);
                print('|');
            }
            if (i + r[i] + 1 >= right) {
                center = i;
                span = r[i];
                const int spanLimit = min(static_cast<int>(s.size()) - center - 1, center);
                print('.');
                while ((span < spanLimit) && (s[center + span + 1] == s[center - span - 1])) {
                    span++;
                    r[i] = span;
                    print('+');
                }
            }
            i++;
        }

        return *max_element(r.begin(), r.end());
    }

    int countSubstringsFull(string s) {
        string t((s.size() * 2) + 1, '\0');
        t[0] = '^';
        for (int i = 0; i < s.size(); i++) {
            t[(i * 2) + 1] = s[i];
            t[(i * 2) + 2] = ' ';
        }
        t[s.size() * 2] = '$';
        return countSubstrings(t);
    }
};

int main() {
    Solution s;
    s.countSubstrings("abaxabaxabybaxabyb");
    s.countSubstringsFull("abaxabaxabybaxabyb");
    return 0;
}
