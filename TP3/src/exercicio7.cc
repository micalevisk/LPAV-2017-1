/**
 * Exercício 7: Enxerto na ABB
 * @author Micael Levi
 * @date 05/04/2017
 */

#include <iostream>
using namespace std;

struct Node {
	int chave;
	Node *sae, *sad;
	Node(int _chave){ chave = _chave; sae = sad = NULL; }
};

class ABB {
	public:
		Node* raiz;

		ABB();
		void imprimir(void);
		void inserir(int);
		Node* buscar(int);
		void enxertar(Node*,int);

	private:
		void inserirEm(Node*,int);
		Node* buscarEm(Node*,int);
		void imprimirInfixada(Node*);
};

ABB::ABB(){ raiz = NULL; }
void ABB::inserirEm(Node* folha, int novaChave){
	if(novaChave < folha->chave){
		if(folha->sae) inserirEm(folha->sae, novaChave);
		else folha->sae = new Node(novaChave);
	}
	else{
		if(folha->sad) inserirEm(folha->sad, novaChave);
		else folha->sad = new Node(novaChave);
	}
}

Node* ABB::buscarEm(Node* folha, int chave){
	if(!folha) return NULL;
	if(chave < folha->chave) return buscarEm(folha->sae, chave);
	if(chave > folha->chave) return buscarEm(folha->sad, chave);
	return folha;
}

void ABB::imprimirInfixada(Node* folha){
	if(!folha) return;
	imprimirInfixada(folha->sae);
	cout << folha->chave << endl;
	imprimirInfixada(folha->sad);
}

void ABB::imprimir(){ imprimirInfixada(raiz); }
void ABB::inserir(int novaChave){
	if(raiz) return inserirEm(raiz, novaChave);
	raiz = new Node(novaChave);
}
Node* ABB::buscar(int chave){ return buscarEm(raiz, chave); }

void ABB::enxertar(Node* enxerto, int chave){
	Node* folha = buscar(chave);
	if(folha){
		if(chave < folha->chave) folha->sae = enxerto;
		else folha->sad = enxerto;
	}
}


main()
{
	ABB a1, a2;
	int num;

	while((cin >> num) && (num)) a1.inserir(num);
	while((cin >> num) && (num)) a2.inserir(num);

	cin >> num;
	a1.enxertar(a2.raiz, num);
	a1.imprimir();
}
