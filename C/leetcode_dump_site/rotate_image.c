void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int tmp[matrixSize][matrixSize];
    int i;
    int i2;
    for (i = matrixSize - 1, i2 = 0; i >= 0; i--, i2++) {
        int j;
        for (j = 0; j < matrixSize; j++) {
            tmp[j][i2] = matrix[i][j];
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrix[i][j] = tmp[i][j];
        }
    }
}
