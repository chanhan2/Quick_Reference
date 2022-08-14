// haskell does it better
void mergeHeler(int *accum, int idx, int *nums1, int m, int pos, int *nums2, int n, int pos2) {
	if (idx >= m + n) return;
	if (m == pos) {
		accum[idx] = nums2[pos2];
		return mergeHeler(accum, idx + 1, nums1, m, pos, nums2, n, pos2 + 1);
	}
	if (n == pos2) {
		accum[idx] = nums1[pos];
		return mergeHeler(accum, idx + 1, nums1, m, pos + 1, nums2, n, pos2);
	}

	if (nums1[pos] < nums2[pos2]) {
		accum[idx] = nums1[pos];
		return mergeHeler(accum, idx + 1, nums1, m, pos + 1, nums2, n, pos2);
	} else {
		accum[idx] = nums2[pos2];
		return mergeHeler(accum, idx + 1, nums1, m, pos, nums2, n, pos2 + 1);
	}
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int result[m + n];
	mergeHeler(result, 0, nums1, m, 0, nums2, n, 0);
	int i;
	for (i = 0; i < m + n; i++) {
		nums1[i] = result[i];
	}
}
