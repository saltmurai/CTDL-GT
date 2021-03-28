#include <iostream>

using namespace std;
template<class T>
class Node {
public: 
    T data;
    Node *next;
};

class Student {
private:
    string name;
    int mssv;
public:
    Student(string _name, int _mssv) {
    name = _name;
    mssv = _mssv; 
    }
}

template<class T>
class Stack {
private:
    Node<T> *head;
public:
    Stack() {
        head = nullptr;
    }
    bool is_empty() {
        return (head == nullptr);
    }
    void push(T a) {
        Node<T> * p = new Node<T>;
        p->data = a;
        p->next = head;
        head = p;
    }
    T pop() {
        Node<T> * p = new Node<T>;
        T x;
        if(this->is_empty()) {
            cout << "Stack is empty"; 
            exit(1);
            }
        else {
            p = head;
            T x = p->data;
            head = head->next;
            delete p;
            return x;
        }
    }
    T top() { 
        return head->data;
    }
    void show_stack() {
        Node<T> * p = new Node<T>;
        p = head;
        while(p!= nullptr) { 
            cout << p->data << "    ";
            p = p->next;
        }
        cout << "\n";
    }
};

int main() { 
    Stack<Student> S;
    Student s1("Sang", 20193076);
    Student s2("Vinh", 20193053);
    Student s3("Binh", 230394);
    S.push(s1);
    S.push(s2);
    S.push(s3);
    S.show_stack();
    cout << S.top() << endl;
    cout << S.pop() << endl;
    cout << S.top() << endl;
}