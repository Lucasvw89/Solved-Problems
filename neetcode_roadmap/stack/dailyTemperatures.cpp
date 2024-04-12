#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int> > s;       // temp, idx
        vector<int> result(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {
            int u = temperatures[i];
            while (!s.empty() && u > s.top().first) {
                result[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.emplace(make_pair(u, i));
        }
        return result;
    }
};
