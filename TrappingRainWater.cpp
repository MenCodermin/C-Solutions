#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int res =  0, l = 0, r = height.size() - 1, leftMax = height[l],
        rightMax = height[r];
        while(l < r)
        {
            if(leftMax < rightMax)
            {
                ++l;
                leftMax = max(leftMax,height[l]);
                res += leftMax - height[l];
            }
            else
            {
                --r;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r]; 
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = sol.trap(height);
    cout<<res<<endl;
}