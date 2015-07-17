// Redo
// 12 min 10+ WA
ass Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash; //<num, index>
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int n = target - nums[i];
            if (hash.find(n)!=hash.end() && hash[n]!=i ) {
                
                res.push_back(hash[n]+1);
                res.push_back(i+1);
                sort(res.begin(), res.end());
                return res;
            }
        }
        
        
        return res;
    }
};
