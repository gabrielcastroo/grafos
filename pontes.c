#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int listaadj[1000];
    int tamlistaadj;
    int in;
    int lower;
    int visitado;
}vertice;

int count;
void dfs(vertice* v, int raiz, int pai);
int min(int a, int b);
int main(void)
{
    int a,b,qtd_vertices, qtd_arestas;

    vertice* vertices = calloc(qtd_vertices,sizeof(vertice));
    scanf("%d %d",&qtd_vertices, &qtd_arestas);
    int i;
    for(i=0;i<qtd_arestas;i++)
    {
        scanf("%d %d",&a,&b);
        vertices[a].listaadj[vertices[a].tamlistaadj] = b;
        vertices[a].tamlistaadj++;
        vertices[b].listaadj[vertices[b].tamlistaadj] = a;
        vertices[b].tamlistaadj++;
    }
    dfs(vertices,1,1);
}

int min(int a, int b)
{ 
    if(a<b) return a;
    else return b;
}

void dfs(vertice* v, int raiz, int pai)
{
    int i,filho;
    v[raiz].visitado = 1;
    v[raiz].in = count;
    v[raiz].lower = count;
    count++;
    printf(" %d",raiz);
    for(i=0;i<v[raiz].tamlistaadj;i++)
    {
        filho = v[raiz].listaadj[i];
        if(filho == pai)
        {
            continue;
        }
        else
        {
            if(v[filho].visitado == 1)
            {
                printf("aresta de retorno: (%d,%d)\n",raiz,filho);
                v[raiz].lower = min(v[raiz].lower,v[filho].in);
            }
            else
            {
                dfs(v,filho,raiz);
                if(v[filho].lower > v[raiz].in)
                {
                    printf("arsta ponte: (%d,%d)\n",raiz,filho);
                }
                v[raiz].lower = min(v[raiz].lower,v[filho].lower);
            }
        }
    }
}