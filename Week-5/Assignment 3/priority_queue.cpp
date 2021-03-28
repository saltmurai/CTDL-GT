#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
struct Node {
   int p;
   int info;
   Node *next;
};
class Priority_Queue {
   private:
      Node *head;
   public:
      Priority_Queue() {
         head = NULL;
      }
      void insert(int i, int p) {
         Node *temp, *q;
         temp = new Node;
         temp ->info = i;
         temp->p = p;
         if (head == NULL || p < head->p) {
            temp->next= head;
            head = temp;
         } else {
            q = head;
            while (q->next != NULL && q->next->p <= p)
               q = q->next;
               temp->next = q->next;
               q->next = temp;
         }
      }
      void del() {
         Node *temp;
         if(head == NULL) //if queue is null
            cout<<"Queue is empty\n";
         else {
            temp = head;
            cout<<"Deleted item is: "<<temp->info<<endl;
            head = head->next;
            free(temp);
         }
      }
      void show()   { 
         Node *ptr;
         ptr = head;
         if (head == NULL)
            cout<<"Queue is empty\n";
         else {
            cout<<"Queue is :\n";
            cout<<"Priority Item\n";
            while(ptr != NULL) {
               cout<< "No." << ptr->p<<": "<<ptr->info<<endl;
               ptr = ptr->next;
            }
         }
      }
};
int main() {
   Priority_Queue pq;
   pq.insert(3, 4);
   pq.insert(4, 3);
   pq.insert(5, 2);
   pq.insert(2, 1);
   pq.show();
   pq.del();
   pq.show();
   return 0;
}