#include <iostream>
using namespace std;

class Student {
private:
    int mssv;
    string name;
    string clas;
    float gpa;

public:
    Student() {
        mssv = 0;
        name = clas = "null";
        gpa = 0.0;
    }
    Student(int _mssv, string _name, string _clas, float _gpa) {
        mssv = _mssv;
        name = _name;
        clas = _clas;
        gpa = _gpa;
    }
    int get_mssv() {
        return mssv;
    }
    string get_name() {
        return name;
    }
    string get_clas() {
        return clas;
    }
    float get_gpa() {
        return gpa;
    }
    void show() {
        cout << this->mssv << " " << this->name << " " << this->clas << " " << this->gpa << endl;
    }
    friend ostream& operator <<(ostream& os, const Student& st);


} ;

ostream& operator<<(ostream& os, const Student& st) {
    os << st.mssv << " " << st.name << " " << st.clas << " " << st.gpa;
    return os;
}

struct Node { 
    Student aStudent;
    Node* left;
    Node* right;
};

Node* create_node(Student s) {
    Node* temp = new Node;
    temp->aStudent = s;
    temp->left = temp->right = nullptr;
    return temp; 
}

Node* search_tree(Node* root, Student s) {
    if(root == nullptr) {
        return nullptr;
    }
    if(s.get_mssv() == root->aStudent.get_mssv()) {
        return root;
    }

    if(s.get_mssv() < root->aStudent.get_mssv()) {
        return search_tree(root->left, s);
    }
    else {
        return search_tree(root->right, s);
    }
}Node* find_maximum(Node* root) {
    Node* max;
    if(root == nullptr) {
        return nullptr;
    }
    max = root;
    while (max->right != nullptr)
    {
        max = max->right;
    }
    return max;
}

Node* find_minimum(Node* root) {
    Node* min;
    if(root == nullptr) {
        return nullptr;
    }
    min = root;
    while (min->left != nullptr)
    {
        min = min->left;
    }
    return min;
}

void traverse_tree(Node* root) {
    if(root == nullptr) {
        return;
    }
    else {
        traverse_tree(root->left);
        cout << root->aStudent << endl;
        traverse_tree(root->right);
    }
}

Node* insert(Node* root, Student s) {
    if(root == nullptr) {
        return create_node(s);
    }
    if(s.get_mssv() < root->aStudent.get_mssv()) {
        root->left = insert(root->left, s);
    }
    else {
        root->right = insert(root->right, s);
    }
    return root;
}

Node* delete_tree(Node* root, int key) {
    if(root == nullptr) {
        return root;
    }
    if(key < root->aStudent.get_mssv()) {
        root->left = delete_tree(root->left, key);
    }
    else if(key > root->aStudent.get_mssv()) {
        root->right = delete_tree(root->right, key);
    }
    else {
        if(root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        else if(root->left == nullptr) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == nullptr) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else {
            Node* temp = find_minimum(root->right);
            root->aStudent = temp->aStudent;
            root->right = delete_tree(root->right, key);
        }
    }
    return root;
}

int main() {
    Student s1(20193076, "Sang", "ET1 - 01", 3.06);
    Student s2(20194579, "Binh", "ET1 - 02", 2.06);
    Student s3(20192045, "Hoang", "ET1 - 03", 1.06);
    Student s4(20191034, "Vinh", "ET1 - 04", 0.06);
    Student s5(20193193, "Thanh", "ET1 - 05", 5.06);
    Student s6(20197100, "Duc", "IT - 01", 10.0);

    Node* root = nullptr;
    root = insert(root, s1);
    root = insert(root, s2);
    root = insert(root, s3);
    root = insert(root, s4);
    root = insert(root, s5);
    root = insert(root, s6);
    traverse_tree(root);
    root = delete_tree(root, 20192045);
    traverse_tree(root);
}




