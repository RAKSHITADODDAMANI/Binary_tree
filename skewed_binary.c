#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define count 10

struct node{
     int data;
     struct node *left,*right;
};

struct node * newnode(int data)
{
    struct node * node=(struct node *)malloc(sizeof(struct node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}
//it does reverse inorder
void print2DUtil(struct node * root ,int space)
{
    if(root==NULL)
        return;
    //increase the dist b\w levels
    space+=count;

    // process right child first
    print2DUtil(root->right,space);
    //print current node after space
    //count
    printf("\n");
    for(int i=count;i<space;i++)
        printf(" ");
    printf("%d\n",root->data);
    //process left child
    print2DUtil(root->left,space);
}

//wrapper over print2DUtil()
void print2D(struct node* root)
{
    //initial space count as 0
    print2DUtil(root,0);
}

//Driver program to test above functions
int main()
{
    struct node * root=newnode(1);
    root->left=newnode(2);

    root->left->left=newnode(4);

    root->left->left->left=newnode(8);

    print2D(root);
    return 0;
}
