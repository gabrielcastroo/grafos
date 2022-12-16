#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int list_adj[100];
    int tam_lista_adj;
    int visitado;
}vertice;

void push(vertice* v, int a, int b);
void mostrar_lista_adj(vertice* v, int qtd_arestas);
void dfs(vertice* v, int raiz);

int main(void)
{
    int qtd_vertices, qtd_arestas;
    scanf("%d %d", &qtd_vertices, &qtd_arestas);
    vertice* vertices = (vertice*)calloc(qtd_vertices,sizeof(vertice));
    int i,x,y;
    for(i=0;i<qtd_arestas;i++){
        scanf("%d %d",&x,&y);
        push(vertices,x,y);
    }
    mostrar_lista_adj(vertices,qtd_arestas);
    printf("DFS: \n");
    dfs(vertices,1);
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
    v[b].list_adj[v[b].tam_lista_adj] = a;
    v[a].tam_lista_adj++;
    v[b].tam_lista_adj++;
}

void dfs(vertice* v, int raiz)
{
    if(v[raiz].visitado != 0)
    {
        return;
    }
    
    v[raiz].visitado = 1;
    printf("%d ",raiz);

    int i;
    for(i=0;i<v[raiz].tam_lista_adj;i++)
    {
        if(v[v[raiz].list_adj[i]].visitado == 0)
        {
            dfs(v,v[raiz].list_adj[i]);
        }
    }
}