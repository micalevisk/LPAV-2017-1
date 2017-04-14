/**
 * Exercício 3: Operações com Pilhas
 * @author Micael Levi
 * @date 04/04/2017
 */

#include <stdio.h>
#include <stdlib.h>

struct Node{ int value; Node* below; };
struct Stack{ Node* top; };
Stack* pilha;
typedef void (* acaoNaPilha)(Node*);
inline bool pilhaVazia(){ return !pilha || !pilha->top; }

/***************** DECLARAÇÃO DE FUNÇÕES *****************/
void commandHandler(char);
void iterarTopDown(acaoNaPilha);
bool _desempilhar(bool mostrar);
void _acaoMostrar(Node*);
void _acaoSair(Node*);
/*********************************************************/

void inicializarPilha(){
	//cria a pilha
	pilha = (Stack*) malloc(sizeof(Stack));
	pilha->top=NULL;
}

//E <n> empilha o inteiro n
void empilhar(){
	int val;
	if( scanf("%d", &val) ){
		Node* novoElemento = (Node*) malloc(sizeof(Node));
		novoElemento->value = val;
		novoElemento->below = pilha->top;
		pilha->top = novoElemento;
	}
}

//D desempilhar topo e imprimir seu valor
bool desempilhar(){ return _desempilhar(true); }

//L apaga todos os dados da pilha (desempilhar tudo mas sem mostrar)
void limpar(){ while( _desempilhar(false) ); }

//M mostrar valores empilhados mas sem desempilhar (iterar sobre a pilha)
void mostrar(){ iterarTopDown(_acaoMostrar); }

//S liberar memória utilizada pela pilha e fechar programa
void sair(){ iterarTopDown(_acaoSair); free(pilha); exit(0); }


main()
{
	inicializarPilha();
	char cmd;
	while( scanf("%c", &cmd) )
		commandHandler(cmd);
}




/***************** FUNÇÕES AUXILIARES *****************/
void commandHandler(char command){
	switch(command){
		case 'E': empilhar(); break;
		case 'D': desempilhar(); break;
		case 'L': limpar(); break;
		case 'M': mostrar(); break;
		case 'S': sair(); break;
	}
}

void iterarTopDown(acaoNaPilha fun){
	if(pilhaVazia()) return;
	Node* it = pilha->top, *aux;
	while(it){
		aux = it->below;
		fun(it);
		it = aux;
	}
}

bool _desempilhar(bool mostrar){
	if(pilhaVazia()) return false;

	Node* topo = pilha->top;
	pilha->top = topo->below;
	int valorTopo = topo->value;
	if(mostrar) printf("%d\n", valorTopo);
	free(topo);
	return true;
}

void _acaoMostrar(Node* elem){
	if(elem)	printf("%d\n",elem->value);
}

void _acaoSair(Node* elem){
	if(elem) free(elem);
}
/*********************************************************/
