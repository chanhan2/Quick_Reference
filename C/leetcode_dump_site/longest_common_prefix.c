int myMin(int a, int b) {
    return (a < b) ? a : b;
}

int myLength(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

char * longestCommonPrefix(char ** strs, int strsSize){
    int shorest_word_len = myLength(strs[0]);  // arbitrary
    int i;
    for (i = 0; i < strsSize; i++) {
        shorest_word_len = myMin(shorest_word_len, myLength(strs[i]));
    }

    char *phrase = (char *)malloc(sizeof(char) * (shorest_word_len + 1));
    phrase[shorest_word_len] = '\0';

    for (i = 0; i < shorest_word_len; i++) {
        int j;
        for (j = 0; j < strsSize - 1; j++) {
            if (strs[j][i] != strs[j + 1][i]) {
                phrase[i] = '\0';
                return phrase;
            }
        }
        phrase[i] = strs[j][i];
    }
    return phrase;
}
