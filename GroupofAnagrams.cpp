#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    vector<string> exp {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res;
    unordered_map<string,vector<string>> mp;
    for(int i = 0; i < exp.size(); ++i)
    {
        s =  exp[i];
        sort(exp[i].begin(),exp[i].end());
        mp[exp[i]].push_back(s);
    }
    for(auto it : mp) res.push_back(it.second);
    for(vector<string> it : res)
        for(string ss : it) cout<<ss<<" ";
    
}

