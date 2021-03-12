#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node
{
public:
    T Value;
    Node *Next;
    Node(T v) : Value(v), Next(0) {}
};

template <class T>
class List
{
    Node<T> *head, *tail;
    int count;

public:
    List() : count(0)
    {
        head = 0;
        tail = 0;
    };
    ~List()
    {
        delete[] head;
        delete[] tail;
    }; // Hàm hủy
    void RemoveAll()
    { // Hàm xóa danh sách
        while (count)
        {
            --count;
            Node<T> *p = head;
            head = p->Next;
            delete p;
        }
    }
    void Add(T v)
    { // Hàm bổ sung một node v vào danh sách
        Node<T> *p = new Node<T>(v);
        if (count++ == 0)
        {
            head = p;
        }
        else
        {
            tail->Next = p;
        }
        tail = p;
    }
    Node<T> *First() const { return head; } // Hàm lấy ra Node đầu tiên trong danh sách
    int Count() const { return count; }     // Hàm tính tổng phần tử Node trong danh sách
    T *ToArray()
    {
        T *arr = new T[count];
        Node<T> *p = head;
        for (int i = 0; i < count; i++, p = p->Next)
        {
            arr[i] = p->Value;
        }
        return arr;
    }
};

class person
{
private:
    int id;
    string name;
    string gender;

public:
    person(int _id = 0, string _name = "unknow", string _gender = "unknow")
    {
        id = _id;
        name = _name;
        gender = _gender;
    }
    person(const person &per1)
    {
        id = per1.id;
        name = per1.name;
        gender = per1.gender;
        //next = per1.next;
    }
    // ~person()
    // {
    //     //next = NULL;
    // }
    void input_pers()
    {
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        //cin.ignore(1);
        getline(cin, name);
        //cin.ignore(1);
        cout << "Gender: ";
        getline(cin, gender);
    }
    void swap(person &pers2)
    {
        person tmp = *this;
        *this = pers2;
        pers2 = tmp;
    }
    void display()
    {
        cout << "Person:\n";
        cout << "ID:\t" << id << endl;
        cout << "Name:\t" << name << endl;
        cout << "Gender:\t" << gender << endl;
    }
};

class student : public person
{
private:
    int stuid;
    string clas;

public:
    student(int _stdid, string _clas, int _id, string _name, string _gender) : person(_id, _name, _gender)
    {
        stuid = _stdid;
        clas = _clas;
    }
    student(const student &std1) : person(std1)
    {
        stuid = std1.stuid;
        clas = std1.clas;
    }
    void input_student()
    {
        cout << "\nInput student" << endl;
        person::input_pers();
        cout << "Student no: " << endl;
        cin >> stuid;
        cout << "Class: " << endl;
        getline(cin, clas);
    }
    void swap(student &stud1) {
        person::swap(stud1);
        stuid = stud1.stuid;
        clas = stud1.clas;
    }
    void display()
    {
        cout << "\nStudent no: " << stuid << endl;
        cout << "Class: " << clas << endl;
        person::display();
    }
    int get_stdid() {return stuid;}
};

class listofstudent
{
private:
    List<student> student_list;

public:
    
    void add(student &s1)
    {
        student_list.Add(s1);
    }
    void remove_all()
    {
        student_list.RemoveAll();
    }
    void sort() {
        Node<student> *node = student_list.First();
        Node<student> *node1 = node;

        for (node; node != 0; node = node->Next)
        {
            for (node1; node1 != 0; node1 = node1->Next)
            {
                if (node->Value.get_stdid() > node1->Value.get_stdid())
                {
                    Node<student> *temp;
                    // temp->Value = node->Value;
                    // node->Value = node1->Value;
                    // node1->Value = temp->Value;
                    delete temp;
                }
            }
        }
    }
    void display()
    {
        int n = student_list.Count();
        Node<student> *curr = student_list.First();
        for (int i = 0; i < n; i++)
        {
            curr->Value.display();
            curr = curr->Next;
        }
    }
};

int main()
{
    listofstudent lofstds;
    student s1(04, "ET1", 04, "Sang", "male");
    student s2(03, "ET1", 05, "Binh", "male");
    student s3(05, "ET1", 07, "Vinh", "male");

    lofstds.add(s1);
    lofstds.add(s2);
    lofstds.add(s3);
    //lofstds.sort(); Segmentation fault
    lofstds.display();
}
