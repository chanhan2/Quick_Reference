int hammingWeight(uint32_t n) {
    uint32_t tmp = n;
    int count = 0;
    while (tmp > 0) {
        count = (tmp % 2 == 1) ? count + 1 : count;
        tmp /= 2;
    }
    return count;
}
