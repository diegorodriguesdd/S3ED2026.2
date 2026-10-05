#include <stdio.h>
#include <stdlib.h>

struct no {
	int valor;
	struct no *prox;
};

int remover(struct no **f){
	if(*f == NULL){
		printf("Nao ha elementos a serem removidos!\n)");
		return 0;
	}

	struct no *aux = *f;
	*f = (*f)->prox;
	free(aux);
	return 1;
}

int inserir(struct no **f, int valor){
	struct no *novo = (struct no *) malloc(sizeof(struct no));
	
	if(!novo){
		printf("Erro ao alocar memoria!\n");
		return 0;
	}

	novo->valor = valor;
	novo->prox = NULL;

	struct no *aux = *f;
	while(aux && aux->prox){
		aux = aux->prox;
	}

	if(!aux) {
		*f = novo;
	}
	else {
		aux->prox = novo;
	}

	return 1;
}

void mostrar(struct no *aux){
	printf("[ ");
	while(aux){
		printf("%d ", aux->valor);
		aux = aux->prox;
	}
	printf("]\n");
}

int main(){
	struct no *fila = NULL;
	inserir(&fila, 2);
	mostrar(fila);
	inserir(&fila, 5);
	mostrar(fila);
	inserir(&fila, 8);
	mostrar(fila);

	remover(&fila);
	mostrar(fila);
	remover(&fila);
	mostrar(fila);
	remover(&fila);
	mostrar(fila);
	remover(&fila);

	return 0;
}
