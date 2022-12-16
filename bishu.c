#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int list_adj[100];
    int tam_lista_adj;
    int visitado;
    int distancia;
}vertice;

void push(vertice* v, int a, int b);
void mostrar_lista_adj(vertice* v, int qtd_arestas);
void dfs(vertice* v, int raiz, int distancia);

int main(void)
{
    int qtd_vertices, qtd_arestas, qtd_garotas;
    int vgarotas[100];
    scanf("%d", &qtd_vertices);
    qtd_arestas = qtd_vertices-1;
    vertice* vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));
    int i,x,y;
    for(i=0;i<qtd_arestas;i++){
        scanf("%d %d",&x,&y);
        push(vertices,x,y);
    }
    // printf("DFS: \n");
    dfs(vertices,1,0);
    // mostrar_lista_adj(vertices,qtd_vertices);
    scanf("%d",&qtd_garotas);

    for(i=0;i<qtd_garotas;i++){
        scanf("%d",&vgarotas[i]);
    }

    int id=vgarotas[0];
    for(int i=1;i<qtd_garotas;i++)
    {
        if(vertices[vgarotas[i]].distancia < vertices[id].distancia){
            id = vgarotas[i];
        }
        if(vertices[vgarotas[i]].distancia == vertices[id].distancia){
            if(vgarotas[i] < id){
                id = vgarotas[i];
            }
        }
    }
    printf("%d\n", id);
    return 0;
}

void mostrar_lista_adj(vertice* v, int qtd_arestas)
{
    int i,j;
    printf("\n");
    for(i=1;i<=qtd_arestas;i++)
    {
        printf("vertice %d: ",i);
        for(j=0;j<v[i].tam_lista_adj;j++){
            printf("%d ",v[i].list_adj[j]);
        }
        printf(" distancia: %d\n",v[i].distancia);
    }
}

void push(vertice* v, int a, int b)
{
    v[a].list_adj[v[a].tam_lista_adj] = b;
    v[b].list_adj[v[b].tam_lista_adj] = a;
    v[a].tam_lista_adj++;
    v[b].tam_lista_adj++;
}

void dfs(vertice* v, int raiz, int distancia)
{
    if(v[raiz].visitado != 0)
    {
        return;
    }
    
    v[raiz].visitado = 1;
    v[raiz].distancia = distancia;
    //printf("%d ",raiz);

    int i;
    for(i=0;i<v[raiz].tam_lista_adj;i++)
    {
        if(v[v[raiz].list_adj[i]].visitado == 0)
        {
            dfs(v,v[raiz].list_adj[i],distancia+1);
        }
    }
}