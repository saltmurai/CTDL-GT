#include <iostream>
#include <string>
using namespace std;
template <class T>
struct Node { 
    T data;
    Node *next;
};

template <class T>
class Stack {
private:
    Node<T> * head;
public:
    Stack() {
        head = nullptr;
    }
    bool is_empty() {
        return (head == nullptr);
    }
    void push(T a) {
        Node<T> *temp = new Node<T>;
        temp->data = a;
        temp->next = head;
        head = temp;   
    }

    T pop() {
        Node<T> *temp = new Node<T>;
        T x;
        if(is_empty()) {
            cout << "Stack is empty" << endl;
            exit(1);
        }
        else 
        {
            x = head->data;
            temp = head;
            head = head->next;
            delete temp;
            return x;
        }    
    }
    T top() {
        return head->data;
    }
    void show() {
        Node<T> *p = new Node<T>;
        p = head;
        while(p != nullptr) {
            cout << p->data << "    ";
            p = p->next;
        }
        cout << "\n";
    }
};
bool check_parentthesis(string str)
{
    Stack<char> S;
    char x;
    int count = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            S.push(str[i]);
            count++;
            continue;
        }

        else if(str[i] == ')') {
            if(S.is_empty()) return 0;
            else S.pop();
        }
    }
    return (S.is_empty() || count != 0);
}

int main() { 
    string test;
    test = "this is a test string ";

    if(check_parentthesis(test))
        cout << "Hop le" << endl;
    else
        cout << "Khong hop le" << endl;

}