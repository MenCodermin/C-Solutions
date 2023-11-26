#include "iostream"
#include "vector"
#include "algorithm"
#include "math.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices);
};

int Solution::maxProfit(vector<int> & prices)
{
    int l = 0, r = 1, profit = 0, maxProfit = 0;
    
    for(; r < prices.size(); ++r)
    {
        profit = max(profit, prices[r] - prices[l]);
        // if(prices[l] > prices[r]) l = r;
    }
    return profit;
}

int main()
{
    Solution solution;

    vector<int> prices = {3,3,5,0,0,3,1,4};

    cout<<"Answer: "<<solution.maxProfit(prices)<<endl;
}