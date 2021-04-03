#include <iostream>
using namespace std;
//almost fully functional double_linked_list
template<class T>
struct Node {
    T data;
    Node* next;
    Node* prev;
};

template<class T>
class Linked_list {
private:
    Node<T>* head;
public:
    Linked_list() {
        head = nullptr;
    }
    bool is_empty() {
        return (head == nullptr);
    }
    void add(T x) {
        Node<T> * temp = new Node<T>;
        temp->data = x;
        temp->next = head;
        temp->prev = nullptr;
        if(head == nullptr) {
            head = temp;
        }
        else {
            head->prev = temp;
            head = temp;
        }
    }
    void add_after(Node<T>* n, T x) {
        Node<T>* temp = new Node<T>;
        temp->data = x;
        temp->next = n->next;
        n->next->prev = temp;
        n->next = temp;
        temp->prev = n;
    }
    //Ham lay node T
    Node<T>* get_node(int index) {
        Node<T>* temp = new Node<T>;
        temp = head;
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }
    void remove(Node<T>* del_node) {
        Node<T>* temp = new Node<T>;
        temp = del_node;
        if(del_node == head) {
            head = head->next;
            head->prev = nullptr;
            del_node->next = nullptr;
            delete temp;
        }
        else if(del_node->next == nullptr) {
            del_node->prev->next = nullptr;
            del_node->next = nullptr;
            del_node->prev = nullptr;
            delete temp;
        }
        else {
            del_node->prev->next = del_node->next;
            del_node->next->prev = del_node->prev;
            del_node->next = nullptr;
            del_node->prev = nullptr;
            delete temp;
        }
    }
    void search(T x) {
        Node<T> *p = new Node<T>;
        p = head;
        int i = 0;
        if(is_empty()) {
            cout << "nothing to search" << endl;
            return;
        }
        else {
            while(p != nullptr) {
                if(p->data == x) {
                    cout << "Found at Node number: " << i << endl;
                    return;
                }
                p = p->next;
                i++;
            }
            cout << "Not found " << endl;
        }
    }
    void show() {
        Node<T>* p = new Node<T>;
        p = head;
        while(p->next != nullptr) {
            cout << p->data << "-->";
            p = p->next;
        }
        cout << p->data << endl;
    }

};

int main() {
    Linked_list<int> list;
    list.add(3);
    list.add(4);
    list.add(5);
    list.add_after(list.get_node(1), 10);
    list.show();
    list.search(10);
    list.remove(list.get_node(0));
    list.show();
}