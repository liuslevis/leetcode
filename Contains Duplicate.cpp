// 2 min 
// 1AC
// notice:
class Solution {
private:
    unordered_map<int, bool> hash;
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.find(nums[i]) != hash.end() ) 
                return true;
            else
                hash[nums[i]]==true;
        }
        return false;
    }
};