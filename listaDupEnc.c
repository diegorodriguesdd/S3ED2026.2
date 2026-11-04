#include <stdio.h>
#include <stdlib.h>

/*
* Listas duplamentente encadeadas
*  
*  Agora o nó aponta tanto para o proximo quanto para o anterior, logo a lista pode ser percorrida nos dois sentidos
* 
*/

struct no {
  int valor;
  struct no *ant;
  struct no *prox;
};

int inserirI(struct no **l, int valor){
  struct no *novo = malloc(sizeof(struct no));
  if(!novo) {
    printf("Nao foi possivel alocar memoria\n");
    return 0;
  }

  novo->valor = valor;
  novo->ant = NULL;
  novo->prox = *l;

  if(*l) (*l)->ant = novo;
  *l = novo;
  
  return 1;
}

int inserirF(struct no **l, int valor){
  struct no *novo = malloc(sizeof(struct no));
  if(!novo) {
    printf("Nao foi possivel alocar memoria\n");
    return 0;
  }

  novo->valor = valor;
  novo->prox = NULL;

  struct no *aux = *l;
  while(aux && aux->prox){
    aux = aux->prox;
  }

  if(!aux) *l = novo;
  else aux->prox = novo;
  novo->ant = aux;

  return 1;
}

int removerI(struct no **l){
  if(*l == NULL){
    printf("Nao ha elementos para remover");
    return 0;
  }

  struct no *aux = *l;

  *l = (*l)->prox;
  (*l)->ant = NULL;
  free(aux);
  return 1;
}

int remover(struct no **l, int valor){
  if(*l == NULL) {
    printf("Sem valores a remover");
    return 0;
  }

  struct no *aux = *l;
  while(aux && aux->valor != valor){
    aux = aux->prox;
  }
  if(aux->valor != valor){
    printf("Valor nao encontrado");
    return 1;
  }

  if(aux == *l){
    *l = aux->prox;
    aux->prox->ant = NULL;
  }
  if(aux->prox == NULL){
     aux->ant->prox = NULL;
  }
  if(aux->prox && aux->ant){
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant; 
  }
  free(aux);
  return 1;
}

int removerF(struct no **l){
  struct no *aux = *l;

  while(aux && aux->prox){
    aux = aux->prox;
  }

  aux->ant->prox = NULL;
  free(aux);
}

int mostrar(struct no *aux){
  printf("[ ");
  while(aux){
    printf("%d ", aux->valor);
    aux = aux->prox;
  }
  printf("]\n");
  return 1;
}

int mostrarR(struct no *aux){
  printf("[ ");
  while(aux && aux->prox){
    aux = aux->prox;
  } 
  while(aux){
    printf("%d ", aux->valor);
    aux = aux->ant;
  }
  printf("]\n");
  return 1;
}

int main(){
  struct no *lista = NULL;
  
  printf("\nInserindo Inicio\n");
  inserirF(&lista, 2);
  mostrar(lista);
  inserirI(&lista, 5);
  mostrar(lista);
  inserirI(&lista, 7);
  mostrar(lista);
  inserirI(&lista, 9);
  mostrar(lista);
 
  printf("\nInserindo Final\n");
  inserirF(&lista, 4);
  mostrar(lista);
  inserirF(&lista, 6);
  mostrar(lista);
  inserirF(&lista, 8);
  mostrar(lista);

  printf("\nRemovendo Inicio\n");
  removerI(&lista);
  mostrar(lista);
  removerI(&lista);
  mostrar(lista);
  removerI(&lista);
  mostrar(lista);

  printf("\nRemovendo especifico\n");
  remover(&lista, 2);
  mostrar(lista);
  remover(&lista, 6);
  mostrar(lista);


  printf("\nRemovendo ultimo \n");
  inserirF(&lista, 9);
  mostrar(lista);
  removerF(&lista);
  mostrar(lista);

  return 0;
}
