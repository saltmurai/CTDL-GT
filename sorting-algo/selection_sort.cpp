#include <iostream>

using namespace std;

void selection_sort(int *a, int n) {
    int min;
    for(int i = 0; i < n - 1; i++) {
        min = i;
        for(int j = i + 1; j <n; j ++) {
            if(a[j] < a[min]) min = j;
        }
        if(min != i) {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}

int main() {
    int A[10] = {3, 5, 1, 4, 7, 9, 12, 9, 54, 2};
    for(int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    int *a = A;
    selection_sort(a, 10);
    cout << "After sort " << endl;
    for(int i = 0; i < 10; i++) {
        cout << a[i] << " " << endl;
    }
    return 0;
}