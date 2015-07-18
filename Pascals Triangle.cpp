//5min 1AC
ass Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows < 1) return res;
        
        // init [[1]]
        vector<int> v = {1};
        res.push_back(v);
        numRows--;
        
        while(numRows!=0) {
            vector<int> lastRow = res.back();
            
            vector<int> newRow;
            newRow.push_back(1);
            for (int i = 1; i < lastRow.size(); i++) {
                newRow.push_back(lastRow[i]+lastRow[i-1]);    
            }
            newRow.push_back(1);
            
            res.push_back(newRow);
            numRows--;
        }
        return res;
    }
};
