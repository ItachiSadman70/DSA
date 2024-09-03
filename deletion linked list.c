#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr= ptr->next;
    }
}
struct Node* deleteAtFirst(struct Node *head)
{
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
};

struct Node* deleteAtIndex(struct Node *head,int index)
{
    struct Node * p = head;
    struct Node * q = head->next;
    for(int i = 0; i<index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
};

struct Node* deleteAtLast(struct Node *head)
{
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third= (struct Node *) malloc(sizeof(struct Node));
    fourth= (struct Node *) malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 22;
    third->next = fourth;

    fourth->data = 90;
    fourth->next = NULL;

    //head = deleteAtFirst(head);
    //head = deleteAtIndex(head,1);
     head = deleteAtLast(head);
    linkedlistTraversal(head);
    return 0;
}

