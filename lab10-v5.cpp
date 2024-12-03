#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;


void inputMatrix(vector<vector<int>>& matrix, int rows, int cols) {
    cout << "Введіть елементи масиву (" << rows << "x" << cols << "):" << endl;
    matrix.resize(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            while (true) {
                cout << "Елемент [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> matrix[i][j];
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Некоректне значення, спробуйте ще раз." << endl;
                } else {
                    break;
                }
            }
        }
    }
}


vector<int> calculateRowSums(const vector<vector<int>>& matrix) {
    vector<int> rowSums;
    for (const auto& row : matrix) {
        int sum = 0;
        for (int element : row) {
            if (element >= 0) {
                sum += element;
            }
        }
        rowSums.push_back(sum);
    }
    return rowSums;
}


void printNonZeroElements(const vector<int>& arr) {
    cout << "Одновимірний масив сум невід'ємних елементів: ";
    int count = 0;
    for (int element : arr) {
        if (element == 0) {
            break;
        }
        cout << element << " ";
        count++;
    }
    cout << endl;
    cout << "Кількість елементів до першого нульового: " << count << endl;
}

int main() {
    try {
        int rows, cols;

      
        cout << "Введіть кількість рядків: ";
        cin >> rows;
        if (rows <= 0) throw invalid_argument("Кількість рядків повинна бути додатною.");
        
        cout << "Введіть кількість стовпців: ";
        cin >> cols;
        if (cols <= 0) throw invalid_argument("Кількість стовпців повинна бути додатною.");

        vector<vector<int>> matrix;
        inputMatrix(matrix, rows, cols);

        vector<int> rowSums = calculateRowSums(matrix);

        printNonZeroElements(rowSums);
    } catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
        return 1;
    }

    return 0;
}
