// TLE
nclude <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

struct Key
{
    int first;
    int second;
    int third;
    
    Key(int i, int j, int k) {
        first = i;
        second = j;
        third = k;
    }
    
    bool operator==(const Key &other) const
    { return (first == other.first
              && second == other.second
              && third == other.third);
    }
};


namespace std {
    
    template <>
    struct hash<Key>
    {
        std::size_t operator()(const Key& k) const
        {
            using std::size_t;
            using std::hash;
            using std::string;
            
            // Compute individual hash values for first,
            // second and third and combine them using XOR
            // and bit shifting:
            
            string s = "("+to_string(k.first)+","+to_string(k.second)+","+to_string(k.third)+")";
            
            return (hash<string>()(s));
        }
    };
    
}

// test case
// assert input no duplicates
class Solution {
private:

    bool hasChecked(unordered_map< Key , bool > result_hash, int i, int j, int k) {
        Key tri(i, j, k);
        if (result_hash.find(tri)!=result_hash.end()) {
            return true;
        }
        result_hash[tri] = true;
        return false;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map< Key , bool > result_hash;
        vector<vector<int>> res;
        unordered_map<int, int> indexOf;//<index, number>

        
        // build index
        for (int i = 0; i < nums.size(); i++)
            indexOf[nums[i]] = i;
        
        // i, j, k: index of num
        for (int i = 0; i < nums.size(); i++) {
            // 2sum, given target, nums, indexOf
            for (int j = i + 1; j < nums.size(); j++) {
                int target2 = 0 - nums[i] - nums[j];
                
                // check if had answer
                if (hasChecked(result_hash, i, j, target2)) {
                    continue;
                }
                

                // calc 2sum
                else if (indexOf.find(target2) != indexOf.end()
                    && indexOf[target2] != i
                    && indexOf[target2] != j) {
                    
                    // found
                    Key tri(target2, nums[i], nums[j]);
                    result_hash[tri]=true;
                    
                    vector<int> v = {target2, nums[i], nums[j]};
                    sort(v.begin(), v.end());
                    res.push_back(v);

                }
            }
        }
        
         sort(res.begin(), res.end(), [] (vector<int> lhs, vector<int> rhs) -> bool {
             if (lhs.size()!=rhs.size() && lhs.size()!= 3) return lhs.size() < rhs.size();
        
             if (lhs[0] != rhs[0]) {
                 return lhs[0] < rhs[0];
             } else if (lhs[1] != rhs[1] ) {
                 return lhs[1] < rhs[1];
             } else {
                 return lhs[2] < rhs[2];
             }
        
         });
        
        res.erase( unique( res.begin(), res.end() ), res.end() );

        return res;
        
    }
};

void printvv(vector<vector<int>> v) {
    for (auto i : v) {
        for (auto j : i) {
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("\n");
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {-6,-8,-9,4,-14,6,-10,7,12,13,4,9,7,14,-12,7,0,14,-1,-3,2,2,-3,11,-6,-10,-13,-13,1,-9,2,2,-2,8,-9,0,-9,-12,14,10,8,3,4,0,-6,7,14,9,6,-2,13,-15,8,-5,3,-13,-8,5,-11,0,11,6,-13,-14,-9,-15,-7,-11,10,-7,14,4,3,3,11,13,-13,11,-1,0,-6,-10,0,9,0,10,11,0,0,-14,-15,-12,-1,10,12,-2,2,-10,2,-2,-10,2,-13,1,12,5,-1,-15,1,5,-8,3,10,8};
    Solution s;
        printvv(s.threeSum(nums));
    return 0;
}

