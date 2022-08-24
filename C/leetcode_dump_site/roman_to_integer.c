

int romanIdx(char *r, char c) {
    int i;
    for (i = 0; i < 7; i++)
        if (r[i] == c) return i;
    return -1;
}

int romanToInt(char * s){
    if (!s) return 0;

    char r[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int n[] = {1, 5, 10, 50, 100, 500, 1000};

    int result = 0;
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
            result += (s[i + 1] == 'V') ? 4 : 9;
            i++;
        } else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
            result += (s[i + 1] == 'L') ? 40 : 90;
            i++;
        } else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
            result += (s[i + 1] == 'D') ? 400 : 900;
            i++;
        } else {
            int idx;
            if ((idx = romanIdx(r, s[i])) != -1) result += n[idx];
        }
    }
    return result;
}
