#include <iostream>

using namespace std;

void bubble_sort(int *a, int n) {
    int i = 0;
    bool sorted = false;
    while(!sorted && i< n - 1) {
        sorted = true;
        for(int k = n - 2; k >= i; k--) {
            if(a[k] > a[k + 1]) {
                swap(a[k], a[k + 1]);
                sorted = false;
            }
        }
        i++;
    }
}

int main() {
    int A[10] = {3, 5, 1, 4, 7, 9, 12, 9, 54, 2};
    for(int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    int *a = A;
    bubble_sort(a, 10);
    cout << "After sort " << endl;
    for(int i = 0; i < 10; i++) {
        cout << a[i] << " " << endl;
    }
    return 0;
}