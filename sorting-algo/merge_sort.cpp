#include <iostream>
using namespace std;
void MergeArrays(int A[],int m, int n, int p){
    int i=m,j=n+1;
    while (i<j && j<=p){
        if (A[i]<=A[j]) i++;
        else {//chen Aj vao vi tri i
            int x=A[j];
            for (int k=j-1;k>=i;k--)
                A[k+1]=A[k];
            A[i]=x;
        i++; j++;
        }
    }
}
void Merge(int *A, int first, int last){
    if (first>=last) return;
    int m=(first+last)/2;
    Merge(A,first,m);
    Merge(A,m+1,last);
    MergeArrays(A,first,m,last);
}

void MergeSort(int *A, int N){
    if (N<2) return;
    Merge(A,0,N-1);
}




int main() {
    int A[10] = {3, 5, 1, 4, 7, 9, 12, 9, 54, 2};
    for(int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    int *a = A;
    MergeSort(a, 10);
    cout << "After sort " << endl;
    for(int i = 0; i < 10; i++) {
        cout << a[i] << " " << endl;
    }
    return 0;
}