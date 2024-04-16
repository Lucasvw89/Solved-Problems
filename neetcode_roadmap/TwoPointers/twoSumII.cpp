#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        int curr = numbers[l] + numbers[r];
        while (curr != target) {
            if (curr > target)
                r--;
            else
                l++;
            curr = numbers[l] + numbers[r];
        }
        vector<int> result = {l + 1, r + 1};
        return result;
    }
};
