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
    cout << "Введіть кількість записів: ";
    cin >> n;

    vector<Item> items(n);


    for (int i = 0; i < n; ++i) {
        cout << "Запис " << i + 1 << ":\n";
        cout << "Введіть дату вилучення: ";
        cin >> items[i].date;
        cout << "Введіть код предмету: ";
        cin >> items[i].code;
        cout << "Введіть кількість одиниць: ";
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

   
    cout << "Код предмету з максимальною кількістю вилучень: " << maxCode << "\n";
    cout << "Загальна кількість вилучень: " << maxQuantity << "\n";

    return 0;
}
