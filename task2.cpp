#include <iostream>
#include <algorithm>

const int rows = 5, cols = 5;

void sortColumnsByMax(int matrix[rows][cols]) {
    int maxInCols[cols];

    for (int j = 0; j < cols; ++j) {
        int maxVal = matrix[0][j];
        for (int i = 1; i < rows; ++i) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
        maxInCols[j] = maxVal;
    }

    for (int j = 0; j < cols - 1; ++j) {
        for (int k = 0; k < cols - j - 1; ++k) {
            if (maxInCols[k] < maxInCols[k + 1]) {
                std::swap(maxInCols[k], maxInCols[k + 1]);
                for (int i = 0; i < rows; ++i) {
                    std::swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

int main() {
    int matrix[rows][cols];

   
    std::cout << "¬вед≥ть елементи матриц≥ (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    sortColumnsByMax(matrix);

    std::cout << "¬≥дсортована матриц€:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
