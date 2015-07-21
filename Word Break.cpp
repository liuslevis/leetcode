// Redo
// exploit then 10min 1 WA 5 CE
// Notice: 优先令 f[i]=题目所求
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& dict) {
        vector<bool> f(s.size() + 1, 0);
        for (int i = 0; i < s.size(); i++) 
            f[i] = false;
        f[0] = true;
        
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (f[j]==true && dict.find(s.substr(j,i-j))!=dict.end() ) {
                    f[i] = true;
                }
                    
            }
        }
        return f[s.size()];
    }
};
