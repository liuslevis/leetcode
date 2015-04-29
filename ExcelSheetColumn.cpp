#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <assert.h>

using namespace std;

// 2 times AC 不熟进制，需要一次过写对bug free!
class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        for (std::string::iterator i = s.begin(); i != s.end(); ++i)
        {
            // char ch = *i;
            char c = *i;
            int digit = c - 'A' + 1;
            num = num*26 + digit;
        }
        return num;
    }
};

void test() {
    Solution s = Solution();
    assert( 28 == s.titleToNumber("AB") );
    assert( 1 == s.titleToNumber("A") );
    assert( 4 == s.titleToNumber("D") );
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}