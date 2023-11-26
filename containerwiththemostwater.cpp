#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        while(l < r)
        {
            res = max(res,min(height[l],height[r]) * (r - l));
            if(height[l] < height[r]) ++l;
            else --r;
        }
    return res;
    }
};

int main()
{
    Solution sol;
    srand(time(NULL));
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    // for(int i = 0; i < 9; ++i)
    //     height.push_back(rand() % 10);
    for(auto i : height) cout<<i<<" ";
    cout<<endl;
    cout<<sol.maxArea(height);
    return 0;
}