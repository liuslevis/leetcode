#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <assert.h>

using namespace std;

// 3 times AC, not familiar with bit op.
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0x00) {
            if ( (n & 0x01) == 0x01) count++;    
            n = n >> 1;
        }
        return count;
        
    }
};

void test() {
    Solution s = Solution();
    uint32_t n = 7;

    cout<< s.hammingWeight(n) <<endl;

}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}