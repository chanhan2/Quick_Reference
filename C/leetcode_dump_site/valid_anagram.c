int myLen(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}

int compare( const void* a, const void* b) {
    char int_a = * ( (char*) a );
    char int_b = * ( (char*) b );

    if ( int_a == int_b ) return 0;
    else if ( int_a < int_b ) return -1;
    else return 1;
}

bool isAnagram(char * s, char * t){
    qsort(s, myLen(s), sizeof(char), compare);
    qsort(t, myLen(t), sizeof(char), compare);

    int i;
    for (i = 0; s[i] != '\0' && t[i] != '\0' && s[i] == t[i]; i++);
    return s[i] == '\0' && t[i] == '\0';
}
