#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <assert.h>

using namespace std;
/*
15 times AC: map.begin()->first 访问第一个元素，而不是 (++map.begin())->first
*/
class Solution {
    unordered_map<int, bool> map;
public:
    int singleNumber(vector<int>& nums) {
        for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
            int num = *it;
            // num first appear
            if (map.find(num) == map.end()){
                map[num] = true;
            } else { // second time appear, remove from map
                map.erase(map.find(num));
            }
        }
        return (map.begin())->first;
    }
};

void test() {
    int arr[]={1,1,22,2,2,33,33};
    vector<int> input(arr,arr+1);
    Solution s = Solution();
    assert(1==s.singleNumber(input));
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}