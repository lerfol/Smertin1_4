#include <iostream>
#include <clocale>
#include <array>
#include <ctime>
using namespace std;

void printArr(int* arr, int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "]";
    cout << endl;
}

//#2
int findLast(array <int,9>& arr, int x) {
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = size-1; i >=0; i--) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}
//#4
int *add(int *arr, int x, int pos, int n) {
    int wr, wr2;
    if (n < pos) {
        return arr;
    }
    else{
        for (int i = 0; i <= n; i++) {
            if (i == pos) {
                wr = arr[i];
                arr[i] = x;
            }
            if (i > pos) {
                wr2 = arr[i];
                arr[i] = wr;
                wr = wr2;
            }
        }
        return arr;
    }
}
//#6
void reverse(int arr[], int size6) {
    int left = 0;
    int n = size6;
    int right = n - 1;
    int temp;
    while (left <= right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}
//#8
int *concat(int arr1[], int x, int arr2[], int y) {
    int sm = x + y;
    int j = 0;
    int* arr3 = new int[sm];
    for (int i = 0; i < sm; i++) {
        if (i < x) {
            arr3[i] = arr1[i];
        }
        else {
            arr3[i] = arr2[j];
            j++;
        }
    }
    return arr3;
    delete[] arr3;

}
//#10
int* deleteNegative(int arr[], int x) {
    int* arr2 = new int[x];
    int k = 0;
    printArr(arr, x);
    for (int i = 0; i < x; i++) {
        if (arr[i] >= 0) {
            arr2[k] = arr[i];
            k++;
        }
    }
    printArr(arr2, k);
    return arr2;
    delete[] arr2;
}
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    //#2
    array <int, 9> arr2 = { 1, 2 ,3 ,4 , 4, 5, 6, 2 , 1 };
    cout << "1 2 3 4 4 5 6 2 1" << endl;
    int x2;
    cout << "№2. Введите число: ";
    cin >> x2;
    cout << findLast(arr2, x2) << endl;
    //#4
    int n4, pos, x4;
    cout << "№4. Введите кол-во элементов в массиве:";
    cin >> n4;
    cout << "Введите индекс места в которое будет вставлено число:";
    cin >> pos;
    cout << "Введите число которое будет вставлено:";
    cin >> x4;
    int* arr4 = new int[n4*2];
    for (int i = 0; i < n4; i++) {
        arr4[i] = rand() % 20;
    }
    printArr(arr4, n4);
    arr4 = add(arr4, x4, pos, n4);
    printArr(arr4, n4 + 1);
    delete[] arr4;
    //#6
    cout << "№6" << endl;
    const int size6 = 7;
    int arr6[size6] = { 1,2,3,4,5,6,7 };
    printArr(arr6, size6);
    reverse(arr6,size6);
    printArr(arr6, size6);
    //#8
    cout << "№8" << endl;
    int arr8_1[5] = { 1,2,3,4,5 };
    int arr8_2[3] = { 9,10,11 };
    int* arr8_3 = new int[20];
    arr8_3 = concat(arr8_1,5, arr8_2,3);
    printArr(arr8_3, 8);
    //#10
    int arr10[5] = { 1,-2,3,4,-4 };
    int* arr10_2 = new int[5];
    cout << "№10" << endl;
    arr10_2 = deleteNegative(arr10, 5);
    delete[] arr8_3;
    delete[] arr10_2;

}

