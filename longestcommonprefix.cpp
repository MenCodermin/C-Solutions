#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        int j;
        for(int i = 1; i < strs.size(); ++i)
        {
            for(j = 0; j < strs[i].size(); ++j)
                if( ans[j] != strs[i][j]) break;
            ans = ans.substr(0,j);
            if(ans.size() == 0) return "";
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> str = {"find","fine","fiber"};
    cout<<sol.longestCommonPrefix(str)<<endl;
    return 0;
}


