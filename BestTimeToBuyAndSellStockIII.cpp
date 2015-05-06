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
2 shoot AC. times 1h.
限制2次买卖，prices分割成2部分，按II题做
TODO 任意n次买卖？
*/
class Solution {
public:
    int maxProfit(vector<int>& p) {
        if (p.size()<2) return 0;

        vector<int> forwardMaxProfits; // i th element is the profit within prices[0..i-1]
        forwardMaxProfits.push_back(0);

        int curMinPrice = p[0];
        int curMaxProfit=0;
        for (int i = 1; i < p.size(); i++) {
            int curProfit = p[i] - curMinPrice;
            if (curProfit > curMaxProfit) {
                curMaxProfit = curProfit;
            }
            if(p[i]<curMinPrice) {
                curMinPrice = p[i];
            }
            forwardMaxProfits.push_back(curMaxProfit);
        }

        if (p.size() < 4) return *max_element(forwardMaxProfits.begin(), forwardMaxProfits.end());

        vector<int> backwardMaxProfits; // i th element is the profit within prices[size-1-i ... size-1]
        backwardMaxProfits.push_back(0);
        int curMaxPrice = p[p.size()-1];
        curMaxProfit = 0;
        for (int i = p.size()-2; i >= 0; i--) {
            int curProfit = curMaxPrice - p[i];
            if (curProfit > curMaxProfit) {
                curMaxProfit = curProfit;
            }
            if (p[i] > curMaxPrice) {
                curMaxPrice = p[i];
            }
            backwardMaxProfits.push_back(curMaxProfit);

        }
       
        int maxResult = 0;
        for (int i = 0; i < p.size(); ++i)
         {
             int curProfit = forwardMaxProfits[i] + backwardMaxProfits[p.size()-i-1];
             if (curProfit > maxResult) maxResult = curProfit;

         } 
        return maxResult;
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