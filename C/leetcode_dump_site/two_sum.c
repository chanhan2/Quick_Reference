/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    // Note:   If using the elements in the array *nums as keys and setting
    //         the corresponding values as their correspoding index position
    //         in the array *nums, then the worst time complexity O(n) can be
    //         achieved to solve this problem.
    //
    //         Example: table[] = {-q, -q, -q, ...}  <--- fix size M
    //                  where -q = (m - 1), m and M is the smallest and largest
    //                  values in the array *nums respectively.
    //
    //                  Algo:
    //                      table[nums[i]] = i;  // 0 <= i < numsSize
    //                      if (table[target - nums[i]]) = j > -q then return [i, j]
    //
    //                      return [], if failed to find such pairing
    //
    //         Did not implement the above, as why would I want to do that???
    //         I ain't smart nor good at anything I do.
    //
    int *ret = (int *)malloc(sizeof(int) * 2);
    int found = 0;
    int i;
    for (i = 0; i < numsSize; i++) {
        int j;
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                ret[0] = i;
                ret[1] = j;
                found = 1;
                break;
            }
        }
    }
    if (found) *returnSize = 2;
    else {
        *returnSize = 0;
        free(ret);
    }
    return ret;
}
