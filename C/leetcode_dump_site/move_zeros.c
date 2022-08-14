void moveZeroes(int* nums, int numsSize){
    int rep[numsSize];
    int i;
    for (i = 0; i < numsSize; i++) {
		rep[i] = 0;
	}

	int pos = 0;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] != 0) {
			rep[pos] = nums[i];
			pos++;
		}
	}

	for (i = 0; i < numsSize; i++) {
		nums[i] = rep[i];
	}
}
