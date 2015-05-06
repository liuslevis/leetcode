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
ref:http://blog.unieagle.net/2012/12/03/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Abest-time-to-buy-and-sell-stock/
一次扫描完成。只需要找到最大增长即可。
从前往后，用当前价格减去此前最低价格，就是在当前点卖出股票能获得的最高利润。
扫描的过程中更新最大利润和最低价格就行了。
O(n)


*/
class Solution {
public:
    int maxProfit(vector<int>& p) {
        if (p.size()<2) return 0;
        int curMinPrice = p[0];
        int max=0;
        for (int i = 1; i < p.size(); i++) {
            int curProfit = p[i] - curMinPrice;
            if (curProfit > max) {
                max = curProfit;
            }
            if(p[i]<curMinPrice) {
                curMinPrice = p[i];
            }
        }
        return max;
    }
};
