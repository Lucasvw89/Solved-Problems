#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m.emplace(target-nums[i], i);
            }
            else {
                result.push_back(m[nums[i]]);
                result.push_back(i);
            }
        }
        return result;
    }
};
