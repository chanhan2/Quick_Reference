

double stringToInt(char *str, double place_tracker) {
    if (str[0] == '\0') return 0;
    return (str[0] - 48) * place_tracker + stringToInt(&str[1], place_tracker * 10);
}

int  reverse(int x){
    if (-2147483648 > x || x >= 2147483648) return 0;
    int tmp = x;
    int len = 0;
    while (tmp != 0) {
        tmp /= 10;
        len++;
    }

    char word[len + 1];
    word[len] = '\0';
    tmp = x;
    int i;
    for (i = len - 1; i >= 0; i--) {
        word[i] = (tmp % 10) + 48;
        tmp /= 10;
    }
    double result = stringToInt(word, 1);
    return (int)((-2147483648 > result || result >= 2147483648) ? 0 : result);
}
