// 10 WA 1h AC. 
// Notice: 1. The boundrary of bin-search 2. Check a[i] before return -1 in the end.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (0==nums.size()) return -1;
        if (1==nums.size()) return nums[0]==target ? 0 : -1;
        
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int m = (left+right)/2;
            
            if (target == nums[m]) {
                return m;
            } else {
                if (nums[left] <= nums[right]) {
                    // Normal binary search
                    if (nums[m]<target) {
                        left = m+1;
                    } else {
                        right = m-1;
                    }
                    
                } else {
                    // revert at pivot    
                    if (nums[left] <= nums[m] ) {//m1
                        // if (target < nums[m] && target = nums[left]) //Error
                        if (target < nums[m] && target >= nums[left]) 
                            right = m - 1;
                        else 
                            left = m + 1;
                    } else {//m2
                        if (target > nums[m] && target <= nums[right]) 
                            left = m + 1;
                        else 
                            right = m - 1;
                    }
                }
            }
        }
        
        // Notice
        if (nums[left]==target) return left;

        return -1;
    }
};
