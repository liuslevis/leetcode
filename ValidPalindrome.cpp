#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <assert.h>
#include <locale>
using namespace std;
/*
TODO:  
1 times, 0.5 AC.

*/
class Solution {
private:
    string alphaNumeric(string s) {
        string res;
        for (int i = 0; i < s.length(); ++i)
        {
            if (( 'a' <= s[i] && s[i] <= 'z') || ( '0' <= s[i] && s[i] <= '9')) {
                res+=(s[i]);
            } else if ( 'A' <= s[i] && s[i] <= 'Z') {
                res+=(tolower(s[i]));
            }
        }
        cout << res <<endl;
        return res;
    }
public:
    bool isPalindrome(string str) {
        str = alphaNumeric(str);
        if (str.length() < 2) return true;
        int p = 0;
        int q = str.length() - 1;
        while(p < q) {
            // cout<< "p:" << p << " q:" << q << endl;
            if (str[p] != str[q]) return false;
            p++;
            q--;
        }
        return true;
    }
};


void test() {
    Solution s;
   assert(true == s.isPalindrome(""));
   assert(true == s.isPalindrome(" "));
   assert(true == s.isPalindrome("a"));
   assert(true == s.isPalindrome("a "));
   assert(true == s.isPalindrome("A.b:a "));
   assert(true == s.isPalindrome("1a.b:a~= 1"));
   assert(false == s.isPalindrome("a.b:"));
   assert(false == s.isPalindrome("ab"));
   assert(false == s.isPalindrome("ab1a"));
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}