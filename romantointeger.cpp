#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> map = {{'I', 1}, {'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
        int res = 0;
        for(auto i = 0; i < s.length(); ++i)
        {
            if(map[s[i+1]] <= map[s[i]]) res += map[s[i]];
            else res -= map[s[i]]; 
        }
        return res;
        }
};

int main()
{
    Solution sol;
    string s = "VII";
    cout<<sol.romanToInt(s)<<endl;
    return 0;
}