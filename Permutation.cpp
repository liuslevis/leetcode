// Retry!
// 36 min
// 2 RTE 3WA 1AC
// Notice: 1. speed up

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <locale>
using namespace std;
class Solution {
private:
    vector<vector<int> > generate(vector<int> nums, int k) {
        vector<vector<int> > res = vector<vector<int> >(1+nums.size(), nums);
        for(int i = 0; i < nums.size() + 1; i++) {
            res[i].insert(res[i].begin() + i, k);
        }
        return res;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        
        if (nums.size()==0) return res;
        
        int num = nums.back();
        nums.pop_back();
        res.push_back({num} );
        
        while(nums.size() > 0) {

            int ins = nums.back();
            nums.pop_back();
            vector<vector<int> > newRes;
            for (int i = 0; i < res.size(); ++i) {
                vector<vector<int> > sub = generate(res[i], ins);
                newRes.insert(newRes.end(), sub.begin(), sub.end());
            }
            
            res = newRes;
        }
        return res;
    }
};

void printi(std::vector<int> v) {
    for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cout<< *i << " ";
    }
    cout<<endl;
}
void run() {
     Solution s;
     std::vector<int> v = {0,1};
     vector<int> &rv = v;
     s.permute(rv);
}

int main(int argc, char const *argv[])
{
    run();
    return 0;
}