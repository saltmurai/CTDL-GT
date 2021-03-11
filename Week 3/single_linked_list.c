#include <stdio.h>

struct Node
{
    int data;
    Node * next;
};

struct LinkedList {
    Node *head;
};
    void init_list(LinkedList &list) {
        list.head = NULL;
    }
    void add_node(LinkedList &list, int value) {
        Node *tmp = new Node;
        tmp->data = value;
        tmp->next = NULL;
        if(list.head==NULL) {
            list.head = tmp; 
        }
        else {
            tmp->next = list.head;
            list.head = tmp;
        }
    }
    void display(LinkedList &list) {
        Node *tmp;
        tmp = list.head;
        while (tmp != NULL)
        {
            printf("%d\n", tmp->data);
            tmp = tmp->next;
        }
    }
    void insert_after(LinkedList &list,int index, int value) {
        Node *p = list.head;
        int i = 0;
        for(i = 0; i < index; i++) {
            p = p->next;
        }
        Node *tmp = new Node;
        tmp->data = value;
        tmp->next = p->next;
        p->next = tmp;
    }
    void insert_before(LinkedList &list, int index, int value) {
        Node *p = list.head;
        int i = 0;
        for(i = 0; i < index - 1; i++) {
            p = p->next;
        }
        Node *tmp = new Node;
        tmp->data = value;
        tmp->next = p->next;
        p->next = tmp;
    }
    Node* get_head(LinkedList &list) {
        return list.head;
    }
    void delete_after(LinkedList &list, Node *before_delete) {
        Node* temp;
        temp = before_delete->next;
        before_delete->next = temp->next;
        delete temp;
    }
    Node* search(LinkedList &list, int K) {
        Node *p = list.head;
        while(p!= NULL) {
            if(p->data == K) return p;
            else p = p->next;
        }
        return NULL;
    }



int main () {
    LinkedList list1;
    init_list(list1);
    add_node(list1, 1);
    add_node(list1, 2);
    add_node(list1, 3);
    insert_before(list1, 1, 5);
    insert_after(list1, 1, 5);
    delete_after(list1, get_head(list1)->next->next);
    display(list1);
}
