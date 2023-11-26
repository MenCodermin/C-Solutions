#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window)
    {
        if(h < 0 || (bounce < 0 || bounce > 1) || window > h) return -1;
        int i = 0, j = 0;
        double temp = h;    
         while(round(temp) >= window)
        {
            temp *= bounce;
            i++;
            j++; 
        }
        return i+j;
    }
};

int main()
{
    Bouncingball sol;
    double h = 30, bounce = 0.66, window = 1.5;
    int res = sol.bouncingBall(h,bounce,window);
    cout<<res<<endl;
    return 0;
}