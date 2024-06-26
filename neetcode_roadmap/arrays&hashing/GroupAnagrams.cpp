#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > m;
        for (string s: strs) {
            string s2 = s;
            sort(s2.begin(), s2.end());
            m[s2].push_back(s);
        }
        vector<vector<string> > v;
        for (auto ma: m) {
            v.push_back(ma.second);
        }
        return v;
    }
};
