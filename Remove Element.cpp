// Python
// 1 RTE 1AC
class Solution:
    # @param {integer[]} nums
    # @param {integer} val
    # @return {integer}
    def removeElement(self, nums, val):
        valCnt = 0
        for num in nums:
            if num==val:
                valCnt+=1
        
        front = 0
        back = len(nums)-1
        
        if (back < 1):
            return len(nums) - valCnt
        
        while(front < back and nums[back]==val):
            back-=1
        while(front < back):
            if (nums[front]==val):
                #swap front back
                tmp = nums[front]
                nums[front] = nums[back]
                nums[back] = tmp
                
                while(nums[back]==val):
                    back-=1
            
            front+=1
        
        return len(nums) - valCnt
        pass

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <locale>
#include <iterator>

// C++
// RTE, not sure what's wrong in c++
using namespace std;

class Solution {

public:
    int removeElement(vector<int>& nums, int val) {
        int newlen = nums.size();
        int back = nums.size() - 1; // pointing to back elem to swap
        
        int countVal = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (val==nums[i]) countVal++;
        }
        
        if (0==countVal) return nums.size();
        
        for (int i = 0; i < nums.size(); ++i) {

            if (val==nums[i]) {

                
                // swap(nums[i], nums[back])
                if (back <= i) {
                    // cout<<"HI"<<i<<" "<<back<<endl;
                    // for (int i = 0; i < nums.size(); ++i)
                    // {        
                    //     cout<<nums[i]<<" ";
                    // }cout<<endl;
                    return newlen - countVal;
                }
                
                while(nums[back]==val) {
                    back--;
                }
                
                int tmp = nums[back];
                nums[back] = nums[i];
                nums[i] = tmp;
                back--;
            }
        }

        return newlen - countVal;
       
    }
};

int _countVal(vector<int> nums, int val) {
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (val==nums[i]) count++;
    }
    return count;
}

int __countVal(vector<int> &nums, int val) {
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (val==nums[i]) count++;
    }
    return count;
}

int countVal(vector<int> &nums, int val) {
    return __countVal(nums, val);
}

void test(){
    std::vector<int> nums = {1,1,3,5,3,5,67,2,3,1,2};//{2},3
    std::vector<int> &r = nums;
    cout<<countVal(r, 3)<<endl;

    Solution s = Solution();
    int res = s.removeElement(r, 3);
    cout<< res << endl;
    
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}