// 10 min  1 WA 
// Notice: 0 input
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() < 2) return *max_element(nums.begin(), nums.end());
        
        // given nums[0]~nums[end-1]
        vector<int> f1(nums.begin(), nums.end()-1);
        for (int i = 2; i < f1.size(); i++) {
            f1[i] = f1[i] + *max_element(f1.begin(), f1.begin()+1 + i-2);
        }
        
        
        // given nums[1]~nums[end]
        vector<int> f2(nums.begin()+1, nums.end());
        for (int i = 2; i < f2.size(); i++) {
            f2[i] = f2[i] + *max_element(f2.begin(), f2.begin()+1 + i-2);
        }
        
        return max(*max_element(f1.begin(), f1.end()), *max_element(f2.begin(), f2.end()));
    }
};

