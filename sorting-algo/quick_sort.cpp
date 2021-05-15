#include <iostream>
using namespace std;

int partition(int *a, int first, int last) {
    if(first >= last) return 0;
    int c = a[first];
    int i = first + 1;
    int j = last;
    while (i <= j)
    {
        while (a[i] <= c && i <= j)
        {
            i++;
        }
        while (a[j] > c && i <= j)
        {
            j--;
        }
        if(i < j) swap(a[i], a[j]);
    }
    swap(a[first], a[j]);
    return j;
}

void quick_sort(int *a, int first, int last) {
    int j;
    if(first < last) {
        j = partition(a, first, j - 1);
        quick_sort(a, first, j - 1);
        quick_sort(a, j + 1, last);
    }
}

int main() {
    int A[10] = {3, 5, 1, 4, 7, 9, 12, 9, 54, 2};
    for(int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    int *a = A;
    quick_sort(a, 1, 54);
    cout << "After sort " << endl;
    for(int i = 0; i < 10; i++) {
        cout << a[i] << " " << endl;
    }
    return 0;
}