// O(m+n): 8 min 2 CE 1 AC. 
// O(1) ?
// Notice:  1. Better solution: use first column to store info instead of set(m+n).

// O(m+n) complexity
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size()==0) return;
        
        int row = matrix.size();
        int col = row==0 ? 0 : matrix[0].size();
        
        set<int> markRow;
        set<int> markCol;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j]==0) {
                    markRow.insert(i);
                    markCol.insert(j);
                }
            }
        }
        
        for (set<int>::iterator it = markRow.begin(); it != markRow.end(); ++it) {
            for (int j = 0; j < col; j++) {
                matrix[*it][j] = 0;
            }
        }
        
        for (set<int>::iterator it = markCol.begin(); it != markCol.end(); ++it) {
            for (int i = 0; i < row; i++) {
                matrix[i][*it] = 0;
            }
        }
    }
};