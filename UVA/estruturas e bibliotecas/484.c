#include <stdlib.h>
#include <stdio.h>

typedef struct Bst bst;

struct Bst{
    int key, num;
    bst *l, *r;
};

bst *init(){    return NULL;}

bst *cria(int key){
    bst *b = malloc(sizeof(bst));
    b->key = key;
    b->num = 1;
    b->l = b->r = init();
    return b;
}

bst *insere(bst *b, int key){
    if (b == NULL)  return cria(key);
    if (key == b->key)   {b->num++; return b;}
    if (key < b->key)   b->l = insere(b->l, key);
    if (key > b->key)   b->r = insere(b->r, key);
    return b;
}

void in_order(bst *b){
    if (b == NULL)  return;
    in_order(b->l);
    printf("%d %d\n", b->key, b->num);
    in_order(b->r)
}


double main(){
    int n;
    bst *b = init();
    while(scanf("%d", &n) ! EOF){
        b = insere(b, n)
    }
    in_order(b);
    return
}
