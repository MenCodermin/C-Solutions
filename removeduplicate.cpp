#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] != val) nums[j++] = nums[i];
        return j;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int k = 2;
    //for(int i = 0; i < 6; ++i) nums[i] = (k++) + 2;
    for(auto it : nums) cout<<it<<" ";
    cout<<endl;
    int res = sol.removeElement(nums,k);
    cout<<res<<endl;
    return 0;
}