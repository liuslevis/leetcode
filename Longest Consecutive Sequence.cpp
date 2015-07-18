//5min 5WA (not sure about define)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase( unique( nums.begin(), nums.end() ), nums.end() );

        int max_len = 1;
        int cur_len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if ( nums[i]-1 == nums[i-1]) {
                cur_len++;
            } else {
                max_len = cur_len > max_len ? cur_len:max_len;
                cur_len = 1;
            }
        }
        return cur_len > max_len ? cur_len:max_len;
        
    }
};
