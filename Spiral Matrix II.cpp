// 16 min 
// 2 RTE 10 WA 1AC
// Notice: run test case yourself on sheet first
class Solution {
private: 
    bool inBorder(int i, int j, int n) {return i<n && i>=0 && j<n &&j>=0;}
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        // n = 0 1 2 3 ...
        int num = 1;        
        int i = 0, j = -1;
        // -> * n
        for (int k = 0; k < n ; k++) {
            v[i][++j] = num++;
        }
        
            
        for (int times = n-1; times > 0 && inBorder(i,j,n);) {
            // v*times  
            for (int k = 0; k < times && inBorder(i,j,n); k++) {
                v[++i][j] = num++;

            }
            // < * times
            for (int k = 0; k < times && inBorder(i,j,n); k++) {
                v[i][--j] = num++;
            }

            
            times--;
            if (times <= 0) return v;
            
            // ^ * times
            for (int k = 0; k < times && inBorder(i,j,n); k++) {
                v[--i][j] = num++;
            }
            // >
            for (int k = 0; k < times && inBorder(i,j,n); k++) {
                v[i][++j] = num++;
            }
            times--;
            if (times <= 0) return v;
            
        }
        return v;
        
    }
};