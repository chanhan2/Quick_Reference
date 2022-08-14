uint32_t bitToVal(int *bits, int len) {
    uint32_t val = 0;
    uint32_t base = 1;  // starting value as 2^0 = 1
    int i;
    for (i = len - 1; i >= 0; i--, base *= 2) {
        val += bits[i] * base;
    }
    return val;
}

uint32_t reverseBits(uint32_t n) {
    uint32_t tmp = n;
    int bits[32];
    int i;
    for (i = 0; i < 32; i++) bits[i] = 0;
    for (i = 0; tmp > 0; i++) {
        bits[i] = tmp % 2;
        tmp /= 2;
    }
    return bitToVal(bits, 32);
}
