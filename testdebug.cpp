#include <iostream>
#include <time.h>
#include <map>
#include <vector>

using namespace std;


int main()
{
    srand(time(NULL));
    map<int,int> map;
    vector<int> pairs;
    vector<int> nums;
    int target;
    for(int i = 0; i < 5; i++)
        nums.push_back(rand() % 10);
    for(auto i : nums)
        cout<<i<<" ";
    cout<<endl;
    cin>>target;
    for(int i = 0; i < nums.size(); i++)
        { 
            int complement =  target - nums[i];
            if(map.find(complement) != map.end())
            {
                pairs.push_back(map.find(complement)->second);
                pairs.push_back(i);
                break;
            }
            map.insert(pair<int,int>(nums[i],i));
        }

    for(auto i : pairs)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}    
