#include <iostream>
#include <cmath>
using namespace std;


#define INPUT_ARRAY(arr, n) { \
    for (int i = 0; i < n; i++) { \
        cin >> arr[i]; \
    } \
}

#define OUTPUT_ARRAY(arr, n) { \
    for (int i = 0; i < n; i++) { \
        cout << arr[i] << " "; \
    } \
    cout << endl; \
}

#define COUNT_GREATER_THAN_C(arr, n, C, count) { \
    count = 0; \
    for (int i = 0; i < n; i++) { \
        if (arr[i] > C) { \
            count++; \
        } \
    } \
}

#define PRODUCT_AFTER_MAX_ABS(arr, n, product) { \
    int maxIdx = 0; \
    for (int i = 1; i < n; i++) { \
        if (abs(arr[i]) > abs(arr[maxIdx])) { \
            maxIdx = i; \
        } \
    } \
    product = 1; \
    for (int i = maxIdx + 1; i < n; i++) { \
        product *= arr[i]; \
    } \
}

#define REARRANGE_ARRAY(arr, n) { \
    int temp[n], negIdx = 0, posIdx = 0; \
    for (int i = 0; i < n; i++) { \
        if (arr[i] < 0) { \
            temp[negIdx++] = arr[i]; \
        } else { \
            temp[n - (++posIdx)] = arr[i]; \
        } \
    } \
    for (int i = 0; i < negIdx; i++) { \
        arr[i] = temp[i]; \
    } \
    for (int i = negIdx; i < n; i++) { \
        arr[i] = temp[i]; \
    } \
}

int main() {
    const int N = 10; 
    double C;
    int count;
    double product;

    cout << "Введіть елементи масиву (" << N << " чисел):" << endl;
    INPUT_ARRAY(arr, N);

    cout << "Введіть значення C: ";
    cin >> C;

    COUNT_GREATER_THAN_C(arr, N, C, count);
    PRODUCT_AFTER_MAX_ABS(arr, N, product);
    REARRANGE_ARRAY(arr, N);

    cout << "Кількість елементів більших за C: " << count << endl;
    cout << "Добуток елементів після максимального за модулем: " << product << endl;

    cout << "Перетворений масив: ";
    OUTPUT_ARRAY(arr, N);

    return 0;
}
