#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void inicializa_matriz(int** m, int size);
void mostra_matriz(int** m, int size);
int** aloca_matriz(int m, int n);
void preenche_matriz(int** m, int a, int b);

int main(void)
{
    int a,b,x,y,aux;
    int n_arestas;

    scanf("%d",&n_arestas);

    int** matriz_adj = aloca_matriz(n_arestas,n_arestas);

    inicializa_matriz(matriz_adj,n_arestas);

    for(aux=0; aux<n_arestas; aux++)
    {
        scanf("%d %d",&x,&y);
        preenche_matriz(matriz_adj,x,y);

    }
    mostra_matriz(matriz_adj,n_arestas);

    return 0;
}
int** aloca_matriz(int m, int n)
{
    int** matriz_adj = malloc(sizeof(*matriz_adj)*n);
    int i;
    for(i=0;i<m;i++){
        matriz_adj[i] = malloc(sizeof(*matriz_adj[i]));
    }

    return matriz_adj;
}
void inicializa_matriz(int** m, int size)
{
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++)
            m[i][j] = 0;
    }
}

void mostra_matriz(int** m, int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }   
}

void preenche_matriz(int** m, int a, int b){
    m[a][b] = 1;
    // m[b][a] = 1;
}