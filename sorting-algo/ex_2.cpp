#include <iostream>
using namespace std;

void no_birth(int *a, int begin, int end) {
    int i = 0;
    for(i; i < end - begin + 1; i++) {
        if(a[i] == 0) {
            cout << begin + i << endl;
        }
    }
}
int less_than_10(int *a, int begin, int end) {
    int count = 0;
    for(int i = 0; i < end - begin + 1; i++) {
        if(a[i] <= 10) {
            count = count + 1;
        }
    }
    return count;

}
int age_over_50(int *a, int begin, int end, int current_year) {
    int count = 0;
    for(int i = 0; i < end - begin + 1; i++){
        if((current_year - (begin + i)) > 50) {
            count += a[i];
        }
    }
    return count;
}

int main() {
    int A[100];
    cout << "Nhap nam bat dau: ";
    int X, Y;
    cin >> X;
    cout << "Nhap nam ket thuc: ";
    cin >> Y;
    int Z;
    cout << "Nhap nam hien tai: ";
    cin >> Z;
    for(int i = 0; i < Y - X + 1; i++) {
        cout << "nhap " << X + i << ": ";
        cin >> A[i];
    }
    int *a = A;
    cout << "So nam co so nguoi sinh = 0: ";
    no_birth(a, X , Y);
    cout << "\nSo nam co so nguoi sinh <= 10: " << less_than_10(a, X, Y);
    cout << "\nSo nguoi > 50 tuoi tinh den " << Z << " la: " << age_over_50(a, X, Y, Z);
    return 0;
}