#include <iostream>
using namespace std;

template<class T>
struct Node {
    T data;
    Node* next;
};

template<class T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }
    bool is_empty() {
        return (rear == nullptr);
    }
    void enqueue(T x) {
        Node<T>* temp = new Node<T>;
        temp->data = x;
        temp->next = nullptr;
        if(is_empty()) {
            front = rear = temp;
        }
        rear->next = temp;
        rear = temp;
    }
    void dequeue() {
        Node<T>* temp = new Node<T>;
        temp = front;
        if(is_empty())
            return;
        front = front->next;
        if(front == nullptr)
            rear = nullptr;
        delete temp;
    }
    void show() {
        Node<T>* temp = new Node<T>;
        temp = front;
        if(is_empty()) {
            cout << "Emty queue" << endl;
            return;
        }
        while(temp->next != nullptr) {
            cout << temp->data << " | ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};

int main() {
    Queue<int> Q;
    Q.enqueue(3);
    Q.enqueue(5);
    Q.enqueue(19);
    Q.show();
    Q.dequeue();
    Q.show();
    Q.enqueue(34);
    Q.show();
}