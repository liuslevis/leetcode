# Retry!
# 16 min
# 5 WA 2TLE 5RTE, 1AC
# Notice: 1.  speed up

class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def permute(self, nums):
        def pfunc(res, m):
            newRes = []
            for i in range(0, len(res)+1):
                newRes.append(res[0:i] + [m] + res[i:])
            return newRes
                
                
        res = []
        if (len(nums)==0):
            return res;
        
        m = nums.pop(len(nums)-1)
        
        
        res.append([m])
        
        while(len(nums) > 0):
            newRes = []
            m = nums.pop(len(nums)-1)
            for r in res:
                newRes+=pfunc(r, m)
            res = newRes
            
        return res