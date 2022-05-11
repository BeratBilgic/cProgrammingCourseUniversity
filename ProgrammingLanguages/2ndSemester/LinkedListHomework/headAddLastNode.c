#include <stdio.h>
#include <stdlib.h>

struct node{
    int number;
    struct node *next;
};

typedef struct node node;

node* createList();
void traverseList(node* head);
node* cutheadaddlast(node* head); 

int main(){
    node *head;
    head = createList();
    traverseList(head);
    head = cutheadaddlast(head);
    traverseList(head);
    
    return 0;
}

node* cutheadaddlast(node* head){
    node *p, *newHead;
    p = head;
    newHead = head->next;
    while (p != NULL)
    {
        if (p->next == NULL && p == head)
        {
            break;
        }else if (p->next == NULL)
        {
            p->next = head;
            head->next = NULL;
            break;
        }
        
        p = p->next;
    }
    return newHead;
}


node* createList(){
    node *ptr,*head;

    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            head = (node*)malloc(sizeof(node));
            ptr = head;
        }else
        {
            ptr->next = (node*)malloc(sizeof(node));
            ptr = ptr->next;
        }
        ptr->number = i+1;
    }
    ptr->next = NULL;
    return head;
}

void traverseList(node* head){
    node *p;
    p = head;
    printf("\n");
    while (p != NULL)
    {
        printf("%d\t",p->number);
        p = p->next;
    } 
    printf("\n");     
}