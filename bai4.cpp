#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
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

Node* createBinaryTree(int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        insert(&root, i + 1); 
    }
    return root;
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

void createGraph(int n, int edges[][2], int edgeCount) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adjacencyList[i][j] = 0;
        }
    }
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjacencyList[u][v] = 1;
        adjacencyList[v][u] = 1;
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
    int n;
    printf("Nhap so luong nut trong cay: ");
    scanf("%d", &n);

    Node* root = createBinaryTree(n);

    printf("Duyet cay theo thu tu truoc (pre-order): ");
    preOrder(root);
    printf("\n");

    printf("Duyet cay theo thu tu giua (in-order): ");
    inOrder(root);
    printf("\n");

    printf("Duyet cay theo thu tu sau (post-order): ");
    postOrder(root);
    printf("\n");

    int edges[][2] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    int edgeCount = 6;
    createGraph(n, edges, edgeCount);

    int visited[MAX] = {0};
    printf("Duyet do thi bang DFS: ");
    DFS(0, visited, n);
    printf("\n");

    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }

    printf("Duyet do thi bang BFS: ");
    BFS(0, visited, n);
    printf("\n");

    return 0;
}
