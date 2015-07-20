// 5min 5 WA due to ...
// Notice: usage of *max_element(v.begin(), v.begin()+1 + 1)
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int> f(nums.size(), 0);
        f[0] = nums[0];
        f[1] = nums[1];
        
        for (int i = 2; i < nums.size(); i++) {
            f[i] = nums[i] + *max_element(f.begin(), f.begin()+1+i-2);
        }
        
        return *max_element(f.begin(), f.end());
    }
};
