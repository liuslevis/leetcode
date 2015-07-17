// 20 min 10+WA
// Notice: test case & run by hand
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return "";
        if (strs.size()< 2) return strs[0];
        
        for (auto str : strs) if (str.size()==0) return "";
        
        int index = -1;
        while (strs[0][index+1] == strs[1][index+1]) {
            index++;
        }
        
        if (index < 0) return "";
        
        for (int i = 2; i < strs.size(); ++i) {
            if (strs[i].size() - 1 < index) index = strs[i].size() - 1;
            
            while(strs[i][index]!=strs[i-1][index]) {
                index--;
                if (index < 0) return "";
            }

        }
        
        
        return strs[0].substr(0, index + 1);
    }
};
