#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node;

//Create the linked list
node *list;

//Them node vao dau danh sach
node *addFront(node *head,int value){
	//Tao 1 not temp, chua value
    node *temp=(node*)malloc(sizeof(node));
	temp->data=value;
	
    //Neu danh sach rong temp = head
	if(head == NULL){
		temp->next=NULL;
		head=temp;
	}

    
    //Neu danh sach ko rong temp noi toi head, roi danh dau head = temp

	else{
		
		temp->next=head;
		head=temp;
	}
	return head;
}

//Them node vao cuoi danh sach
node *addBack(node *head, int value) {
    node *temp = (node*)malloc(sizeof(node));
    node *p = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;
    //Tao node p = head de di chuyen den cuoi danh sach
    p = head;
    while(p->next != NULL) {
        p = p->next;
    }
    //temp la node can them vao, temp->next = Null, p->next = temp
    p->next = temp;
    return head;
}

//Them node vao vi tri nhat dinh
node *insert_node_after(node* head, int index, int value) {
    node *p = (node*)malloc(sizeof(node));
    node *temp = (node*)malloc(sizeof(node));
    p = head;
    temp->data = value;
    int i = 0;
    //Sau vong for node p dang o vi tri ma can them node temp vao sau
    for(i; i < index; i++) {
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;

    return head;


}

//Tuong tu nhung p lui lai 1 node
node *insert_node_before(node* head, int index, int value) {
    node *p = (node*)malloc(sizeof(node));
    node *temp = (node*)malloc(sizeof(node));
    p = head;
    temp->data = value;
    int i = 0;
    for(i; i < index - 1; i++) {
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;

    return head;

}

//Ham xoa 1 node voi tham so la insex
node *delete_node(node* head, int index) { 
    node *p = (node*)malloc(sizeof(node));
    node *temp = (node*)malloc(sizeof(node));
    p = head;
    int i = 0;
    //p tro toi node truoc node can xoa
    for(i; i < index - 1; i++) {
        p = p->next;
    }

    temp = p->next;
    p->next = temp->next;
    free(temp);
    

    return head;
}
void print(node *head){
	if(head ==NULL)
		printf("list is empty");
	else{
		node *q=head;
		while(q->next != NULL)
		{
			printf("%d  ",q->data);
			q=q->next;
		}
		
		printf("%d",q->data);
	
	}
}
//Ham tim min max cua day
int topla(node *head){
	
	int max=head->data;
	int min=head->data;
	
	while(head != NULL){
		
		if(head->data > max)
			max = head->data;
		if(head->data < min)
			min=head->data;
		
		head=head->next;
	}	
	printf("\n*******\nmax : %d\nmin : %d\n",max,min);
	return min+max;
}


int main(){

	list=addFront(list,5);
	list=addFront(list,3);
	list=addFront(list,4);
	list=addFront(list,9);
	list=addFront(list,1);
	list=addFront(list,2);
    list=addBack(list, 10);
    list=insert_node_after(list, 2, 26);
    list=insert_node_before(list, 1, 26);
    print(list);

    list=delete_node(list, 4);
	
    //index start at 0
    printf("\nAfter delete node 4: \n");
	print(list);
			
	printf("\n---sonuc--\n%d",topla(list));
    return 0;
}