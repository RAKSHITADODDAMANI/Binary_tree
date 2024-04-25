#include <stdio.h>
#include <stdlib.h>
struct node
{
   struct node *left, *right;
   int key;
};
struct node *newNode(int item);
struct node *insert(struct node *node, int key);
void preorder(struct node *root);
int main()
{
     //system("cls");
     int i,n,data;
     struct node *root = NULL;
     printf("Enter number of elements\n");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
        printf("Enter the data\n");
        scanf("%d",&data);
        root = insert(root, data);
     }
     printf("\npre order traversal of given tree \n");
     preorder(root);
     return 0;
}
// create new BST tree
struct node *newNode(int item)
{
     struct node *temp = (struct node *)malloc(sizeof(struct node));
     temp->key = item;
     temp->left = temp->right = NULL;
     return temp;
}



void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}


struct node *insert(struct node *node, int key)
{
    if (node == NULL)
          return newNode(key);
    if (key < node->key)
         node->left = insert(node->left, key);
    else
         node->right = insert(node->right, key);
    return node;
}
