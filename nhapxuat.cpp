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

int checkValidMatrix(graph g) {
    for (int i = 0; i < g.n; i++) {
        if (g.a[i][i] != 0)
            return 0;
    }
    return 1;
}

int checkGraphDirection(graph g) {
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++)
            if (g.a[i][j] != g.a[j][i])
                return 0;
    }
    return 1;
}



int main() {
    graph g;
    if (readMatrix(inputfile, g) == 1) {
        displayMatrix(g);
        printf("Bam phim bat ki de kiem tra do thi\n");
        getchar();
        if (checkValidMatrix(g))
            printf("Do thi hop le!\n");
        else
            printf("Do thi khong hop le\n");
        if (checkGraphDirection(g)) 
            printf("Do thi vo huong\n");
        else
            printf("Do thi co huong\n");
    }
    getchar();
    return 0;
}

