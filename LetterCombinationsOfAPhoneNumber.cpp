#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <assert.h>
#include <locale>
#include <sstream>
using namespace std;
/*
TODO:  
1 times, 1h AC. Be Faster!

*/

class Solution {
private:
    vector<string> letterOf;
public:
    vector<string> letterCombinations(string digits) {
        letterOf.push_back("");//0
        letterOf.push_back("");
        letterOf.push_back("abc");
        letterOf.push_back("def");
        letterOf.push_back("ghi");
        letterOf.push_back("jkl");
        letterOf.push_back("mno");
        letterOf.push_back("pqrs");
        letterOf.push_back("tuv");
        letterOf.push_back("wxyz"); // 9

        vector<string> resultVec;
        for (int i = 0; i < digits.length(); i++) {
            int digit = digits[i] - '0';
            // cout << "digit:" << digit << endl;
            if (resultVec.size() == 0) {
                for (string::iterator letter = letterOf[digit].begin(); letter != letterOf[digit].end(); ++letter)
                {
                    stringstream ss;
                    string s;
                    ss << (*letter);
                    ss >> s;
                    // cout<< "add letter: "<< s << endl;
                    resultVec.push_back(s);
                }
            } else {
                vector<string> tmpResultVec;
                for (vector<string>::iterator eachRes = resultVec.begin(); eachRes != resultVec.end(); ++eachRes)
                {

                        // cout<< "eachRes: "<< *eachRes << endl;
                     string letterOfButton = letterOf[digit];
                        // cout<< "letterOfButton: "<< letterOfButton << endl;

                    for (string::iterator letter = letterOfButton.begin(); letter != letterOfButton.end(); ++letter)
                    {

                        string newResult = *eachRes + *letter;
                        tmpResultVec.push_back(newResult);
                    }
                }
                resultVec.clear();
                resultVec = tmpResultVec;
            }
        }
        return resultVec;
    }
};

void printVec(vector<string> v) {
  for (std::vector<string>::iterator i = v.begin(); i != v.end(); ++i)
  {
    cout<< *i << " ";
  }cout << endl;
}
int main(int argc, char const *argv[])
{
    Solution s;
    printVec( s.letterCombinations("23")) ;
    printVec( s.letterCombinations("")) ;
    printVec( s.letterCombinations("0")) ;
    printVec( s.letterCombinations("1")) ;
    
    return 0;
}