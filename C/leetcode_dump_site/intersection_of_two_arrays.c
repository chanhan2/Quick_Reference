int cmp(const void *a, const void *b) {
	int a_val = *((int *)a);
	int b_val = *((int *)b);

	if (a_val == b_val) return 0;
	if (a_val < b_val) return -1;
	return 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int *l1 = nums1;
	int len1 = nums1Size;
	int *l2 = nums2;
	int len2 = nums2Size;
	if (nums1Size <= nums2Size) {
		l1 = nums2;
		len1 = nums2Size;
		l2 = nums1;
		len2 = nums1Size;
	}

	qsort(l1, len1, sizeof(int), cmp);
	qsort(l2, len2, sizeof(int), cmp);

	int *result = (int *)malloc(sizeof(int) * len2);

	int i;
	int pos2;
	for (i = 0, *returnSize = 0, pos2 = 0; i < len1; i++) {
        while (pos2 < len2 && l1[i] > l2[pos2]) pos2++;
        if (pos2 >= len2) break;
		if (l1[i] == l2[pos2]) {
			result[*returnSize] = l2[pos2];
			pos2++;
            *returnSize = *returnSize + 1;
		}
	}

	return result;
}
