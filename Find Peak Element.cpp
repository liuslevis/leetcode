// logarithmic: 26 min 10+ WA 1 AC. 
// linear:       8 min 1 AC
// Notice: 1. speed up

// linear complexity
class Solution {
private:
    bool isPeak(vector<int> nums, int index) {
        if (nums.size()<=0) return false;
        if (nums.size()==1 && index==0) return true;
        
        if (index < 0 && index > nums.size()) return false;
        
        int l = index - 1;
        int r = index + 1;
        int lnum = INT_MIN;
        int rnum = INT_MIN;
        if (l > -1 && l < nums.size()) lnum = nums[l]; 
        if (r > -1 && r < nums.size()) rnum = nums[r];
        
        if (lnum < nums[index] && rnum < nums[index]) return true;
        
        return false;
    }
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            if (isPeak(nums, i)) return i;
        return -1;
    }
};

// recursive, logarithmic complexity (divide 'n conquer)
class Solution {
private:
    bool isPeak(vector<int> nums, int index) {
        if (index < 0 || index >= nums.size()) return false;
        if (nums.size()<=0) return false;
        if (nums.size()==1 && index==0) return true;
        
        int l = index - 1;
        int r = index + 1;
        long lnum = INT_MIN;
        long rnum = INT_MIN;
        if (l > -1 && l < nums.size()) lnum = nums[l]; 
        if (r > -1 && r < nums.size()) rnum = nums[r];
        
        if (lnum < nums[index] && rnum < nums[index]) return true;
        else return false;
    }
    int p(vector<int> nums, int i, int j) {
        if (!(i < j)) return -1;
        if ((i >= nums.size() && i < 0)||(j >= nums.size() && j < 0)) return -1;
        
        if (isPeak(nums, i)) return i;
        if (isPeak(nums, j)) return j;
        
        int m = (i+j)/2;
        
        if (isPeak(nums, m)) {
            return m;
        } else {
            if (isPeak(nums, m-1)) return m-1;
            if (isPeak(nums, m+1)) return m+1;
            
            // m-1 higher
            if (m-1 >= 0 && nums[m-1] > nums[m]) {
                int leftIndex = p(nums, i, m-1);
                if (leftIndex!=-1)  return leftIndex;
            }
            // m+1 higher
            if (m+1 < nums.size() && nums[m+1] > nums[m]) {
                int rightIndex = p(nums, m+1, j);
                if (rightIndex!=-1) return rightIndex;
            }
        }
        return -1;
    }
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size()==0) return -1;
        if (nums.size()==1) return 0;
        // size >= 2
        return p(nums, 0, nums.size());
    }
};