#include <iostream>
using namespace std;

int sum(int n) {
    if(n <= 1)
        return n;
    return n + sum(n-1);
}

int comb(int k, int n) {
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    return comb(k - 1, n - 1) + comb(k, n - 1);
}

int ucln(int a, int b) {
    if(b == 0)
        return a;
    return ucln(b, a % b);
}


int min(int a[], int n) {
    if(n == 1)
        return a[0];

    int first_half = n/2;
    int second_half = n -first_half;
    if(min(a[0], first_half) < min(a[second_half], second_half)) 
        return min(a[0], first_half);
    else 
        return min(a[second_half], second_half);
}


int main() {
    int A[] = {3, 0, 5, 1, 2, 6};
    int *p = A;
    cout << min(p, 6);
    cout << "Tong 5 so tu nhien dau tien: " << sum(5) << endl;
    cout << "Uoc chung lon nhat cua 3 & 4: " << ucln(3,4) << endl;
    cout << "Tinh to hop chap k cua n: " << comb(3,4) << endl;
}