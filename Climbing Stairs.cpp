// 1 TLE 1AC
// notice: fib-like question, use array to store computation.

int CS(int n, int *arr) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n >= 3){
        if (arr[n] == 0) {
            int CS_N = CS(n-1,arr) + CS(n-2,arr);
            arr[n] = CS_N;
        }
        return arr[n];
    }
}

int climbStairs(int n) {
    int arr[10000];
    return CS(n, arr);
}
