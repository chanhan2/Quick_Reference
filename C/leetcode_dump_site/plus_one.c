/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int result[digitsSize + 1];
    int i;
    for (i = 0; i < digitsSize; i++) result[i] = -1;
    int carry = 0;
    for (i = digitsSize - 1; i >= 0; i--) {
        int toAdd = 1;
        if (i != digitsSize - 1) toAdd = 0;
        int val = (digits[i] + toAdd + carry) % 10;
        carry = (digits[i] + toAdd + carry) / 10;
        result[i + 1] = val;
    }
    if (carry > 0) result[0] = carry;

    int pos = (result[0] == 0) ? 1 : 0;
    *returnSize = ((result[0] == -1) ? digitsSize : digitsSize + 1);
    int *return_arr = (int *)malloc(sizeof(int) * *returnSize);
    for (i = (result[0] == -1) ? 1 : 0; i < digitsSize + 1; i++) {
        return_arr[pos] = result[i];
        pos++;
    }
    return return_arr;
}
