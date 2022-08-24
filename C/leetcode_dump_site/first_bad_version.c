// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int l = 1;
    int r = n;
    while (r - l > 1) {
        int m = l + ((r - l) / 2);
        if (isBadVersion(m)) r = m;
        else l = m;
    }
    return (isBadVersion(l)) ? l : r;
}
