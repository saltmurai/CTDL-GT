 #include<iostream>
 using namespace std;

struct Node {
     int key;
     Node* left;
     Node* right;
 };

Node* create_node(int x) {
    Node* temp = new Node;
    temp->key = x;
    temp->left = temp->right = nullptr;
    return temp;
}

Node* search_tree(Node* root, int x) {
    if(root==nullptr) {
        return nullptr;
    }
    if(x == root->key) {
        return root;
    }

    if(x < root->key) {
        return search_tree(root->left, x);
    }
    else {
        return search_tree(root->right, x);
    }
}

Node* find_minimum(Node* t) {
    Node* min;
    if(t == nullptr) {
        return nullptr;
    }
    min = t;
    while(min->left != nullptr) {
        min = min->left;
    }
    return min;
}

//inorder traversal
void traverse_tree(Node* root) {
    if(root == nullptr) {
        return;
    }
    else {
        traverse_tree(root->left);
        cout << root->key << endl;
        traverse_tree(root->right);
    }
}

void insert(Node *&root, int x) {
    if(root == nullptr) {
        root = create_node(x);
    }
    else {
        if(x < root->key) insert(root->left, x);
        else if( x > root->key) insert(root->right, x);
    }
}

void delete_node(Node* &root) {
    Node* temp;
    Node* p;
    //no child
    if(root->left == nullptr && root->right == nullptr) {
        root = nullptr;
    }

    //one child
    else if(root->left == nullptr || root->right == nullptr) {
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
            root->key = temp->key;
            root->left = temp->left;
        }
        else {
            do {
                p = temp;
                temp=temp->right;
            } while (temp->right != nullptr);
            root->key = temp->key;
            p->right = temp->left;
        }
    }
    delete temp;
}
void delete_tree(Node *&root, int x) {
    if(root != nullptr) {
        if(x < root->key) delete_tree(root->left, x);
        else if(x > root->key) delete_tree(root->right, x);
        else delete_node(root);
    }
}

int main() {
    Node* root;
    root = create_node(10);
    insert(root, 3);
    insert(root, 2);
    insert(root, 5);
    insert(root, 15);
    insert(root, 11);
    insert(root, 16);
    traverse_tree(root);
    delete_tree(root, 15);
    traverse_tree(root);
}