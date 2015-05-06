#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <assert.h>
using namespace std;
/*
3 times AC: Problem:Recursive definition lead to endless loop to cound isHappy. Solution: use hash to record.
*/

class Solution {
private:
    unordered_map<int, bool> map;
    void queried(int n, bool isHappy) {
        map[n] = isHappy;
    }
    // -1 not found, 0 not happy, 1 isHappy
    bool is_queried(int n) {
        if (map.find(n) == map.end()) return false;
        else return true;
    }
    vector<int> getDigits(int n) {
        // cout<<"getDigits:"<< int(n) <<endl;

        vector<int> digits;
        if (n <= 0) return digits;

        while ( n > 0 ) {
            digits.push_back(int(n%10));
            // cout<<"p:"<< int(n%10) <<endl;
            // getchar();
            n = n/10;
        }

        return digits;
    }

    bool _isHappy(int n, int parent) {

        if (n <= 0) {
            return false;
        }
        if (n == 1){
            return true;
        }

        if (true == is_queried(n)) {
            return false;
        } else {
            queried(n, true);
        }



        vector<int> digits = getDigits(n);
        
        if (digits.size()==0) {
            return false;
        }
        
        // more than 2 digits
        int sum = 0;
        for (vector<int>::iterator i = digits.begin(); i != digits.end(); ++i)
        {
            sum += (*i) * (*i);
            // cout<<"sum"<<sum<<endl;
        }
        return _isHappy(sum, parent);
    }
public:

    bool isHappy(int n) {
        // cout<<"isHappy("<<n<<")"<<endl;
        return _isHappy(n, n);
    }
};

void test() {
    Solution s;
    assert(false == s.isHappy(0));
    assert(true == s.isHappy(1));
    assert(true == s.isHappy(19));
    assert(false == s.isHappy(2));

}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}