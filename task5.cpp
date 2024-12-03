#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void sumDiagonals(const vector<vector<int>>& matrix, int& mainDiagSum, int& secDiagSum) {
    int n = matrix.size();
    mainDiagSum = 0;
    secDiagSum = 0;
    for (int i = 0; i < n; ++i) {
        mainDiagSum += matrix[i][i];             
        secDiagSum += matrix[i][n - i - 1];     
}


void sortFirstColumn(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> firstColumn(n);
    for (int i = 0; i < n; ++i) {
        firstColumn[i] = matrix[i][0];
    }
    sort(firstColumn.begin(), firstColumn.end());
    for (int i = 0; i < n; ++i) {
        matrix[i][0] = firstColumn[i];
    }
}


void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "������ ����� ��������� �������: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "������ �������� �������:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "��������� �������:" << endl;
    printMatrix(matrix);

    int mainDiagSum, secDiagSum;
    sumDiagonals(matrix, mainDiagSum, secDiagSum);
    cout << "���� ������� �������: " << mainDiagSum << endl;
    cout << "���� ������ �������: " << secDiagSum << endl;

    sortFirstColumn(matrix);
    cout << "������� ���� ���������� ������� �������:" << endl;
    printMatrix(matrix);

    return 0;
}
