#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i: nums) {
            s.emplace(i);
        }
        return s.size() != nums.size();
    }
};
