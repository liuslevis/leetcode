// REDO
// 47 in 10+WA RTE. Dont understand zigzag definition.
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        
            string li[1000];
            for (int i = 0; i < s.size(); ++i) {
                int index =  i%(numRows * 2 - 2);
                if ( index < numRows) 
                { // 0~row-1
                    li[index].push_back(s[i]);  
                    
                } else 
                {// row~2*row-1, reverese
                    li[numRows - 2 - (index - numRows)].push_back(s[i]);
                
                }
                
            }
            
            //return l1+l2+l3+...;
            string res;
            for (auto line : li) {
                for (auto ch : line) {
                    res.push_back(ch);
                }
            }
            return res;
       
    }
};
