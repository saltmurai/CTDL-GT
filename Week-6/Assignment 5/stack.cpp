#include <iostream>
#define MAX 10
using namespace std;

template<class T>
struct Node {
    T data;
    Node* next;
};


template<class T>
class Stack {
private:
    unsigned int n;
    Node<T>* head;
public:
    Stack() {
        head = nullptr;
    }
    bool is_empty() {
        return (head == nullptr);
    }
    bool is_full() {
        return (n == MAX);
    }
    T top() {
        if(is_empty()) {
            cout << "List if empty" << endl;
            exit(1);
        }
        else
            return head->data;
    }

    void pop() {
        if(is_empty())
            cout << "Nothing to pop" << endl;
        else
            head = head->next;
            
    }
    void push(T x) {
        Node<T>* temp = new Node<T>;
        temp->data = x;
        temp->next = nullptr;
        if(is_full())
            cout << "List is full" << endl;
        else
            temp->next = head;
            head = temp;
    }
    void show() { 
        Node<T> *p = new Node<T>;
        p = head;
        while(p->next != nullptr) {
            cout << p->data << "--->";
            p = p->next; 
        }
        cout << p->data << '\n';
    }
};

int main() {
    Stack<int> S;
    S.push(3);
    S.push(4);
    S.push(5);
    S.show();
    cout << "after pop: " << endl;
    S.pop();
    S.show();
    cout << "Top: " << S.top();
}