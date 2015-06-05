// Redo!
// 30 min
// Recursive method TLE (but python okay)
// Iterative method 1WA 1AC
// Notice: DP speed up.
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
    int f(vector<vector<int>> grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int j = 1; j < n; j++) 
            grid[0][j] += grid[0][j-1];
            
        for (int i = 1; i < m; i++) 
            grid[i][0] += grid[i-1][0];
        
        if (m==1) return grid[0][n-1];
        if (n==1) return grid[m-1][0];
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
            
        
        
    }
public:

    int minPathSum(vector<vector<int>>& grid) {
        
        if (grid.size() < 0) return 0;
        
        return f(grid);
    }
};
void run() {
    vector<vector<int> > v = {{0}};
    vector<vector<int> > &rv = v;
    Solution s;
    s.minPathSum(rv);
}

int main(int argc, char const *argv[])
{
    run();
    return 0;
}