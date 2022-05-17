// Imported libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * Source to the purposed solution to return the number of digits of a given
 * integer:  https://stackoverflow.com/a/3068420
 */

void free_partition_str_lst(char** lst, int idx) {
    if (!lst) return;

    int i;
    for (i = 0; i <= idx; i++) free(lst[i]);
    free(lst);
}

char* allocate_str(int n) {
    if (n <= 0) return NULL;

    char* str;
    if (!(str = (char*)malloc(n * sizeof(char) + 1))) {
        printf("Failed to allocate memory");
        return NULL;
    }
    return str;
}

char* reallocate_str(char *word, int n) {
    if (n <= 0 || word == NULL) return word;

    int current_size = strlen(word);
    char* str;
    if (!(str = (char*)malloc((current_size + n) * sizeof(char) + 1))) {
        printf("Failed to allocate memory");
        return NULL;
    }
    str = strcpy(str, word);
    free(word);
    return str;
}

char** allocate_str_lst(int n) {
    if (n <= 0) return NULL;

    char** lst;
    if (!(lst = (char**)malloc(n * sizeof(char*)))) {
        printf("Failed to allocate memory");
        return NULL;
    }
    return lst;
}

char** fizzbuzz(int n) {
    char** lst;
    if (!(lst = allocate_str_lst(n + 1))) return NULL;

    int i;
    for (i = 0; i <= n; i++) lst[i] = NULL;

    for (i = 0; i <= n; i++) {
        if (i % 3 == 0) {
            if (!(lst[i] = allocate_str(strlen("fizz")))) {
                free_partition_str_lst(lst, i);
                return NULL;
            }
            lst[i] = strcpy(lst[i], "fizz");
        }
        if (i % 5 == 0) {
            if (lst[i] == NULL) {
                if (!(lst[i] = allocate_str(strlen("buzz")))) {
                    free_partition_str_lst(lst, i);
                    return NULL;
                }
                lst[i] = strcpy(lst[i], "buzz");
            } else {
                if (!(lst[i] = reallocate_str(lst[i], strlen("buzz")))) {
                    free_partition_str_lst(lst, i);
                    return NULL;
                }
                lst[i] = strcat(lst[i], "buzz");
            }
        }
        if (lst[i] == NULL) {
            int nDigits = floor(log10(abs(i))) + 1;
            char snum[nDigits + 1];
            if (sprintf(snum, "%d", i) < 0) {    // Could not convert to string
                free_partition_str_lst(lst, i);  // due to low memory space
                return NULL;
            }
            if (!(lst[i] = allocate_str(nDigits))) {
                free_partition_str_lst(lst, i);
                return NULL;
            }
            lst[i] = strcpy(lst[i], snum);
        }
    }
    return lst;
}

int main (int argc, char** argv){
    int n = 20;
    char** lst;
    if (!(lst = fizzbuzz(n))) {
        printf("Failed to build fizzbuzz list...\nGo buying more RAM.");
        return 0;
    }

    char* output_outline;  // Unnecessary to create a string to represent the
                           // the output printed format. Could had just defined
                           // it statically with a variable to define the array
                           // char array length. But did it just cause strcat
                           // returns a char pointer, so might as well just
                           // retrieve the output.

    // The "12" was the inclusion of the rest of the characters used to define
    // the output format when printing the list of fizzbuzz values from 0 to n.
    if (!(output_outline = allocate_str(12))) {
        free_partition_str_lst(lst, n);
        printf("Failed to build/setup output...\nGo buying more RAM\n");
        return 0;
    }
    int nDigits = floor(log10(abs(n))) + 1;
    if (sprintf(output_outline, "#%%%dd: ", nDigits) < 0) {
        free_partition_str_lst(lst, n);
        printf("Failed to build/setup output...\nGo buying more RAM\n");
        return 0;
    }
    output_outline = strcat(output_outline, "%s\n");

    int i;
    for (i = 0; i <= n; i++) {
        printf(output_outline, i, lst[i]);
        free(lst[i]);
    }
    free(lst);
    free(output_outline);

    return 0;
}
