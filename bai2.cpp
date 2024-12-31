#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        return;
    }

    if (value < (*root)->data) {
        insert(&((*root)->left), value);
    } else {
        insert(&((*root)->right), value);
    }
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = NULL;
    int n;

    printf("Nhap so luong nut trong cay: ");
    scanf("%d", &n);

    printf("Nhap cac gia tri: ");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insert(&root, value);
    }

    printf("Duyet cay theo thu tu truoc (pre-order): ");
    preOrder(root);
    printf("\n");

    printf("Duyet cay theo thu tu giua (in-order): ");
    inOrder(root);
    printf("\n");

    printf("Duyet cay theo thu tu sau (post-order): ");
    postOrder(root);
    printf("\n");

    return 0;
}
