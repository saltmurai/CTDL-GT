#include<iostream>
using namespace std;

//Creating a node
struct Node {
    int value;
    Node* left;
    Node* right;
};

//init a node
Node* create_node(int value) {
    Node* temp = new Node;
    temp->value = value;
    temp->left = temp->right = nullptr;
    return temp;
}

//insert a key to BST
Node* insert(Node* root, int value){
    if(root == nullptr) {
        return create_node(value);
    }
    if(value < root->value) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

//find node with the maximum key value
Node* find_maximum(Node* root) {
    Node* max;
    if(root == nullptr) {
        return nullptr;
    }
    max = root;
    while(max->right != nullptr)
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
    while(min->left != nullptr)
    {
        min = min->left;
    }
    return min;
}
int find_min(Node* root){
    Node* temp = find_minimum(root);
    return temp->value;
}
int find_max(Node* root) {
    Node* temp = find_maximum(root);
    return temp->value;
}

void inorder(Node* root) {
    if(root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void pre_order(Node* root) {
    if(root == nullptr) {
        return;
    }
    cout << root->value << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(Node* root) {
    if(root == nullptr) {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout << root->value << " ";
}
int count_even(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    int n = count_even(root->left) + count_even(root->right);
    if(root->value % 2 == 0){
        return n + 1;
    }
    else {
        return n;
    }
}


int main() {
    Node* root = nullptr;
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 65);
    root = insert(root, 25);
    root = insert(root, 50);
    root = insert(root, 76);
    root = insert(root, 35);
    root = insert(root, 10);
    root = insert(root, 28);
    root = insert(root, 27);
    root = insert(root, 73);
    root = insert(root, 36);
    root = insert(root, 34);
    //pre_order(root);
    post_order(root);
    cout << "\nMinimum value:" << find_min(root) << "\n";
    cout << "Maximum Value: " << find_max(root) << "\n";
    cout << "Number of even number: " << count_even(root) << "\n";
    return 0;
}
