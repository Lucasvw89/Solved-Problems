#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int result = 0;
        
        unordered_map<int, int> m;
        
        for (int x: nums) {
            m[x] = 0;
        }

        int x, i;

        for (auto u: m) {
            x = i = u.first;
            while (m.find(i - 1) == m.end() && m.find(i + m[i]) != m.end()) {
                m[i]++;
            }
            result = max(result, m[i]);
        }

        return result;
    }

};
