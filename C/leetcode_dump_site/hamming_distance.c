int hammingDistance(int x, int y){
    int x_tmp = x;
	int y_tmp = y;

	int count = 0;
	while (x_tmp > 0 || y_tmp > 0) {
		count = (x_tmp % 2 != y_tmp % 2) ? count + 1 : count;
		x_tmp /= 2;
		y_tmp /= 2;
	}
	return count;
}
