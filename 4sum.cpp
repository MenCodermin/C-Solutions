#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0 || size > INT_MAX || size < INT_MIN) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < size - 3; ++i)
        {
            for(int j = i + 1; j < size - 2; ++j)
            {
                int lo = j + 1, hi = size - 1; 
                long long sum = (long long)(target) - (long long)nums[i] - (long long)nums[j];
                while(lo < hi)
                {
                    if((long long)nums[lo] + nums[hi] == sum)
                    {
                        res.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                        while(lo < hi && nums[lo] == nums[lo + 1]) ++lo;
                        ++lo;--hi;
                    }
                    else if((long long)nums[lo] + nums[hi] < sum) ++lo;
                    else --hi;
                } 
                while(j+1 < size && nums[j] == nums[j+1]) ++j;
            }
            while(i+1 < size && nums[i] == nums[i+1]) ++i;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    int target = -294967296;
    vector<vector<int>> res = sol.fourSum(nums,target);
    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j) cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
