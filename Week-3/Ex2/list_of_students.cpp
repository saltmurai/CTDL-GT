#include <iostream>
#include <string>
using namespace std;
#define null 0

class Student {
public:
    string name;
    int age;
    float gpa;
    Student(string name, int age, float gpa) {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
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
    int getSize() {
        return size;
    }
    void append(string name, int age, float gpa) {
        Student *stud = new Student(name, age, gpa);
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
    void insert_back(string name, int age, float gpa) {
        Student *stud = new Student(name, age, gpa);
        Node *temp = new Node(stud);
        temp->next = NULL;
        //Tao node p = head de di chuyen den cuoi danh sach
        p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        //temp la node can them vao, temp->next = Null, p->next = temp
        p->next = temp;
        }

    void removeStu(string name) {
        if(head != null) {
            Node *current = head;
            if(current->stu->name == name) {
                delete current;
            } else {
                while(current != null) {
                    if(current->next->stu->name == name) {
                        current->next = current->next->next;
                        break;
                    } else {
                        current = current->next;
                    }
                }
            }
            size--;
        }
    }
    void removeHead() {
        if(head != null) {
            Node *current = head;
            head = head->next;
            delete current;
            size--;
        }
    }
    void display() {
        Node *current = head;
        while(current != null) {
            cout << current->stu->name << ", " << current->stu->age << ", " << current->stu->gpa << endl;
            current = current->next;
        }
        cout << "*" << getSize() << endl;
        cout << endl;
    }

    void destroy() {
        Node* current;
        while(head != null) {
            current = head->next;
            delete head;
            head = current;
        }
        head = null;
        tail = null;
        size = 0;
    }
    ~LinkedList() {
        destroy();
    }
};

int main() {
    LinkedList list;
    list.run();
    return 0;
}