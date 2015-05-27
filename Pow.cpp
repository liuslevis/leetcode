double myPow(double x, int n) {
        if (n == 0) return 1;

    int originalN = n;
    n = abs(n);
    
        if (n % 2 == 1 ) {
            double tmp = myPow(x, (n-1)/2);
            return originalN < 0  ? (1/(x*tmp*tmp)) : x *  tmp * tmp;
        } else {
            double tmp = myPow(x, n/2);
            return originalN < 0 ? (1/(tmp*tmp)) : tmp * tmp;
        }   
}