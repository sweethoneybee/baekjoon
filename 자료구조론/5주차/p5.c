#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* r_fp;
FILE* w_fp;

typedef struct Node* NodePtr;
typedef struct Node
{
    int value;
    NodePtr left, right;
}Node;

NodePtr insertNode(int value, NodePtr* root);
NodePtr deleteNode(int value, NodePtr root);
NodePtr findNode(int value, NodePtr root);
NodePtr findMaxNode(NodePtr root);
void printInorder(NodePtr root);
void printPreorder(NodePtr root);
void printPostorder(NodePtr root);
void inorder(NodePtr root);
void preorder(NodePtr root);
void postorder(NodePtr root);

int main(void)
{
    r_fp = fopen("input.txt", "r");
    w_fp = fopen("output.txt", "w");

    char oper[3];
    int value;
    NodePtr root = NULL;
    while(fscanf(r_fp, "%s", oper) != EOF)
    {
        // print tree
        if(oper[0] == 'p')
        {
            if(oper[1] == 'i') 
            {
                printInorder(root);
            }
            else if(oper[1] == 'r')
            {
                printPreorder(root);
            } 
            else if(oper[1] == 'o') 
            {
                printPostorder(root);
            }
            continue;
        }

        // operation
        fscanf(r_fp, "%d\n", &value);
        if(oper[0] == 'i')
        {
            insertNode(value, &root);
        }
        if(oper[0] == 'd')
        {
            deleteNode(value, root);
        }
        if(oper[0] == 'f')
        {
            findNode(value, root);
        }
    }
    system("pause");
    return 0;
}

NodePtr insertNode(int value, NodePtr* root)
{ 
    if((*root) == NULL)
    {
        (*root) = (Node*)malloc(sizeof(Node));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->value = value;
    }
    else if((*root)->value > value)
    {
        (*root)->left = insertNode(value, &((*root)->left));
    }
    else if((*root)->value < value)
    {
        (*root)->right = insertNode(value, &((*root)->right));
    }
    else if((*root)->value == value)
    {
        printf("%d is already exists.\n", value);
        fprintf(w_fp, "%d is already exists.\n", value);
    }
    return (*root);
}
NodePtr deleteNode(int value, NodePtr root)
{
    NodePtr temp = NULL;

    if(root == NULL)
    {
        printf("Deletion failed. %d does not exist.\n", value);
        fprintf(w_fp, "Deletion failed. %d does not exist.\n", value);
    }
    else if(root->value > value)
    {
        root->left = deleteNode(value, root->left);
    }
    else if(root->value < value)
    {
        root->right = deleteNode(value, root->right);
    }
    else if(root->left != NULL && root->right != NULL) // has two childs
    {
        temp = findMaxNode(root->left);
        root->value = temp->value;
        root->left = deleteNode(root->value, root->left);
    }
    else // 1 or 0 child
    {
        temp = root;
        if(root->left == NULL)
        {
            root = root->right;
        }    
        else if(root->right == NULL)
        {
            root = root->left;
        }
        free(temp);
    }
    return root;
}
NodePtr findNode(int value, NodePtr root)
{
    if(root == NULL)
    {
        printf("%d is not in the tree.\n", value);
        fprintf(w_fp, "%d is not in the tree.\n", value);
        return root;
    }
    else if(root->value == value)
    {
        printf("%d is in the tree.\n", value);
        fprintf(w_fp, "%d is in the tree.\n", value);
        return root;
    }
    else if(root->value < value)
    {
        return findNode(value, root->right);
    }
    else if(root->value > value)
    {
        return findNode(value, root->left);
    }
}
NodePtr findMaxNode(NodePtr root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->right == NULL)
    {
        return root;
    }
    else
    {
        return findMaxNode(root->right);
    }
}
void printInorder(NodePtr root)
{
    printf("pi - ");
    fprintf(w_fp, "pi - ");
    inorder(root);
    printf("\n");
    fprintf(w_fp, "\n");
}
void printPreorder(NodePtr root)
{
    printf("pr - ");
    fprintf(w_fp, "pr - ");
    preorder(root);
    printf("\n");
    fprintf(w_fp, "\n");
}
void printPostorder(NodePtr root)
{
    printf("po - ");
    fprintf(w_fp, "po - ");
    postorder(root);
    printf("\n");
    fprintf(w_fp, "\n");
}
void inorder(NodePtr root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->value);
        fprintf(w_fp, "%d ", root->value);
        inorder(root->right);
    }
}
void preorder(NodePtr root)
{
    if(root != NULL)
    {
        printf("%d ", root->value);
        fprintf(w_fp, "%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(NodePtr root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
        fprintf(w_fp, "%d ", root->value);
    }
}