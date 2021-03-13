#include<stdlib.h>
#include<string.h>
#include<stdio.h>
//Node init
struct Student
{
    int mssv;
    char name[100];
    char clas[100];
    float gpa;
    struct Student *next;
    
}* head;

//insert node
void insert(int mssv, char* name, char* clas, float gpa)
{
    
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->mssv = mssv;
    strcpy(student->name, name);
    strcpy(student->clas, clas);
    student->gpa = gpa;
    student->next = NULL;
    
    if(head==NULL){
        head = student;
    }
    else{
        student->next = head;
        head = student;
    }
    
}
void search(int mssv)
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->mssv==mssv){
            printf("MSSV: %d\n", temp->mssv);
            printf("Name: %s\n", temp->name);
            printf("Lop: %s\n", temp->clas);
            printf("GPA: %0.4f\n", temp->gpa);
            return;
        }
        temp = temp->next;
    }
    printf("Khong tim thay sinh vien co MSSV %d!\n", mssv);
}
void update(int mssv)
{
    
    struct Student * temp = head;
    while(temp!=NULL){
        
        if(temp->mssv==mssv){

            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new class: ");
            scanf("%s", temp->clas);
            printf("Enter new gpa: ");
            scanf("%f",&temp->gpa);
            printf("Cap nhap thanh cong!\n");
            return;
        }
        temp = temp->next;
        
    }
    printf("Khong tim thay sinh vien co MSSV %d!\n", mssv);
    
}
void Delete(int mssv)
{
    struct Student * temp1 = head;
    struct Student * temp2 = head; 
    while(temp1!=NULL){
        
        if(temp1->mssv==mssv){
            if(temp1==temp2){
                head = head->next;
                free(temp1);
            }
            else{

                temp2->next = temp1->next;
                free(temp1); 
            }
            
            printf("Xoa sinh vien thanh cong!\n");
            return;
            
        }
        temp2 = temp1;
        temp1 = temp1->next;
        
    }
    printf("Khong tim thay sinh vien co MSSV %d!\n", mssv);

    
}
void display()
{
    struct Student * temp = head;
    while(temp!=NULL){
        
        printf("MSSV: %d\n", temp->mssv);
        printf("Name: %s\n", temp->name);
        printf("Lop: %s\n", temp->clas);
        printf("GPA: %f\n\n", temp->gpa);
        temp = temp->next;
        
    }
}
int main()
{
    head = NULL;
    int choice;
    char name[100];
    char clas[100];
    int mssv;
    float gpa;
    printf("0. Ket thuc chuong trinh\n1. Nhap thong tin\n2. Tim sinh vien\n3. Xoa sinh vien\n4. Cap nhap sinh vien\n5. Hien thi danh sach sinh vien");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter MSSV: ");
                scanf("%d", &mssv);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter class: ");
                scanf("%s", clas);
                printf("Enter gpa: ");
                scanf("%f", &gpa);
                insert(mssv, name, clas, gpa);
                break;
            case 2:
                printf("Enter MSSV to search: ");
                scanf("%d", &mssv);
                search(mssv);
                break;
            case 3:
                printf("Enter MSSV to delete: ");
                scanf("%d", &mssv);
                Delete(mssv);
                break;
            case 4:
                printf("Enter MSSV to update: ");
                scanf("%d", &mssv);
                update(mssv);
                break;
            case 5:
                display();
                break;
            default:
                printf("Ending program...\n");
                break;
        }
        
    } while (choice != 0);
}