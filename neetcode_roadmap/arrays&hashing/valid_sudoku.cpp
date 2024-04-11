#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int count = 0;
        unordered_set<string> s;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char number = board[i][j]; 
                if (number != '.') {
                    s.emplace("l" + to_string(i) + number);
                    s.emplace("c" + to_string(j) + number);
                    s.emplace("s" + to_string(i / 3) + to_string(j / 3) + number);
                    count++;
                    if (count != s.size()/3) return false;
                }
            }
        }
        return true;
    }
};
