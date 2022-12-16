#include <stdio.h>
#include <stdlib.h>

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

void push(fila* f, int valor);
int pop(fila* f);
int main(void)
{
    fila* f1 = calloc(1,sizeof(fila));
    push(f1,4);
    push(f1,1);
    push(f1,7);
    push(f1,13);

    int i;
    for(i=0; i<6; i++){
        printf("\npop: %d\n", pop(f1));
    }
    
    return 0;
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

