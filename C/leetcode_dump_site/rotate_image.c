

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    //  This is the grade 9 and grade 10 method I've used before.
    //  The below method has horrible aggregate time complexity,
    //  as it uses 2 for loops, which is not needed for this
    //  problem.
    int i;
    for (i = 0; i < matrixSize; i++) {
        int j;
        for (j = i + 1; j < matrixSize; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    for (i = 0; i < matrixSize; i++) {
        int j;
        for (j = 0; j < matrixSize / 2; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - 1 - j];
            matrix[i][matrixSize - 1 - j] = tmp;
        }
    }
}
