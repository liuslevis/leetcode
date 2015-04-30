#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <map>
#include <limits>
using namespace std;
/*
TODO:  
1 times, 26min AC. Be Faster!

*/
class Solution {
private:
    bool isAllNegative(vector<int> nums) {
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        {
            if (*i > 0 ) return false;
        }
        return true; 
    }
public:
    int firstMissingPositive(vector<int>& nums) {
        cout<<endl;
        if (nums.size()==0) {
            return 1;
        }

        if (isAllNegative(nums)) {
            return 1;
        }
        map<int, bool> map;

        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        {
            map[*i] = true;
            // cout<<"marking:"<< *i << endl;

        }
        for (int i = 1; i <= INT_MAX; ++i)
        {
            if (map.find(i) == map.end()) return i;
            // cout<<"finding:"<< i << endl;
        }
        return 1;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v1;
    vector<int> v2{0,1};
    vector<int> v3{1};
    vector<int> v4{2,1};
    vector<int> &rv1 = v1;
    vector<int> &rv2 = v2;
    vector<int> &rv3 = v3;
    vector<int> &rv4 = v4;
    assert( 1==s.firstMissingPositive(rv1));
    assert( 2==s.firstMissingPositive(rv2));
    assert( 2==s.firstMissingPositive(rv3));
    assert( 3==s.firstMissingPositive(rv4));
    cout <<" pass!" << endl;
    return 0;
}