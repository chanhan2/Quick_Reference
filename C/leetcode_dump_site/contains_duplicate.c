int cmp(const void *a, const void *b) {
    int a_val = *((int *)a);
    int b_val = *((int *)b);

    if (a_val == b_val) return 0;
    if (a_val < b_val) return -1;
    return 1;
}

bool containsDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int i;
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) return true;
    }
    return false;
}
