// Retry!
// 55 min
// 10+ CE 1 WA 1AC
// Notice: 1. backtrace problem faster!
//         2. c++ string not familiar

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <locale>
using namespace std;

void printv(vector<string> v) {
  for(auto i : v) {
    cout<<i<<" ";
  }cout<<endl;
}
class Solution {
private:
    int countChar(string s, char c) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) if (s[i] == c) count++;

        return count;
    }    
    bool canAddL(string s, int n) {
        int cntL = countChar(s,'(');
        int cntR = countChar(s,')');
        
        if (cntL < n) return true;
        
        return false;

    }
    
    bool canAddR(string s, int n) {
        int cntL = countChar(s,'(');
        int cntR = countChar(s,')');

        if (cntL > cntR) return true;
        
        return false;
    }
public:
    vector<string> generateParenthesis(int n) {
        if (n==0) return {""};
        if (n==1) return {"()"};
        string L = "(";
        string R = ")";
        
        
        int m = n * 2; // remain parenthesis
        deque<string> que;
        que.push_back(L);
        m--;
        
        vector<string> result;


        while(!que.empty()) {
            string elem = que.front();
            que.pop_front();
            
            if (canAddL(elem, n)) {
                que.push_back(elem + L);
            }
            if (canAddR(elem, n)) {
                que.push_back(elem + R);
            } else {
                if (elem.length() == 2*n)
                    result.push_back(elem);
            }
        }
        
        std::sort(result.begin(), result.end());
        return result;
    }
};

void test() {
  Solution s = Solution();
  printv(s.generateParenthesis(0));
  printv(s.generateParenthesis(1));
  printv(s.generateParenthesis(2));
  printv(s.generateParenthesis(3));

}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}