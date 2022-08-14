int strStr(char * haystack, char * needle){
	int i;
	for (i = 0; haystack[i] != '\0'; i++) {
		int context = 1;
		int j;
		for (j = 0; needle[j] != '\0'; j++) {
			if (haystack[i + j] != needle[j]) {
				context = 0;
				break;
			}
		}
		if (context) return i;
	}
	return -1;
}
