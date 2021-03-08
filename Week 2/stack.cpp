#include <iostream>
#define MAX 100
using namespace std;

template<class T>
class Stack {
    T  info[MAX];
    unsigned int n;	//Số phần tử của Stack
public:
    //Khoi tao Stack
    Stack() {
        n = 0;
    }

    //Kiem tra Stack rong hay khong
    bool IsEmpty() {
        if (n == 0) return true;
        else return false;
    }

    //Kiem tra Stack day hay khong
    bool IsFull() {
        if (n == MAX) return true;
        else return false;
        //return (n==Max);
    }

    //Bo sung phan tu vao Stack
    void Push(T K) {
        if (IsFull()) return;
        info[n] = K;
        n++;
    }

    //Lay ra phan tu o dinh Stack
    T Pop() {
        if (IsEmpty()) return NULL;
        n--;
        return info[n];
    }

    //Tra phan tu o dinh Stack, khong lay ra phan tu do
    T Top() {
        if (IsEmpty()) return NULL;
        return info[n - 1];
    }

    //Hien thi phan tu trong Stack
    void show() {
        if (IsEmpty())
            return;
        for (int i = 0; i < n; i++)
            cout << info[i] << "\t";
        cout << endl;
    }
};

int main()
{
    Stack<int> S;
    S.Push(1);
    S.Push(2);
    S.Push(3);
    S.show();
    
}
