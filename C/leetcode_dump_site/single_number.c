int myMax(int a, int b) {
    return (a < b) ? b : a;
}

int myAbs(int v) {
    return (v < 0) ? v * -1 : v;
}

int singleNumber(int* nums, int numsSize){
    int max = myAbs(nums[0]);
    int i;
    for (i = 0; i < numsSize; i++) {
        max = myMax(max, myAbs(nums[i]));
    }
    if (max == 1) max = 3;

    int hash[(max * 2) + 1];
    for (i = 0; i < (max * 2) + 1; i++) {
        hash[i] = 2147483640;  // arbitrary
    }

    for (i = 0; i < numsSize; i++) {
        if (hash[(max + nums[i]) % (max + max)] == 2147483640) hash[(max + nums[i]) % (max + max)] = nums[i];
        else hash[(max + nums[i]) % (max + max)] = 2147483641;  // arbitrary
    }

    int found = -1;
    for (i = 0; i < numsSize; i++) {
        if (hash[(max + nums[i]) % (max + max)] != 2147483640 && hash[(max + nums[i]) % (max + max)] != 2147483641) found = nums[i];
    }
    return found;
}
