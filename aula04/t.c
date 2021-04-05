typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct pilha{
    struct elemento * topo;
}pilha;

void push(pilha * p, int num)
{
    elemento * novo;
    novo->valor = num;

    if(empty(p))
        p->topo = novo;
    else{
        novo->prox = p->topo;
        p->topo = novo;
    }
}

int stackpop(pilha * p)
{
    if(empty(p))
        return -1;
    else
        return p->topo->valor;
}

int pop(pilha * p)
{
    if(empty(p))
        return -1;
    else{
        int num;
        elemento * aux;

        aux = p->topo;
        num = p->topo->valor;

        p->topo = p->topo->prox;

        free(aux);
        return num;
    }
}


int empty(pilha * p)
{
    if(p->topo == NULL)
        return 1;
    else
        return 0;
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = (elemento*)calloc(1, sizeof(elemento));
    return novo;
}

pilha * aloca_pilha()
{
    pilha * nova;
    nova = (pilha*)calloc(1, sizeof(pilha));
    return nova;
}

