// Redo
// 1 h 10 WA 1 AC
// Demand: Implement atoi to convert a string to an integer.
// Notice: Consider all possible case!

int myAtoi(char* str) {
    long long num = 0;
    int neg = 1;
    int index = 0;
    
    // handle ' '
    while(' '==str[index]) index++;
    
    // handle +/- symbol
    int symbolCount = 0;
    while('+'==str[index] || '-'==str[index]) {
        if ('-' == str[index]) {
            neg *= -1;
            index++;
            symbolCount++;
        }
        if ('+' == str[index]) {
            index++;
            symbolCount++;
        }
        if (symbolCount > 1) return 0;
    }
    
    // handle '++c'
    if (!isdigit(str[index])) return 0;
    
    // handle '000'
    while(str[index] && '0'==str[index]) index++;
    
    int digitCount = 0;
    while(str[index]) {
        if (!isdigit(str[index])) break;
        
        int digit = str[index] - '0';
        num = num*10 + (long long)digit;
        
        if (num * neg > (long long)INT_MAX) return INT_MAX;
        if (num * neg < (long long)INT_MIN) return INT_MIN;

        index++;
        digitCount++;
    }
    
    
    return num * neg;
}