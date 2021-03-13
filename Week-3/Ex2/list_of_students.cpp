#include <iostream>
#include <string>
using namespace std;
#define null 0

class Student {
public:
    string name;
    string clas;
    int mssv;
    Student(string _name, string _clas, int _mssv) {
        this->name = _name;
        this->clas = _clas;
        this->mssv = _mssv;
    }
};

class Node {
public:
    Student* stu;
    Node* next;
    Node(Student* stu) {
        this->stu = stu;
        next = null;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = null;
    }
    void insert_front(string name, string clas, int mssv) {
        Student *stud = new Student(name, clas, mssv);
        Node *temp = new Node(stud);
        temp->next = nullptr;
        if(head == nullptr) {
            head = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }

    }
    void insert_back(string name, string clas, int mssv) {
        Student *stud = new Student(name, clas, mssv);
        Node *temp = new Node(stud);
        temp->next = nullptr;
        //Tao node p = head de di chuyen den cuoi danh sach
        Node *p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        //temp la node can them vao, temp->next = Null, p->next = temp
        p->next = temp;
        }
    void display() {
        Node *current = head;
        int i = 1;
        while(current != null) {

            cout <<"No." << i++ << ": " <<  current->stu->name << ", " << current->stu->clas << ", " << current->stu->mssv << endl;
            current = current->next;
        }
    }
    void del(string _name) {
        Node *p = head;
        while(p->next->stu->name != _name) {
            p = p->next;
        }
        Node *temp;
        temp = p->next;
        p->next = temp->next;
        delete[] temp;
    }
    bool search(string _name) {
        Node *p = head;
        while(p != nullptr) {
            if(p->stu->name == _name) return 1;
            p = p->next;
        }
        return 0;
        
    }

    void destroy() {
        Node* current;
        while(head != null) {
            current = head->next;
            delete head;
            head = current;
        }
        head = null;
    }
    ~LinkedList() {
        destroy();
    }
};

int main() {
    LinkedList list;
    list.insert_front("Sang", "ET1-01", 20183965);
    list.insert_front("San", "ET1-01", 20193076);
    list.insert_front("Sa", "ET1-02", 20193432);
    list.insert_back("Ted", "ET1-03", 20193842);
    list.display();
    cout << "\nDanh sach sau khi xoa hoc sinh Sang" << endl;
    list.del("Sang");
    list.display();

    cout << "\nTim hoc sinh ten San trong danh sach: " << endl;
    if(list.search("San")) cout << "Co trong danh sach" << endl;
    else cout << "Khong co trong danh sach" << endl;
    return 0;
}