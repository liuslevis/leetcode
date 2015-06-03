#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <assert.h>
#include <algorithm>

// 30min, 4 WA 1AC
// [1 Pass Count Sort]
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        /* 1 pass */
        int MAX_COLOR = 3;
        int back[MAX_COLOR]; // index 0 1 2 <-> R W B
        for (int i = 0; i < MAX_COLOR; ++i) 
            back[i] = nums.size() - 1;
        

        // back[0]
        int color = 0;

        int front = 0;
        int back_0 = nums.size() - 1;

        for (int color = 0; color < MAX_COLOR; ++color)
        {
            while(front < back[color]) {
                while(front < back[color] && nums[back[color]] != color) {
                    back[color]--;
                }
                while(front < back[color] && nums[front] <= color) {
                    front++;
                }
                // swap back front
                cout<<"swap color:"<<color<<" f:"<< front <<" b:"<<back[color] << endl;
                if (nums[front] > nums[back[color]]) {
                    int tmp = nums[back[color]];
                    nums[back[color]] = nums[front];
                    nums[front] = tmp;

                    front++;
                    back[color]--;   
                } else {
                    break; // while
                }
            }        
        }

    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<int> v = {0,2,1};
    vector<int> &nums = v;
    s.sortColors(nums);
    return 0;
}