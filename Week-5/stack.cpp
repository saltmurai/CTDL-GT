#include <iostream>

using namespace std;

class Node {
public: 
    int data;
    Node *next;
};

class Stack {
private:
    Node *head;
public:
    Stack() {
        head = nullptr;
    }
    bool is_empty() {
        return (head == nullptr);
    }
    void push(int a) {
        Node * p = new Node;
        p->data = a;
        p->next = head;
        head = p;
    }
    int pop() {
        Node * p = new Node;
        int x;
        if(this->is_empty()) {
            cout << "Stack is empty"; 
            exit(1);
            }
        else {
            p = head;
            int x = p->data;
            head = head->next;
            delete p;
            return x;
        }
    }
    int top() { 
        return head->data;
    }
};

int main() { 
    Stack S;
    S.push(3);
    S.push(5);
    S.push(6);
    cout << S.top() << endl;
    cout << S.pop() << endl;
    cout << S.top() << endl;
}