#include "iostream"
#include "math.h"

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long a = abs(dividend), b = abs(divisor), ans = 0;
        bool sign = dividend > 0 == divisor > 0;
        while (a >= b) 
        {
            long temp = b, m = 1;
            while (temp << 1 <= a) 
            {
                temp <<= 1;
                m <<= 1;
            }
            a -= temp;
            ans += m;
        }

        return sign ? ans : -ans;
    }
};

int main()
{
    Solution sol;
    int f = 26, s = 2;
    cout<<sol.divide(f,s)<<endl;
    return 0;
}