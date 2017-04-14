/**
 * Exercício 4: Filas para Simulação do Controle de Pista de Decolagem de Aviões
 * @author Micael Levi
 * @date 04/04/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{ int  id; char nome[4]; Node* next; };
struct Queue{ Node* first; Node* last; unsigned size; };
Queue* fila;
typedef void (* acaoNaFila)(Node*);
inline bool filaVazia(){ return !fila || !fila->size; }

/***************** DECLARAÇÃO DE FUNÇÕES *****************/
void commandHandler(char);
void iterarLeftRight(acaoNaFila);
void _acaoListarNomes(Node*);
void _acaoSair(Node*);
/*********************************************************/

void inicializarFila(){
	//cria a fila
	fila = (Queue*) malloc(sizeof(Queue));
	fila->first = fila->last = NULL;
	fila->size  = 0;
}

//Q (lista a quantidade de aviões aguardando na fila)
void quantidade(){ if(fila) printf("%u\n", fila->size); }

//L (lista os nomes de todos)
void listarNomes(){ iterarLeftRight(_acaoListarNomes); }

//D (remove o primeiro da fila)
void remover(){
	if(filaVazia()) return;
	Node* prim = fila->first;
	if(fila->last == prim) fila->last = NULL;
	fila->first = prim->next;
	fila->size--;
	free(prim);
}

//A <c> <n> (adicionar à fila, nome 'c' e id 'n')
void adicionar(){
	char* nome = (char*) malloc(sizeof(char)*4);
	int id;
	scanf("%s %d", nome, &id);

	Node* novoAviao = (Node*) malloc(sizeof(Node));
	novoAviao->id = id;
	strcpy(novoAviao->nome, nome);

	if(!fila->last) fila->first = fila->last = novoAviao;
	else{
		fila->last->next = novoAviao;
		fila->last = novoAviao;
	}

	fila->size++;
}

//P (imprime o nome do primeiro avião da fila)
void primeiro(){
	if(filaVazia()) return;
	Node* prim = fila->first;
	printf("%s %d\n", prim->nome, prim->id);
}

//S (limpa a fila e sai do programa)
void sair(){
	iterarLeftRight(_acaoSair);
	free(fila);
	exit(0);
}


main()
{
	inicializarFila();
	char cmd;
	while( scanf("%c", &cmd) )
		commandHandler(cmd);
}




/***************** FUNÇÕES AUXILIARES *****************/
void commandHandler(char command){
	switch(command){
		case 'Q': quantidade(); break;
		case 'L': listarNomes(); break;
		case 'P': primeiro(); break;
		case 'D': remover(); break;
		case 'A': adicionar(); break;
		case 'S': sair(); break;
	}
}


void iterarLeftRight(acaoNaFila fun){
	if(filaVazia()) return;
	Node* aux, *it = fila->first;
	while(it){
		aux = it->next;
		fun(it);
		it = aux;
	}
}

void _acaoListarNomes(Node* elem){
	if(elem) printf("%s %d\n", elem->nome, elem->id);
}

void _acaoSair(Node* elem){
	if(elem) free(elem);
}
