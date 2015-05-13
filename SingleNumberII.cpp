// 1 AC,  O(N) time & space
// TODO: bitmap to get O(1) space
class Solution {
private:
    //           key   times
    unordered_map<int, int> map;
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            // found
            if (map.find(num) != map.end()) {
                int times = map[num] + 1;
                map[num] = times;
            } else {// not found
                map[num]=1;
            }
        }
        for(unordered_map<int, int>::const_iterator it = map.begin(); it != map.end(); it++)
        {
            int key = it->first;
            int value = it->second;
            if (value == 1) {
                return key;
            }
        }
        return -1;
    }
};