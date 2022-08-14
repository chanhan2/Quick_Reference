int firstUniqChar(char * s){
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        int j;
        if (s[i] == '_') continue;
		int duplicate = 0;
        for (j = i + 1; s[j] != '\0'; j++) {
            if (s[i] == s[j]) {
                s[j] = '_';
				duplicate = 1;
            }
        }
		if (duplicate) {
			s[i] = '_';
			duplicate = 0;
		}
    }
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] != '_') return i;
	}
    return -1;
}
