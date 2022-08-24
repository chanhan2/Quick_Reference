

bool isPowerOfThree(int n){
    if (n <= 0) return false;

    return pow(3, ceil(log(n)/log(3))) == n;
}
