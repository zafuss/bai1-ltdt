#include<stdio.h>
#define MAX 10
#define inputfile "D:/code/lythuyetdothi/bai1/text.txt"

typedef struct graph
{
    int n;
    int a[MAX][MAX];
}DoThi;

int readMatrix(char fileName[100], graph &g) {
    FILE *f;
    f = fopen(fileName, "rt");
    if (f == NULL) {
        printf("Khong mo duoc file\n");
        return 0;
    }
    fscanf(f, "%d", &g.n);
    int i, j;
    for ( i = 0; i < g.n; i++)
    {
        for (j = 0; j < g.n; j++)
        {
            fscanf(f, "%d", &g.a[i][j]);
        }
        
    }
    fclose(f);
    return 1;
    
}

void displayMatrix(graph g) {
    printf("So dinh cua do thi: %d\n", g.n);
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
            printf("%d\t", g.a[i][j]);
        }
        printf("\n");
    }
}

void findConnectedVertex(graph g, int label[MAX], int i) {
    for (int j = 0; j < g.n; j++) {
        if (g.a[i][j] != 0 && label[j] != label[i]) {
            label[j] = label[i];
            findConnectedVertex(g, label, j);
        }
    }
}

void examineConnected(graph g) {
    int label[MAX];
    for (int i = 0; i < g.n; i++)
        label[i] = 0;
    int soTP = 0;
    for (int i = 0; i < g.n; i++) {
        if (label[i] == 0) {
            soTP++;
            label[i] = soTP;
            findConnectedVertex(g, label, i);
        }
    }
    printf("So thanh phan lien thong la %d\n", soTP);
    for (int i = 1; i <= soTP; i++) {
        printf("Thanh phan lien thong thu %d gom cac dinh: ", i);
        for(int j = 1; j <= g.n; j++){
            if(label[j] == i)
                printf("%3d", j);

        }
    }
}

int main() {
    graph g;
    if (readMatrix(inputfile, g) == 1) {
        displayMatrix(g);
        examineConnected(g);
    }

    return 0;
}

