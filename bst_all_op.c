#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
struct node {
    int data;
    struct node* left, *right;
};

// Function to create a new node with the given data
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node with the given key
struct node* insert(struct node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

// Function to search for a key in the BST
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return search(root->right, key);
    
    return search(root->left, key);
}

// Function to find the minimum value node in a BST
struct node* minval(struct node* root) {
    struct node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

// Function to find the maximum value node in a BST
struct node* maxval(struct node* root) {
    struct node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

// Function to delete a node with the given value from the BST
struct node* delete(struct node* root, int val) {
    if (root == NULL) {
        return root;
    }

    if (root->data == val) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        if (root->left != NULL && root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        if (root->left == NULL && root->right != NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->left != NULL && root->right != NULL) {
            struct node* temp = root->left;
            int mini = minval(root->right)->data;
            root->data = mini;
            root->right = delete(root->right, mini);
            return root;
        }
    }
    else if (root->data > val) {
        root->left = delete(root->left, val);
        return root;
    }
    else {
        root->right = delete(root->right, val);
        return root;
    }
}

// Function to calculate the height of the BST
int height(struct node* root) {
    if (root == NULL)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Function to count the number of elements in the BST
int countElements(struct node* root) {
    if (root == NULL)
        return 0;

    return 1 + countElements(root->left) + countElements(root->right);
}

// Function to count the number of leaf nodes in the BST
int countLeaves(struct node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

// Function to count the number of non-leaf nodes in the BST
int countNonLeaves(struct node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;

    return 1 + countNonLeaves(root->left) + countNonLeaves(root->right);
}

// Function to perform range search in the BST
void rangeSearch(struct node* root, int low, int high) {
    if (root == NULL)
        return;

    if (root->data >= low && root->data <= high) {
        printf("%d ", root->data);
    }

    if (root->data > low)
        rangeSearch(root->left, low, high);

    if (root->data < high)
        rangeSearch(root->right, low, high);
}

// Function to perform in-order traversal of the BST
void inorder(struct node* root) {
    if (root == NULL) 
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node* root = NULL;
    int choice, key, low, high;

    do {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Inorder Traversal\n5. Height of Tree\n6. Count Elements\n7. Count Leaves\n8. Count Non-Leaves\n9. Range Search\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                root = delete(root, key);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Height of Tree: %d\n", height(root));
                break;
            case 6:
                printf("Number of Elements: %d\n", countElements(root));
                break;
            case 7:
                printf("Number of Leaves: %d\n", countLeaves(root));
                break;
            case 8:
                printf("Number of Non-Leaves: %d\n", countNonLeaves(root));
                break;
            case 9:
                printf("Enter the range (low high): ");
                scanf("%d %d", &low, &high);
                printf("Range Search: ");
                rangeSearch(root, low, high);
                printf("\n");
                break;
            case 10:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 10);

    return 0;
}