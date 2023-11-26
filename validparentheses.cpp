#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char,char> mp;
        mp['{'] = '}';
        mp['('] = ')';
        mp['['] = ']';
        string res;
        res.push_back(s[0]);
        for(unsigned int i = 1; i < s.size(); ++i)
        {
        
            if (mp[res.back()] == s[i]) res.pop_back();
            else res.push_back(s[i]);        
        }
        return res.size() ? 0 : 1;
    }
};

int main()
{
    Solution sol;
    string s = "[]";
    if(sol.isValid(s)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}