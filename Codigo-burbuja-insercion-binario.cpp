#include <iostream>
using namespace std;

void insercion (int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void burbuja (int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int binario (int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Ingrese el tamano del array: ";
    cin >> n;

    int arr[n];
    cout << "Ingrese los elementos del array: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array sin ordenar: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Array ordenado por insercion: ";
    insercion (arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Array ordenado por burbuja: ";
    burbuja (arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int x;
    cout << "Ingrese el numero a buscar: ";
    cin >> x;

    int pos = binario (arr, n, x);
    if (pos != -1) {
        cout << "El numero " << x << " se encuentra en la posicion " << pos + 1 << " del array ordenado." << endl;
    } else {
        cout << "El numero " << x << " no se encuentra en el array." << endl;
    }

    return 0;
}