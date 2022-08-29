

void moveZeroes(int* nums, int numsSize){
    // Below is my grade 10 to grade 12 approach to this
    // problem, as I've done this exact problem before
    // for my assignments/projects. Though it was a minor
    // problem which was needed to be solved to solve the
    // overall whole problem.
    int track;
    int i;
    for (i = 0, track = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[track++] = nums[i];
        }
    }

    while (track < numsSize) {
        nums[track++] = 0;
    }
}
