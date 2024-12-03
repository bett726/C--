#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


struct Item {
    string date;    
    int code;       
    int quantity;   
};

int main() {
    int n;
    cout << "������ ������� ������: ";
    cin >> n;

    vector<Item> items(n);


    for (int i = 0; i < n; ++i) {
        cout << "����� " << i + 1 << ":\n";
        cout << "������ ���� ���������: ";
        cin >> items[i].date;
        cout << "������ ��� ��������: ";
        cin >> items[i].code;
        cout << "������ ������� �������: ";
        cin >> items[i].quantity;
    }

   
    map<int, int> frequency;
    for (const auto& item : items) {
        frequency[item.code] += item.quantity;
    }

 
    int maxCode = -1;
    int maxQuantity = 0;
    for (const auto& entry : frequency) {
        if (entry.second > maxQuantity) {
            maxQuantity = entry.second;
            maxCode = entry.first;
        }
    }

   
    cout << "��� �������� � ������������ ������� ��������: " << maxCode << "\n";
    cout << "�������� ������� ��������: " << maxQuantity << "\n";

    return 0;
}
