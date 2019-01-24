class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        const auto it = upper_bound(letters.begin(), letters.end(), target);
        return (it != letters.end()) ? *it : *letters.begin();
    }
};
