// 30min 10+WA 
// Notice: Boundary of Array!

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        triangle[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                // triangle[i][j] = triangle[i][j] + min(triangle[i-1][j], triangle[i-1][j-1])
                int a = INT_MAX/2;
                int b = INT_MAX/2;
                
                if (j>=0 && j < triangle[i-1].size())
                    a = triangle[i-1][j];
                if (j-1 >= 0 && j-1 < triangle[i-1].size())
                    b = triangle[i-1][j-1];

                triangle[i][j] = triangle[i][j] + min(a,b);
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};

