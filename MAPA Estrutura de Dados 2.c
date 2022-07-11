#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define E 0
#define D 1
#define R -1

typedef struct NO {
	int dado;
	struct NO *esquerda;
	struct NO *direita;
	struct NO *pai;
} NO;

typedef struct ARVORE{
	NO *raiz;
}ARVORE;

ARVORE a;

void inicializaArvore(ARVORE arv);
void inicializaNo(NO* n, int val);
void insereNoArvoreOrdenada(int valor);
void preOrdem(NO* raiz);


void inicializaArvore(ARVORE arv)
{
	arv.raiz = NULL;
}

void inicializaNo(NO* n, int val){
	if(!n)
	{
		printf("Falha de alocacao.\n");
		return;
	}
	n->esquerda = NULL;
	n->direita = NULL;
	n->pai = NULL;
	n->dado = val;
}

void arvoreOrdenada(int valor) 
{
	NO* corrente = a.raiz;
	NO* pai;

	NO* novoNo = (NO*) malloc(sizeof(NO));
	inicializaNo(novoNo, valor);
	printf("Inserindo nó %d: \n", novoNo->dado);
	
	if(corrente == NULL)
	{
		a.raiz = novoNo;
		printf("Nó Raiz. \n");
		return;
	}
	
	while(corrente){
		pai = corrente;
		if(novoNo->dado < corrente->dado){
			corrente = corrente->esquerda;
			if(!corrente){
				printf("À esquerda do nó %d. \n", pai->dado);
				pai->esquerda = novoNo;
				return;
			}
		}
		else{
			corrente = corrente->direita;
			if(!corrente){
				printf("À direita do nó %d. \n", pai->dado);
				pai->direita = novoNo;
				return;
			}
		}
	}
}


void preOrdem(NO* raiz){
	if(raiz){
		printf("%d \t", raiz->dado);
		preOrdem(raiz->esquerda);
		preOrdem(raiz->direita);
	}
}


int main()
{
	setlocale(LC_ALL, "Portuguese");
	inicializaArvore(a);
	
	arvoreOrdenada(2);
	arvoreOrdenada(1);
	arvoreOrdenada(0);
	arvoreOrdenada(4);
	arvoreOrdenada(5);
	arvoreOrdenada(0);
	arvoreOrdenada(6);
	arvoreOrdenada(5);
	
	
	printf("\n Visitação pré-ordem: 21045065: \n\n\n");
	preOrdem(a.raiz);
	

}
