#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    set<int> temp (nums.begin(),nums.end());
    int k = 0;
    for(auto it : temp)
        nums[k++] = it;
    return k;
    }
};


int main()
{
    Solution sol;
    vector<int> nums(7);
    vector<int> res;
    int k;
    for(int i = 0 ; i < 7; ++i) nums[i] = 1;
    //nums.push_back(5);
    for(auto it : nums) cout<<it<<" ";
    cout<<endl;
    k = sol.removeDuplicates(nums);

    cout<<k<<endl;
    return 0;
}