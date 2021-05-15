#include <iostream>
using namespace std;

void insertion_sort(int *a, int n) {
    for(int i = 1; i < n; i ++) {
        int temp = a[i];
        int j = i - 1;
        while ((temp<a[j]) &&(j>= 0))
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
        
    }
}


int main() {
    int A[10] = {3, 5, 1, 4, 7, 9, 12, 9, 54, 2};
    for(int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    int *a = A;
    insertion_sort(a, 10);
    cout << "\nAfter sort " << endl;
    for(int i = 0; i < 10; i++) {
        cout << a[i] << " " << endl;
    }
    return 0;
}

