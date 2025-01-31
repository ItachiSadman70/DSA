#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* createNode(int data)
{
    struct node *n;//creating a node pointer
    n = (struct node*)malloc(sizeof(struct node));//allocating memory in the heap
    n->data=data;//setting the data
    n->left= NULL;//setting the left and right children to NULL
n->right= NULL;//setting the left and right children to NULL
              return n;
}

void preOrder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    //constructing the root node - using function()
    struct node *p= createNode(4);
    struct node *p1= createNode(1);
    struct node *p2= createNode(6);
    struct node *p3= createNode(5);
    struct node *p4= createNode(2);
// linking the root node with left and right children
    p->left= p1;
    p->right= p2;
    p1->left= p3;
    p1->right= p4;
    preOrder(p);
    printf("\n");
    postOrder(p);

    return 0;




}

