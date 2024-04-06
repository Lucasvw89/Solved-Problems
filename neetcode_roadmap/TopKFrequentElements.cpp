#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<pair<int, int> > pq;
        unordered_map<int, int> m;
        unordered_map<int, bool> used;

        for (int num: nums) {
            m[num]++;
            pq.emplace(m[num], num);
        }

        vector<int> v;
        int j = 0;
        int size = pq.size();

        while (!pq.empty()) {
            if (!used[pq.top().second]) {
                used[pq.top().second] = true;
                v.push_back(pq.top().second);
                j++;
            }
            pq.pop();
            if (j == k) break;
        }
        return v;
    }
};
