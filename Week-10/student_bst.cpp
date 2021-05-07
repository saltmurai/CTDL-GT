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
}

Node* find_maximum(Node* root) {
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


//inorder

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

void insert(Node* &root, Student s) {
    if(root == nullptr) {
        root = create_node(s);
    }
    else {
        if(s.get_mssv() < root->aStudent.get_mssv()) {
            insert(root->left, s);
        }
        else if(s.get_mssv() > root->aStudent.get_mssv()) {
            insert(root->right, s);
        }
    }
}
void delete_node(Node* &root) {
    Node* temp;
    Node* p;
    //no child
    // if(root->left == nullptr && root->right == nullptr) {
    //     root = temp;
    //     delete temp;
    // }
    //one child
    if(root->left == nullptr || root->right == nullptr) {
        if(root->left == nullptr) {
            temp = root->right;
        }
        else {
            temp = root->left;
        }
        root = temp;
    }
    //two child

    else {
        temp = root->left;
        if(temp->right == nullptr) {
            root->aStudent = temp->aStudent;
            root->left = temp->left;
        }
        else {
            do {
                p  = temp;
                temp = temp->right;
            } while(temp->right != nullptr);
            root->aStudent = temp->aStudent;
            p->right = temp->left;
        }
    }
    delete temp;
}

void delete_tree(Node* &root, int _mssv) {
    if(root != nullptr) {
        if(_mssv < root->aStudent.get_mssv()) {
            delete_tree(root->left, _mssv);
        }
        else if(_mssv > root->aStudent.get_mssv()) {
            delete_tree(root->right, _mssv);
        }
        else delete_node(root);
    }
}




int main() {
    Student s1(20193076, "Sang", "ET1 - 01", 3.06);
    Student s2(20194579, "Binh", "ET1 - 02", 2.06);
    Student s3(20192045, "Hoang", "ET1 - 03", 1.06);
    Student s4(20191034, "Vinh", "ET1 - 04", 0.06);
    Student s5(20193193, "Thanh", "ET1 - 05", 5.06);
    Student s6(20197100, "Duc", "IT - 01", 10.0);

    Node* root;
    root = create_node(s1);
    insert(root, s2);
    insert(root, s3);
    insert(root, s4);
    insert(root, s5);
    insert(root, s6);
    traverse_tree(root);
    delete_tree(root, 20192045);
    traverse_tree(root);

    cout << "Tim sinh vien co mssv 20192045" << endl;
    cout << find_maximum(root)->aStudent;
}