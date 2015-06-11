// 2 min + 1 day (misunderstood, not Cask Effect)
// 1AC
// Notice: the level of water is min(height[first], height[last])!
class Solution {
private:

public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0;
        int j = height.size()-1;
        
        while(i > j) {
            water = max(water, min(height[j], height[i]) * (j-i));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return water;
    }
};