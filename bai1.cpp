#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct Node {
    int dinh;
    struct Node* tiep;
} Node;

Node* danhSachKe[MAX];
bool daTham[MAX];

Node* taoNut(int v) {
    Node* nutMoi = (Node*)malloc(sizeof(Node));
    nutMoi->dinh = v;
    nutMoi->tiep = NULL;
    return nutMoi;
}

void themCanh(int u, int v) {
    Node* nutMoi = taoNut(v);
    nutMoi->tiep = danhSachKe[u];
    danhSachKe[u] = nutMoi;
    nutMoi = taoNut(u);
    nutMoi->tiep = danhSachKe[v];
    danhSachKe[v] = nutMoi;
}

void DFS(int v) {
    daTham[v] = true;
    printf("%d ", v);

    Node* temp = danhSachKe[v];
    while (temp != NULL) {
        int dinhKe = temp->dinh;
        if (!daTham[dinhKe]) {
            DFS(dinhKe);
        }
        temp = temp->tiep;
    }
}

void BFS(int batDau) {
    int hangDoi[MAX], dau = 0, cuoi = 0;
    daTham[batDau] = true;
    hangDoi[cuoi++] = batDau;
    while (dau < cuoi) {
        int dinhHienTai = hangDoi[dau++];
        printf("%d ", dinhHienTai);

        Node* temp = danhSachKe[dinhHienTai];
        while (temp != NULL) {
            int dinhKe = temp->dinh;
            if (!daTham[dinhKe]) {
                daTham[dinhKe] = true;
                hangDoi[cuoi++] = dinhKe;
            }
            temp = temp->tiep;
        }
    }
}

int main() {
    int soDinh, soCanh;
    printf("Nhap so luong dinh: ");
    scanf("%d", &soDinh);
    printf("Nhap so luong canh: ");
    scanf("%d", &soCanh);
    
    for (int i = 0; i < soDinh; i++) {
        danhSachKe[i] = NULL;
    }
    printf("Nhap cac canh duoi dang cap dinh (u v):\n");
    for (int i = 0; i < soCanh; i++) {
        int u, v; 
        scanf("%d %d", &u, &v);
        themCanh(u, v);
    }
    printf("Nhap dinh bat dau cho DFS: ");
    int batDauDFS;
    scanf("%d", &batDauDFS);
    for (int i = 0; i < soDinh; i++) {
        daTham[i] = false;
    }
    
    printf("Duyet DFS: ");
    DFS(batDauDFS);
    printf("\n");
    printf("Nhap dinh bat dau cho BFS: ");
    int batDauBFS;
    scanf("%d", &batDauBFS);
    for (int i = 0; i < soDinh; i++) {
        daTham[i] = false;
    }
    
    printf("Duyet BFS: ");
    BFS(batDauBFS);
    printf("\n");
    return 0;
}
