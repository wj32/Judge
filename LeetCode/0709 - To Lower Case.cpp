class Solution {
public:
    string toLowerCase(string str) {
        for (char& c : str) {
            c = tolower(c);
        }
        return str;
    }
};
