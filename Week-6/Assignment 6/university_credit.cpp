#include <iostream>
using namespace std;

template<class T>
class Node {
public:
    T data;
    Node* next;
};

//tao 1 cau truc course
class Course {
private:
    string course_id;
    string course_name;
    unsigned int credit;
public:
    Course() {
        course_id = "null";
        course_name = "null";
        credit = 0;
    }
    Course(string _id, string _name, int _cre) {
        course_id = _id;
        course_name = _name;
        credit = _cre;
    }
    int get_credit() {
        return credit;
    }
    string get_id() {
        return course_id;
    }
    void show() {
        cout << course_id << " " << course_name << "(" << credit << ")";
    }
    friend ostream& operator <<(ostream& os, const Course& c);

};

ostream& operator<<(ostream& os, const Course& c) {
    os << c.course_id << " - " << c.course_name << "(" << c.credit <<")";
    return os;
}

//customize linked list only can use with course class
template<class T>
class single_linked_list {
private:
    Node<T>* head;
public:
    single_linked_list() {
        head = nullptr;
    }
    bool is_empty() {
        return (head == nullptr);
    }
    void add(T x) {
        Node<T>* temp = new Node<T>;
        temp->data = x;
        temp->next = nullptr;
        //neu danh sach rong head = temp;
        if(is_empty()) {
            temp->next = nullptr;
            head = temp;
        }

        //khi add them 1 node vao danh sach, danh sach da duoc sap xep san
        else {
            //Neu node them vao nho hon head ta them nhu bth
            if(x.get_credit() < head->data.get_credit()) {
                temp->next = head;
                head = temp;
            }
            //ham get_node tra ve node cuoi cung trong danh sach ma so tin chi nho hon mon hoc dang them vao
            else {
            temp->next = get_node(x.get_credit())->next;
            get_node(x.get_credit())->next = temp;
            }
        }
    //and vice versa, the list is shorted
    }
    Node<T>* get_node(int x) {
        Node<T>* temp = new Node<T>;
        if(is_empty())
            return nullptr;
        temp = head;

        //traverse den node cuoi cung neu node tiep theo lon hon x break tra ve node hien tai
        while(temp->next != nullptr) {
            if(temp->next->data.get_credit() > x) {
                break;
            }
            temp = temp->next;
        }
        return temp;
    }
    void show() {
        Node<T>* temp = new Node<T>;
        temp = head;
        if(is_empty()) {
            cout << "empty" << endl;
            return;
        }
        while(temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    void delete_course(string id) {
        Node<T> *p = new Node<T>;
        p = head;
        if(is_empty()) {
            cout << "nothing to delete " << endl;
            return;
        }
        //delete first node not working
        if (head->data.get_id() == id) {
            Node<T> *temp = new Node<T>;
            temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
            return;
        }
        while(p->next->data.get_id() != id) {
            p = p->next;
        }
        Node<T> *temp = new Node<T>;
        temp = p->next;
        p->next = temp->next;
        delete temp;
    }
};

int main() {
    Course c1("ET2050", "Cau truc du lieu giai thua", 9);
    Course c2("ET2060", "ly thuyet mach", 5);
    Course c3("ET3212", "Ki thuat lap trinh", 7);
    Course c4("test", "test", 6);
    single_linked_list<Course> list;
    list.add(c1);
    list.add(c2);
    list.add(c3);
    list.add(c4);
    list.show();
    cout << endl;
    cout << "Sau khi xoa test" << endl;
    list.delete_course("ET2060");
    list.show();
    return 0;
}

