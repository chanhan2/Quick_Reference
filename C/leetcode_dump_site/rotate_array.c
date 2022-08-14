void rotate(int* nums, int numsSize, int k) {
    int new_k = k % numsSize;
    int result[numsSize];

    int pos = 0;
    int i;
    for (i = numsSize - new_k; i < numsSize; i++) {
        result[pos] = nums[i];
        pos++;
    }

    for (i = 0; i < numsSize - new_k; i++) {
        result[pos] = nums[i];
        pos++;
    }

    for (i = 0; i < numsSize; i++) {
        nums[i] = result[i];
    }
}
