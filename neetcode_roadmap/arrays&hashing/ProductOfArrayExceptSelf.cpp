#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left_prefix(nums.size(), 1);
        vector<int> right_prefix(nums.size(), 1);
        vector<int> result(nums.size(), 1);

        left_prefix[0] = 1;
        right_prefix[nums.size() - 1] = 1;

        for (int i = 1; i < nums.size(); i++) {
            left_prefix[i] = left_prefix[i - 1] * nums[i - 1];
            right_prefix[nums.size() - i - 1] = right_prefix[nums.size() - i] * nums[nums.size() - i];
        }

        for (int i = 0; i < nums.size(); i++) {
            result[i] = left_prefix[i] * right_prefix[i];
        }

        return result;
    }
};
