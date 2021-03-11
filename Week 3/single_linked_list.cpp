#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head;
public:
    linked_list()
    {
        head = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
        }
        else
        {
            tmp->next = head;
            head = tmp;
        }
    }
    node* get_head() {
        return head;
    }
    void insert_front(int n) {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = head;
        head = tmp;
    }
    void after(int index, int value) {
        node *p = head;
        for(int i = 0; i < index; i++) {
            p = p->next;
        }
        node *tmp = new node;
        tmp->data = value;
        tmp->next = p->next;
        p->next = tmp;
    }
    void before(int index, int value) {
        node *p = head;
        for(int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        node *tmp = new node;
        tmp->data = value;
        tmp->next = p->next;
        p->next = tmp;
    }
    void del(node *before_del) {
        node* temp;
        temp = before_del->next;
        before_del->next = temp->next;
        delete temp;
    }
    void display()
    {
        node *tmp;
        tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
    node* search(int K) {
        node *p = head;
        while(p!= nullptr) {
            if(p->data == K) return p;
            else p = p->next;
        }
        return nullptr;
    }
};

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.add_node(4);
    //List now: 4 3 2 1
    a.insert_front(5);
    //List now: 5 4 3 2 1
    a.after(1, 6);
    //list now: 5 4 6 3 2 1
    a.before(1, 6);
    //list now: 5 6 4 6 3 2 1
    
    //head->next->next->next point to 3
    a.del(a.get_head()->next->next->next);
    
    //search for value 2 in the linked list. return a node pointer point to that node
    cout << a.search(2)->data << endl;

    //display the linkedlist
    a.display();
    return 0;
}