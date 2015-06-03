#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <assert.h>
#include <algorithm>

// 15min, 3 RTE 1AC
// [Two Pass Count Sort]
// Notice: clear array after init !!
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Not allow!
        // sort(nums.begin(), nums.end());

        /* counting sort */
        int MAX_COLOR = 3;
        int count[MAX_COLOR]; // index 0 1 2 <-> R W B
        for (int i = 0; i < MAX_COLOR; ++i) count[i] = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            int color = nums[i];
            count[color]++;
        }

        int index = 0;

        for (int color = 0; color < MAX_COLOR; ++color)
        {

            for (int j = 0; j < count[color]; ++j)
            {
                nums[index] = color;
                index++;
            }
        }

    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<int> v = {0};
    vector<int> &nums = v;
    s.sortColors(nums);
    return 0;
}