// Retry!
// 30 min
// 20+ WA TLE CE, 1AC
// Notice: 1. i>>1 does not change value of i; i=i>>1 does. 
//         2. too many bugs

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <locale>
using namespace std;

void printv(vector<int> v) {
  for(auto i : v) {
    cout<<i<<" ";
  }cout<<endl;
}
class Solution {
public:
    int bitOf(vector<int> v) {
        int bit = 0;
        int max = *max_element(v.begin(), v.end());
        if (max < 0) return 0;
        while( 0 < max) {
            bit++;
            max = max >> 1;
        }
        return bit;
    }
    vector<int> concact(int b, vector<int> v) {
        if (0==b) return v;
        if (1==b) {
            int bit = bitOf(v);
            for (int i = 0; i < v.size(); ++i) {
                v[i] |= 1<<(bit);
            }
        }
        return v;
    }
public:
    vector<int> grayCode(int n) {
        return grayCodeGen(n);
    }
    
    vector<int> grayCodeGen(int n) {

        if (0>=n) return {0};
        if (1==n) return {0,1};
        // if (2==n) return {0,1,3,2};
        
        // concact(0, grayCode) + concact(1, grayCode)
        vector<int> grayCodeN_1 = grayCodeGen(n - 1);
        
        vector<int> smallPart = concact(0, grayCodeN_1);
        
        reverse(grayCodeN_1.begin(), grayCodeN_1.end());
        
        vector<int> largePart = concact(1, grayCodeN_1);
        // small + large
        smallPart.resize( largePart.size());
        smallPart.insert(smallPart.end(), largePart.begin(), largePart.end());

        return smallPart;
    }
};


void test() {
  Solution s = Solution();
  printv(s.grayCode(0));
  printv(s.grayCode(1));
  printv(s.grayCode(2));
  printv(s.grayCode(3));
  // cout<<"HI2"<<endl;
  // printv(s.grayCode(4));
  // cout<<"HI3"<<endl;
  // cout<< s.bitOf({3}) <<endl;


}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}