class Solution {
public:
    void recurse(vector<int>* nums, vector<vector<int>>* result, int position) {
        if (position == nums->size()) {
            result->push_back(*nums);
        }
        else {
            recurse(nums, result, position + 1);

            set<int> seen;
            seen.insert((*nums)[position]);

            for (int k = position + 1; k < nums->size(); k++) {
                if (seen.find((*nums)[k]) == seen.end()) {
                    seen.insert((*nums)[k]);
                    swap((*nums)[position], (*nums)[k]);
                    recurse(nums, result, position + 1);
                    swap((*nums)[position], (*nums)[k]);
                }
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        recurse(&nums, &result, 0);
        return result;
    }
};
