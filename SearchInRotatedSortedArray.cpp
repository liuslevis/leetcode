#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <assert.h>
using namespace std;
/*
TODO:  
8 times, 2h AC. Attention: 1. binarySort. 2. given array is not rotated.

*/
class Solution {
private:
    // TODO O(n) time complexity, to be improve.
    int find_sep(vector<int>& nums) {
        assert(nums.size() > 1);

        int last = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (last > nums[i]) return i;;
        } 
        // not rotated
        assert(false);
        return -1; 
    }

    bool is_ordered_asc(vector<int> &arr) {
        if (arr.size() < 2) return true;
        int last = arr[0];
        for (int i = 1; i < arr.size(); ++i)
        {
            if (last > arr[i]) return false;
        }
        return true;
    }
    int binsort(vector<int> &arr, int begin, int end, int target) {
        // cout<<begin<<" "<<end<<" "<<arr.size()<<" "<<target<<endl;
        if (begin > end) return -1;
        assert(0 <= begin && begin <= end && end < arr.size() );
        if (target < arr[begin] || target > arr[end]) return -1;
        if (target == arr[begin]) return begin;
        if (target == arr[end]) return end;
        
        int mid = int((begin + end) / 2);
        if (target == arr[mid]) return mid;
        if (arr[begin] < target && target < arr[mid]) return binsort(arr, begin + 1, mid - 1, target);
        if (arr[mid] < target && target < arr[end]) return binsort(arr, mid  + 1, end - 1, target);

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            else return -1;
        }
        if (nums.size() == 2) {
            if (nums[0] == target) return 0;
            if (nums[1] == target) return 1;
            return -1;
        }

        if (is_ordered_asc(nums)) {
            return binsort(nums, 0, nums.size()-1, target);
        }

        int sep = find_sep(nums);
        if (sep == -1) return -1; // not rotated

        // [  5  7  8  |  1  2  4 ]
        //   mid   max   min    
        int min_index = sep;
        int max_index = sep-1;
        int mid_index = 0;

        int min = nums[min_index];
        int max = nums[max_index];
        int mid = nums[mid_index];

        if (target < min || target > max) return -1;

        if (target == min) return sep;
        if (target == max) return sep-1;
        if (target == mid) return 0;
        if (min < target && target < mid) return binsort(nums,min_index, nums.size()-1, target);
        if (mid < target && target < max) return binsort(nums,mid_index, max_index, target);

        return -1;
    }
};



void test() {
   int arr[] = {4, 5, 6, 7, 0, 1, 2};
   vector<int> input(arr, arr+sizeof(arr)/sizeof(arr[0]));
   vector<int> inputRef = input;
   Solution s;
   assert(0 == s.search(inputRef, 4));
   assert(1 == s.search(inputRef, 5));
   assert(3 == s.search(inputRef, 7));
   assert(4 == s.search(inputRef, 0));
   assert(5 == s.search(inputRef, 1));
   assert(6 == s.search(inputRef, 2));
   assert(-1 == s.search(inputRef, 3));
   assert(-1 == s.search(inputRef, 8));

   int arr2[] = {1};
   vector<int> input2(arr2, arr2+sizeof(arr2)/sizeof(arr2[0]));
   vector<int> inputRef2 = input2;
   assert(-1 == s.search(inputRef2, 0));

   int arr3[] = {1,3,5};
   vector<int> input3(arr3, arr3+sizeof(arr3)/sizeof(arr3[0]));
   vector<int> inputRef3 = input3;
   assert(-1 == s.search(inputRef3, 2));
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}