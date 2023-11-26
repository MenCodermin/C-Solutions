#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 2; ++i)
        {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1]))
            {
                int lo = i + 1 , hi = nums.size() - 1, sum = -nums[i];
                while(lo < hi)
                {
                    if(nums[lo] + nums[hi] == sum)
                    {
                        vector<int> temp = {nums[i],nums[lo],nums[hi]};
                        res.push_back(temp);

                        while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi - 1]) hi--;

                        ++lo;--hi;
                    }
                    else if(nums[lo] + nums[hi] < sum) ++lo;
                    else --hi;
                }
            }
        }
        return res;
    }
};


int main()
{
    Solution sol;
    vector<int> sam = {-2,-2,-1,-1,-1,0,0,0,2,2,2};
    vector<vector<int>> res;
    res = sol.threeSum(sam);
    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res.size(); ++j) cout<<res[i][j]<<" ";
        cout<<endl;
    }
        return 0;
}

