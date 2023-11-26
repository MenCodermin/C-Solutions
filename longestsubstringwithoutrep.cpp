#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == NULL) return 0;
        int i = 0, j = 0, res = 0;
        unordered_set<char> set;
        while(i < s.size() && j < s.size())
        {
            if(set.find(s[j]) == set.end())
            {
                set.insert(s[j++]);
                res = max(res,j-i);
            }
            else set.erase(s[i++]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "abcabcbb";
    int res = sol.lengthOfLongestSubstring(s);
    cout<<res<<endl;
    return 0;
}