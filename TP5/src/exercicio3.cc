/**
 * Exercício 3: (Minha) Batalha Naval
 * @author Micael Levi
 * @date 09/05/2017
 */


#include <iostream>
using namespace std;

#define PARTE_NAVIO '#'
#define AGUA        '.'
#define ATINGIDO    '*'
#define VISITADO    '-'

//----------------------------------------------------------------------------------------//
template<class T> class Matriz {
	unsigned qtdLinhas, qtdColunas;
	T** matriz;

	bool naoEstaAlocado(){return (matriz == nullptr) || (!qtdLinhas) || (!qtdColunas);}
	bool posicaoValida(unsigned i, unsigned j){return (i < qtdLinhas) && (j < qtdColunas);}
	public:
		Matriz(unsigned l, unsigned c);
		~Matriz();
		void lerValoresFormatados();
		void imprimirValores();
		void setElemento(unsigned i, unsigned j, const T newValue);
		T* getElemento(unsigned i, unsigned j);
};
//----------------------------------------------------------------------------------------//

bool navioDestruido(Matriz<char>& tabuleiro, unsigned i, unsigned j){
	char* valor = tabuleiro.getElemento(i,j);
	if(!valor || *valor == AGUA || *valor == VISITADO) return true;
	if(*valor == PARTE_NAVIO) return false;

	tabuleiro.setElemento(i,j,VISITADO);
	if(
		navioDestruido(tabuleiro, i-1, j) && // N
		navioDestruido(tabuleiro, i+1, j) && // S
		navioDestruido(tabuleiro, i, j+1) && // L
		navioDestruido(tabuleiro, i, j-1)    // O
	)
		return true;

	tabuleiro.setElemento(i,j,ATINGIDO);
	return false;
}


main()
{
	unsigned N, M, K;///número de linhas e colunas do tabuleiro e quantidade de disparos;
	unsigned qtdNaviosDestruidos=0;

	cin >> N >> M;

	Matriz<char> tabuleiro = Matriz<char>(N,M);
	tabuleiro.lerValoresFormatados();

	for(cin >> K; K > 0; --K){
		unsigned L, C; cin >> L >> C;///(L,C) indica linha e coluna do disparo (1-indexado)
		--L; --C;///normalizar para a matriz

		char valor = * tabuleiro.getElemento(L, C);
		if(valor == PARTE_NAVIO){
			tabuleiro.setElemento(L, C, ATINGIDO);
			if( navioDestruido(tabuleiro, L, C) ) qtdNaviosDestruidos++;
		}
	}

	cout << qtdNaviosDestruidos << endl;
}




//========================================================================================//
template<class T> Matriz<T>::Matriz(unsigned l, unsigned c) : qtdLinhas(l), qtdColunas(c) {
	if(!qtdLinhas) return;
	matriz = new (nothrow) T*[qtdLinhas];
	if(matriz == nullptr)
		cout << "ERRO AO ALOCAR\n";
	else
		for(unsigned i=0; i<qtdLinhas; ++i) matriz[i] = new T[qtdColunas];
}

template<class T> Matriz<T>::~Matriz(){
	if(naoEstaAlocado()) return;
	for(unsigned i=0; i < qtdLinhas; ++i) delete [] matriz[i];
	delete [] matriz;
	matriz = NULL;
}

template<class T> void Matriz<T>::lerValoresFormatados(){
	if(naoEstaAlocado()) return;
	for(unsigned i=0; i < qtdLinhas; ++i)
		for(unsigned j=0; j < qtdColunas; ++j)
			cin >> matriz[i][j];
}

template<class T> void Matriz<T>::imprimirValores(){
	if(naoEstaAlocado()) return;
	for(unsigned i=0; i < qtdLinhas; ++i){
		for(unsigned j=0; j < qtdColunas; ++j)
			cout << matriz[i][j];
		cout << '\n';
	}
}

template<class T> void Matriz<T>::setElemento(unsigned i, unsigned j, const T newValue){
	if(!posicaoValida(i,j)) return;
	matriz[i][j] = newValue;
}

template<class T> T* Matriz<T>::getElemento(unsigned i, unsigned j){
	return posicaoValida(i,j) ? &matriz[i][j] : nullptr;
}
