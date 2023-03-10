#include <stdio.h>
#include <stdlib.h>

// Node structure of a Binary Search Tree
typedef struct node {
    int data;
    int priority;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insert(Node* root, int data, int priority) {
    if (root == NULL) {
        return createNode(data, priority);
    }

    if (priority < root->priority) {
        root->left = insert(root->left, data, priority);
    }
    else {
        root->right = insert(root->right, data, priority);
    }

    return root;
}

// Function to find the node with the highest priority
Node* findMaxPriority(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete the node with the highest priority
Node* deleteMaxPriority(Node* root) {
    if (root->left == NULL) {
        Node* temp = root->right;
        free(root);
        return temp;
    }
    root->left = deleteMaxPriority(root->left);
    return root;
}

// Function to print the elements in the BST in in-order traversal
void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("(%d, %d) ", root->data, root->priority);
        printInOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 10, 1);
    root = insert(root, 20, 2);
    root = insert(root, 30, 4);
    root = insert(root, 40, 5);
    root = insert(root, 50, 1);

    printf("Priority Queue: ");
    printInOrder(root);

    Node* maxPriorityNode = findMaxPriority(root);
    printf("\n\nElement with highest priority: (%d, %d)\n", maxPriorityNode->data, maxPriorityNode->priority);

    root = deleteMaxPriority(root);
    printf("\nPriority Queue after deleting element with highest priority:\n ");
    printInOrder(root);

    return 0;
}




