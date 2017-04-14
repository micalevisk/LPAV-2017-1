/**
 * Exercício 1: Inversão de Listas Encadeadas
 * @author Micael Levi
 * @date 03/27/2017
 */

#include <cstdio>
#include <cstdlib>

struct tipoNo{
	int valor;
	tipoNo* prox;
	tipoNo(int _valor){ valor=_valor; prox=NULL; }
};

struct Lista{
	Lista(){ prim = NULL; }
	tipoNo* prim;
	void imprimir(void);
	void inserir(int);

	private:
		void imprimirAPartirDe(tipoNo*);
};

void Lista::imprimirAPartirDe(tipoNo* no){//impressão recursiva
	if(!no) return;
	printf("%d ",no->valor);
	imprimirAPartirDe(no->prox);
}

void Lista::imprimir(){ imprimirAPartirDe(prim); printf("\n"); }

void Lista::inserir(int val){//no final
	tipoNo *ultimo=prim, *novo = new tipoNo(val);
	if(!ultimo) prim = novo;
	else{
		while(ultimo->prox) ultimo=ultimo->prox;
		ultimo->prox = novo;
	}
}

void inserirEm(Lista& l, tipoNo* no){//inserção recursiva
	if(!no) return;
	inserirEm(l, no->prox);
	l.inserir(no->valor);
}

main()
{
	unsigned qtdElementos;

	while((scanf("%u", &qtdElementos)) && (qtdElementos > 0)){
		Lista l1, l2;
		do{
			--qtdElementos;
			int elemento; scanf("%d",&elemento);
			l1.inserir(elemento);
		}while(qtdElementos > 0);

		inserirEm(l2, l1.prim);
		l2.imprimir();

	}
}
