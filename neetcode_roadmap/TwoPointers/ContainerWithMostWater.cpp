#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int volume = 0;
        while (l < r) {
            volume = max(volume, (r-l) * min(height[l], height[r]));
            if (height[l] <= height[r])
                l++;
            else
                r--;
        }
        return volume;
    }
};
