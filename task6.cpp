#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> readMatrix(const string& fileName) {
    ifstream fin(fileName);
    if (!fin.is_open()) {
        cerr << "Не вдалося відкрити файл для читання!" << endl;
        exit(1);
    }

    int rows, cols;
    fin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fin >> matrix[i][j];
        }
    }

    fin.close();
    return matrix;
}


int findColumnWithZero(const vector<vector<int>>& matrix) {
    for (int j = 0; j < matrix[0].size(); ++j) {
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][j] == 0) {
                return j + 1; 
            }
        }
    }
    return -1;
}


int calculateRowCharacteristic(const vector<int>& row) {
    int sum = 0;
    for (int elem : row) {
        if (elem < 0 && elem % 2 == 0) {
            sum += elem;
        }
    }
    return sum;
}


void sortRowsByCharacteristic(vector<vector<int>>& matrix) {
    sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b) {
        return calculateRowCharacteristic(a) > calculateRowCharacteristic(b);
        });
}


void writeMatrix(const vector<vector<int>>& matrix, const string& fileName) {
    ofstream fout(fileName);
    if (!fout.is_open()) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        exit(1);
    }

    for (const auto& row : matrix) {
        for (int elem : row) {
            fout << elem << "\t";
        }
        fout << endl;
    }

    fout.close();
}

int main() {
    string inputFileName = "data.txt";
    string outputFileName = "result.txt";

    
    vector<vector<int>> matrix = readMatrix(inputFileName);

   
    cout << "Початкова матриця:" << endl;
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }

    
    int columnWithZero = findColumnWithZero(matrix);
    if (columnWithZero != -1) {
        cout << "Перший стовпець з нульовим елементом: " << columnWithZero << endl;
    }
    else {
        cout << "Стовпці без нульових елементів." << endl;
    }

    
    sortRowsByCharacteristic(matrix);

    
    cout << "Відсортована матриця:" << endl;
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }

    
    writeMatrix(matrix, outputFileName);
    cout << "Результати записані у файл: " << outputFileName << endl;

    return 0;
}
