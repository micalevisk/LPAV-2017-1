/**
 * Exercício 5: Classe ABB
 * @author Micael Levi
 * @date 05/04/2017
 */

#include <iostream>
using namespace std;
#define END_OF_COMMAND cout << "###\n"

struct Node {
	int chave;
	Node *sae, *sad;
	Node(int _chave){ chave = _chave; sae = sad = NULL; }
};

class ABB {
	public:
		Node* raiz;

		ABB();
		~ABB();
		void imprimir(void);
		void inserir(int);
		Node* buscar(int);
		void enxertar(Node*,int);
		void podar(int);

	private:
		void destruir(Node*);
		void inserirEm(Node*,int);
		Node* buscarEm(Node*,int);
		void imprimirInfixada(Node*);
};

/******************** MÉTODOS ********************/
ABB::ABB(){ raiz = NULL; }
ABB::~ABB(){ destruir(raiz); }
void ABB::destruir(Node* folha){
	if(folha){
		destruir(folha->sae);
		destruir(folha->sad);
		delete folha;
	}
}
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
	if(folha) folha->sad = enxerto;
}

void ABB::podar(int chave){
	Node* folha = buscar(chave);
	if(folha) folha->sad = NULL;
}




main()
{
	ABB arvore1;
	int num;

	//[3] e [4]
	while((cin >> num) && (num)) arvore1.inserir(num);
	arvore1.imprimir();
	END_OF_COMMAND;

	//[5]
	while((cin >> num) && (num)){
		Node* folha = arvore1.buscar(num);
		if(folha) cout << "SIM\n";
		else cout << "NAO\n";
	}
	END_OF_COMMAND;

	//[6]
	ABB arvore2;
	while((cin >> num) && (num)) arvore2.inserir(num);

	//[7] e [8]
	cin >> num;
	arvore1.enxertar(arvore2.raiz, num);

	//[9]
	arvore1.imprimir();
	END_OF_COMMAND;

	//[10] e [11]
	cin >> num;
	arvore1.podar(num);

	//[12]
	arvore1.imprimir();
}

// https://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.html
