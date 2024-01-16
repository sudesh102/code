// C function to search a given key in a given BST

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    else
        return search(root->left, key);
}

struct node *minval(struct node *root)
{
    struct node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

struct node *maxval(struct node *root)
{
    struct node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

struct node *delete(struct node *root, int val)
{
    //^ best case
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        //^ 0 child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        //^ 1 child
        //* left child
        if (root->left != NULL && root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        //* right part
        if (root->left == NULL && root->right != NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        //^ 2 child
        if (root->left != NULL && root->right != NULL)
        {
            // struct node *temp = root->left;
            int mini = minval(root->right)->data;
            root->data = mini;
            root->right = delete (root->right, mini);
            return root;
        }
    }

    else if (root->data > val)
    {
        //& going into left part
        root->left = delete (root->left, val);
        return root;
    }
    else
    {
        //& going into right part
        root->right = delete (root->right, val);
        return root;
    }
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct node *root = NULL;
    int choice, key;

    do
    {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            if (search(root, key) == NULL)
                printf("%d not found\n", key);
            else
                printf("%d found\n", key);
            break;
        case 3:
            printf("Enter the value to delete: ");
            scanf("%d", &key);
            root = delete (root, key);
            break;
        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 6:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 7:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 7);

    return 0;
}