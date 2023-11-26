#include "iostream"
#include "string"

using namespace std;

class Solution
{
public:
    string CountAndSay(int n)
    {
        string ans = "1",prev = "";
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < ans.size(); ++j)
            {
            int c = 1;
            while(j+c<ans.size() && ans[j] == ans[j+c]) ++c;
            j += (c-1);
            prev += to_string(c);
            prev += ans[j];
            }
            ans = prev;
            prev = "";
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int num  = 4;
    string res = sol.CountAndSay(num);
    for(auto x : res)
        cout<<x;
    cout<<endl;
    return 0;
}