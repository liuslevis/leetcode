// O(m+n): 8 min 2 CE 1 AC. 
// O(1) ?
// Notice:  1. Better solution: use first column to store info instead of set(m+n).

// O(m+n) complexity

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0) return 0;
        if (nums.size()==1) return 1;
        
        int last = nums[0];
        int len = 1;
        int scan = 0;
        while(scan < nums.size() && len < nums.size()) {
            scan++;
            if (nums[scan] != last) {
                last = nums[scan];
                // swap(scan, len)
                int tmp = nums[scan];
                nums[scan] = nums[len];
                nums[len] = tmp;
                
                
                
                len++;                
            }
        }
        return len;
    }
};
void printv(vector<int> v){
    for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cout<< *i <<" ";
    }cout<<endl;
}
void test() {
   int arr[] = {-3,-3,-2,-1,-1,0,0,0,0,0};
   vector<int> input(arr, arr+sizeof(arr)/sizeof(arr[0]));
   vector<int> inputRef = input;
   Solution s;
   cout<<"len:"<<s.removeDuplicates(inputRef)<<endl;
   printv(inputRef);

}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}