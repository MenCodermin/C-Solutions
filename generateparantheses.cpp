#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<string> &ans, int open, int close, int n, string rem);

class Solution {
public:
    vector<string> generateParenthesis(int n) {
            vector<string>res;
            solve(res,0,0,n,"");
            return res;
    }
};

int main()
{
    Solution sol;
    vector<string> str;
    int n = 3;
    str = sol.generateParenthesis(n); 
    for(auto s : str) cout<<s<<" ";
    return 0;
}

void solve(vector<string> &ans, int open, int close, int n, string rem)
{
    if(rem.size() == n*2) ans.push_back(rem);
    
    if(open < n) solve(ans, open + 1, close, n, rem + "(");
    if(close < open) solve(ans, open, close + 1, n, rem + ")");
}