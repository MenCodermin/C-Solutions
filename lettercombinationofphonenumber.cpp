#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

const vector<string> pad = {
    "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) return {};
        res.push_back("");
        for(auto tries : digits)
        {
            vector<string> tmp;
            for(auto words : pad[tries - '0'])
                for(auto ins : res)
                    tmp.push_back(ins + words);
            res.swap(tmp);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string digits = "23";
    vector<string> result;
    result = sol.letterCombinations(digits);
    for(auto s : result) cout<<s<<endl;
    return 0;
}
