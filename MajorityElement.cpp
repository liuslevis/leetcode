// 2 WA 1AC,  O(N) time  O(N) space using hashmap
class Solution {
private:
    unordered_map<int, int> timesOf;
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() <= 1) return nums[0];
        
        int  majorityNum = nums.size() / 2;
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (timesOf.find(num) != timesOf.end()) {            // found
                int times = timesOf[num] + 1;

                if (times > majorityNum) return num;

                timesOf[num] = times;
                
            } else { // not found
                timesOf[num] = 1;
            }
        }
       
        return -1;
    }
};

// Better O(N) time O(1) space, Moor's Voting Algorithm
// http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
// Precondition: the majority element must exist
int majorityElement(int* nums, int numsSize) {
    int majNum = nums[0];
    int cnt = 1;
    for (int i = 1; i < numsSize; i++) {
        if (majNum == nums[i]) {
            cnt++;
        } else if (0 == cnt) {
            majNum = nums[i];
            cnt = 1;
        } else {
            cnt --;
        }
    }
    return majNum;
}