int myLen(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}

bool isPalindrome(char * s){
    int len = myLen(s);
    char word[len + 1];
    int i;
    int pos = 0;
    for (i = 0; i < len + 1; i++) {
        word[i] = '\0';
        if (65 <= s[i] && s[i] <= 90 || 97 <= s[i] && s[i] <= 122 || 48 <= s[i] && s[i] <= 57) {
            word[pos] = (65 <= s[i] && s[i] <= 90) ? s[i] + 32 : s[i];
            pos++;
        }
    }

    len = myLen(word);
    for (i = 0; i < len / 2; i++) {
        if (word[i] != word[len - 1- i]) return false;
    }
    return true;
}
