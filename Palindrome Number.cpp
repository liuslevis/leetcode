// Redo
// 17min, 10 WA
// Notice: pass testcase by hand
class Solution {
public:
    int getdigit(int bit, int x) {
        for (int i = 0; i < bit; i++) {
            if (x <= 0) return -1;
            x /= 10;
        }
        return x%10;
    }
    bool isPalindrome(int x) {
        if (x == 0) return true;
        
        long lx = x;
        if (lx>=INT_MAX || lx <= INT_MIN) return false;


        bool isNeg = false;
        if(x < 0) {
            isNeg = true;
            x = -x;
            return false;
        }
        
        
        //1 
        //11
        //101
        //1001
        //>INT_MAX
        
        int digit = 0;
        int tmp = x;
        while(tmp > 0) {
            digit++;
            tmp/=10;
        }
        
        if (digit <= 1) return true;
        
        int l=0, r=digit-1;
        while(l < r) {
            if (getdigit(l, x)!=getdigit(r,x)) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
