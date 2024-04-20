#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int> > result;
        sort(nums.begin(), nums.end());
        int curr;
        for (int i = 0; i < nums.size(); ++i) {
            int target = -1 * nums[i];
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                curr = nums[j] + nums[k];
                if (curr == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    result.insert(temp);
                    j++;
                    k--;
                }
                else if (curr > target) k--;
                else if (curr < target) j++;
            }
        }
        vector<vector<int> > v(result.begin(), result.end());
        return v;
    }
};
