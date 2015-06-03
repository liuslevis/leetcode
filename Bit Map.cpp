#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <locale>
using namespace std;

enum { BITSPERWORD = 64, SHIFT = 6, MASK = 0x3F}; // 64 bit
// enum { BITSPERWORD = 32, SHIFT = 5, MASK = 0x1F}; // 32 bit

int n, hi;
int x[200]; // 0 ~ 2^64*200 - 1

void set(int i)  {        x[i>>SHIFT] |=   (1<<(i & MASK)); }
void clr(int i)  {        x[i>>SHIFT] &=  ~(1<<(i & MASK)); }
int  test(int i) { return x[i>>SHIFT] &    (1<<(i & MASK)); }

void showbits(unsigned int x)
{
    int i; 
    for(i=(sizeof(int)*8)-1; i>=0; i--)
        (x&(1<<i))?putchar('1'):putchar('0');

    printf("\n");
}

void printi(int i) {
    cout<< i << endl;
}
void run() {
    set(1);
    showbits(x[0]);
    set(2);
    showbits(x[0]);
    // set(3);
    cout << "3 :" << endl;
    showbits(3) ;
    cout << "1<<3 :" << endl;
    showbits((1<<3)) ;
    showbits(x[0]  | (1<<3));
    // showbits(x[0]);

    printi(test(1));
    printi(test(2));
    printi(test(3));
}

int main(int argc, char const *argv[])
{
    run();
    return 0;
}