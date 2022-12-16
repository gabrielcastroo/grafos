#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int list_adj[100];
    int tam_lista_adj;
}vertice;

void push(vertice* v, int a, int b);
void mostrar_lista_adj(vertice* v, int qtd_arestas);

int main(void)
{
    int qtd_vertices, qtd_arestas;
    scanf("%d %d", &qtd_vertices, &qtd_arestas);
    vertice* vertices = (vertice*)malloc(sizeof(vertice)*qtd_vertices);
    int i,x,y;
    for(i=0;i<qtd_arestas;i++){
        scanf("%d %d",&x,&y);
        push(vertices,x,y);
    }
    mostrar_lista_adj(vertices,qtd_arestas);
    return 0;
}

void mostrar_lista_adj(vertice* v, int qtd_arestas)
{
    int i,j;
    for(i=0;i<qtd_arestas;i++)
    {
        printf("vertice %d: ",i);
        for(j=0;j<v[i].tam_lista_adj;j++){
            printf("%d ",v[i].list_adj[j]);
        }
        printf("\n");
    }
}

void push(vertice* v, int a, int b)
{
    v[a].list_adj[v[a].tam_lista_adj] = b;
    //v[b].list_adj[v[b].tam_lista_adj] = a;
    v[a].tam_lista_adj++;
    //v[b].tam_lista_adj++;
}