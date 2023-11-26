#include <iostream>
#include <string.h>
#include <math.h>
#include <cstddef>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
    long long res = 0;
    int sign = 1;
    int it = s.find_first_not_of(' ');
    for(;isdigit(s[it]) || s[it] == '-' || s[it] == '+';it++)
    {
        if(s[it] == '-' || s[it] == '+') sign = 1 - 2 * (s[it] == '-');
        if(s[it] > '0' && s[it] <= '9') res = res * 10 + s[it] - '0';
    }
    res *= sign;
    return  res < INT_MIN ? INT_MIN : res > INT_MAX ? INT_MAX : res;
    }
};

int main()
{
    Solution solve;
    string s = "+-12";
    int num = solve.myAtoi(s);
    cout<<num<<endl;
    return 0;
}

