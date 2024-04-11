#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') { st.emplace(c); }
            else if (!st.empty()) {
                switch (c) {
                    case ')':
                        if (st.top() == '(') st.pop();
                        else return false;
                        break;
                    case ']':
                        if (st.top() == '[') st.pop();
                        else return false;
                        break;
                    case '}':
                        if (st.top() == '{') st.pop();
                        else return false;
                        break;
                }
            }
            else return false;
        }
        return st.empty();
    }
};
