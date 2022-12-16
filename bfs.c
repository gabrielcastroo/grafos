#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int list_adj[100];
    int tam_lista_adj;
    int visitado;
}vertice;

typedef struct elemento
{
    int valor;
    struct elemento* prox;
}elemento;

typedef struct fila
{
    int tam_fila;
    elemento* inicio;
    elemento* fim;
}fila;

void push_g(vertice* v, int a, int b);
void mostrar_lista_adj(vertice* v, int qtd_arestas);
void push(fila* f, int valor);
int pop(fila* f);
int is_empty(fila* f);
void bfs(vertice* vertices, int raiz);

int main(void)
{
    int qtd_vertices, qtd_arestas;
    scanf("%d %d", &qtd_vertices, &qtd_arestas);
    vertice* vertices = (vertice*)calloc(qtd_vertices,sizeof(vertice));
    int i,x,y;
    for(i=0;i<qtd_arestas;i++){
        scanf("%d %d",&x,&y);
        push_g(vertices,x,y);
    }
    mostrar_lista_adj(vertices,qtd_arestas);
    printf("\nBFS: \n");
    bfs(vertices,1);
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

void push_g(vertice* v, int a, int b)
{
    v[a].list_adj[v[a].tam_lista_adj] = b;
    v[b].list_adj[v[b].tam_lista_adj] = a;
    v[a].tam_lista_adj++;
    v[b].tam_lista_adj++;
}

void push(fila* f, int valor)
{
    elemento* novo = calloc(1,sizeof(elemento));
    novo->valor = valor;
    if(f->tam_fila == 0)
    {
        f->inicio = novo;
        f->fim = novo;
        f->tam_fila++;
    }
    else
    {
        novo->valor = valor;
        f->fim->prox = novo;
        f->fim = novo;
        f->tam_fila++;
    }
}

int is_empty(fila* f)
{
    if(f->tam_fila<=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop(fila* f)
{
    int res;
    if(f->tam_fila == 0)
    {
        return -1;
    }
    elemento* aux;
    res = f->inicio->valor;
    aux = f->inicio;
    f->inicio = f->inicio->prox;
    free(aux);
    f->tam_fila--;
    return res;
}

void bfs(vertice* vertices, int raiz)
{
    fila* f;
    f = calloc(1,sizeof(fila));
    int i,current;
    push(f,raiz);

    while(!is_empty(f))
    {
        current = pop(f);
        if(vertices[current].visitado == 0)
        {
            printf("%d ",current);
        }
        vertices[current].visitado = 1;
    
        for(i=0;i<vertices[current].tam_lista_adj;i++)
        {
            if(vertices[vertices[current].list_adj[i]].visitado == 0){
                push(f,vertices[current].list_adj[i]);
            }
        }
    }
}
