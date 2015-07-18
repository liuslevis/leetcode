// REDO
// 1hours TLE
ass Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int front = i + 1;
            int back = nums.size() - 1;
            while(front < back) {
                int sum = nums[i] + nums[front] + nums[back];
                if (sum < 0) {
                    front++;
                } else if (sum > 0) {
                    back--;
                } else {
                    // found
                    vector<int> triplet = {nums[i], nums[front], nums[back]};
                    res.push_back(triplet);
                    
                    // skip duplicate numbers
                                    // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && nums[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && nums[back] == triplet[2]) back--;

                }
                
            }
            while (i+1 < nums.size() && nums[i]==nums[i+1]) i++;
        }
        // std::sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());


        return res;
    }
};
