// 5min 2 WA
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        
        res.push_back(1);
        if (rowIndex <= 0) return res;
        
        res.push_back(1);
        if (rowIndex == 1) return res;
        
        rowIndex -= 1;
        
        while(rowIndex-- > 0) {
            vector<int> newRes;
            newRes.push_back(1);
            for (int i = 1; i < res.size(); i++) {
                newRes.push_back(res[i]+res[i-1]);
            }
            newRes.push_back(1);
            res = newRes;
            
        }
        return res;
    }
};
