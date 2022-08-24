

int missingNumber(int* nums, int numsSize){
	int sum = numsSize;
    for (numsSize -= 1; numsSize >= 0; numsSize--) sum += numsSize - nums[numsSize];
	return sum;
}
