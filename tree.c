#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

Node *buildTree(int root, int data[], int leftChild[], int rightChild[])
{
    if(root == -1)
    {
        return NULL;
    }
    Node * newNode = malloc(sizeof(Node));
    newNode->value = data[root];
    newNode->left  = buildTree(leftChild[root], data, leftChild, rightChild);
    newNode->right = buildTree(rightChild[root], data, leftChild, rightChild);
    return newNode;
}

void printTreePreOrder(Node* root)
{
    if(root == NULL) {
        return;
    }

    printf("Value: %d\n", root->value);
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}

void printTreeInOrder(Node* root)
{
    if(root == NULL) {
        return;
    }

    printTreeInOrder(root->left);
    printf("Value: %d\n", root->value);
    printTreeInOrder(root->right);
}

void printTreePosOrder(Node* root)
{
    if(root == NULL) {
        return;
    }

    printTreePosOrder(root->left);
    printTreePosOrder(root->right);
    printf("Value: %d\n", root->value);
}

int main()
{
    int data[]          = { 12, 4, 10, 2, 18, 7, 21, 5 };
    int leftChilds[]    = { 5, 7, 3, -1, 0, -1, -1, -1 };
    int rightChilds[]   = { 1, -1, 6, -1, 2, -1, -1, -1 };

    Node *root = buildTree(4, data, leftChilds, rightChilds);
    printTreePreOrder(root);
    printf("\n");
    printTreeInOrder(root);
    printf("\n");
    printTreePosOrder(root);

    return 0;
}