#include <iostream>

template <class T>
class List
{
    T *data;
    int length;

public:
    List(int len)
    {
        length = len;
        data = new int[length];
    }
    int get_length()
    {
        return length;
    }
    T get(int i)
    {
        return data[i];
    }
    void set(int i, T x)
    {
        data[i] = x;
    }
    T &operator[](int i)
    {
        return data[i];
    }
    List<T> &operator=(List<T> &b)
    {
        if (data != NULL)
            delete[] data;
        length = b.length;
        data = new T[length];
        data = b.data;
        return *this;
    }
    void add(int i, T x) {
        for(int j = length; j > i; j--)
            data[j] = data[j-1];
        data[i] = x;
    }
    void remove(int i) {
        for(int j = i; j < length; j++)
            data[j] = data[j + 1];
        
    }
    
};

int main() {
    List<int> list1(6);
    list1.set(0, 3);
    list1.set(1, 4);
    list1.set(2, 5);
    list1.set(3, 6);
    list1.add(2,7);
    std::cout << "Sau khi them 7 vao vi tri 2" << std::endl;
    for(int i = 0; i < 8 ; i++) {
        std::cout << list1[i] << '\n';
    }
    list1.remove(2);

    std::cout << "\nSau khi xoa vi tri so 2" << std::endl;
    for(int i = 0; i < 8 ; i++) {
        std::cout << list1[i] << '\n';
    }
}