#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
    public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        unordered_map<char,set<char>> row;
        unordered_map<char,set<char>> column;
        map<pair<int,int>,set<char>> square;
        for(int r = 0; r < 9; ++r)
        {
            for(int c = 0; c < 9; ++c)
            {
                if(board[r][c] == '.') continue;

                pair<int,int> square_inx = {r/3,c/3};

                if( row[r].find(board[r][c]) != row[r].end() || //
                    column[c].find(board[r][c]) != column[c].end() || //
                    square[square_inx].find(board[r][c]) != square[square_inx].end())
                   return false;

                row[r].insert(board[r][c]);
                column[c].insert(board[r][c]);
                square[square_inx].insert(board[r][c]);
            }
        }
        return true;
    
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> vcr
    {       { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
            { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
            { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
            { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
            { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
            { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
            { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
            { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
            { '.', '.', '.', '.', '8', '.', '.', '7',
              '9' } };
    cout<<(sol.isValidSudoku(vcr) ? "Yes\n" : "No\n"); 
    return 0;
}