#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <assert.h>
#include <locale>
#include <cstdint>

using namespace std;
/*
2d, ref: http://blog.unieagle.net/2012/12/04/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Abest-time-to-buy-and-sell-stock-ii/
这个更简单了，题目要求可以多次买卖，但是同一时间只能有一股在手里。
这样就可以在每次上升子序列之前买入，在上升子序列结束的时候卖出。相当于能够获得所有的上升子序列的收益。
而且，对于一个上升子序列，比如：5，1，2，3，4，0 中的1，2，3，4序列来说，对于两种操作方案：
一，在1买入，4卖出；
二，在1买入，2卖出同时买入，3卖出同时买入，4卖出；
这两种操作下，收益是一样的。
*/
class Solution {

public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2) return 0;
        int curProfit = 0;
        for(int i = 0; i < prices.size() - 1; i++) {
            if (prices[i+1] > prices[i]) {
                curProfit+= prices[i+1] - prices[i];
            }
        }
        return curProfit;
    }
};

void test() {
    // 2,1
    // 2,6,8,7,8,7,9,4,1,2,4,5,8
    // 1,9,1
    // 4,1,2
    // 2,1,2,0,1
    Solution s;
    std::vector<int> v{2,1,2,0,1};
    std::vector<int>&ref = v;
   assert(2 == s.maxProfit(ref));
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}