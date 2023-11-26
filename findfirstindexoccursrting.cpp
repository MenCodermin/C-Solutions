#include <iostream>
#include <string.h>


using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for(int i = 0; i <= m - n; ++i)
        {
            int j = 0;
            for(; j < n; ++j)
                if(haystack[j + i] != needle[j]) break;
            if(j == n) return i;
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    string haystack = "abc", needle = "c";
    int res = sol.strStr(haystack,needle);
    cout<<res<<endl;
    return 0; 
}