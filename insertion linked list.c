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
struct Node* insertAtFirst(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
};
struct Node* insertAtEnd(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;
    while(p->next!=NULL)
    {
        p= p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
};
struct Node* insertAfterNode(struct Node *head,struct Node *prevNode, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
};
struct Node* insertAtIndex(struct Node *head, int data, int index)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i=0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data= data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third= (struct Node *) malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 22;
    third->next = NULL;

    linkedlistTraversal(head);
    //head = insertAtFirst(head, 47);
    //head = insertAtIndex(head, 78, 2);
    //head = insertAtEnd(head, 78);
    head = insertAfterNode(head,third,100);
    linkedlistTraversal(head);
    return 0;
}

