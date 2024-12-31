#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

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

int adjacencyList[MAX][MAX];

void convertTreeToGraph(Node* root, int adjacencyList[MAX][MAX], int size) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL) {
        adjacencyList[root->data][root->left->data] = 1;
        adjacencyList[root->left->data][root->data] = 1;
        convertTreeToGraph(root->left, adjacencyList, size);
    }
    if (root->right != NULL) {
        adjacencyList[root->data][root->right->data] = 1;
        adjacencyList[root->right->data][root->data] = 1;
        convertTreeToGraph(root->right, adjacencyList, size);
    }
}

void DFS(int start, int visited[], int size) {
    printf("%d ", start);
    visited[start] = 1;
    for (int i = 0; i < size; i++) {
        if (adjacencyList[start][i] && !visited[i]) {
            DFS(i, visited, size);
        }
    }
}

void BFS(int start, int visited[], int size) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < size; i++) {
            if (adjacencyList[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
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

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adjacencyList[i][j] = 0;
        }
    }

    convertTreeToGraph(root, adjacencyList, MAX);

    int visited[MAX] = {0};
    printf("Duyet do thi bang DFS: ");
    DFS(root->data, visited, MAX);
    printf("\n");

    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }

    printf("Duyet do thi bang BFS: ");
    BFS(root->data, visited, MAX);
    printf("\n");

    return 0;
}
