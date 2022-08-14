int nextBiggest(int* nums, int numsSize, int current_val, int current_pos) {
    if (current_pos >= numsSize) return -1000;

    int i;
    for (i = current_pos; i < numsSize; i++) {
        if (current_val < nums[i]) return nums[i];
    }
    return -1000;
}

int count_n_sorted(int *nums, int numsSize) {
    int count = 1;
    int i;
    for (i = 0; i < numsSize - 1 && nums[i] < nums[i + 1]; i++) {
        count++;
    }
    return count;
}

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 1) return 1;

    if (numsSize == 2) {
        if (nums[0] == nums[1]) {
            return 1;
        } else {
            return 2;
        }
    }

    int i;
    int count = 0;
    for (i = 1; i < numsSize; i++) {
        nums[i] = nextBiggest(nums, numsSize, nums[i - 1], i - 1);
    }
    return count_n_sorted(nums, numsSize);
}
