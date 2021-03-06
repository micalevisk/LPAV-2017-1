/**
 * Exercício 2: Quebra-cabeça Binário
 * @author Micael Levi
 * @date 18/05/2017
 */

#include <iostream>
#include <vector>
using namespace std;

#ifndef ORDEM_MATRIZ
	#define ORDEM_MATRIZ 6
#endif

#define OCORRENCIA_MAX ORDEM_MATRIZ/2
#define QTD_LINHAS     ORDEM_MATRIZ
#define QTD_COLUNAS    ORDEM_MATRIZ

#define CELULA_DEFINIDA_1 1
#define CELULA_DEFINIDA_0 0
#define CELULA_INDEFINIDA 2


//----------------------------------------------------------------------------------------//
template<class T> class Matriz {
	unsigned qtdLinhas, qtdColunas;
	T** matriz;

	bool naoEstaAlocado(){return (matriz == NULL) || (!qtdLinhas) || (!qtdColunas);}
	bool posicaoValida(unsigned i, unsigned j){return (i < qtdLinhas) && (j < qtdColunas);}

	public:
		Matriz(unsigned l, unsigned c);
		~Matriz();
		void lerValoresFormatados();
		void imprimirValores();
		void setElemento(unsigned i, unsigned j, const T newValue);
		T* getElemento(unsigned i, unsigned j);
		bool celulasIguais(unsigned ai, unsigned aj, unsigned bi, unsigned bj);
		vector<unsigned> getLinhasComecamCom(T x, unsigned exceto);
		vector<unsigned> getColunasComecamCom(T x, unsigned exceto);
};

Matriz<short> tabuleiro = Matriz<short>(QTD_LINHAS, QTD_COLUNAS);
//----------------------------------------------------------------------------------------//



//{REGRA 1} não deve ter 3 células consecutivas iguais
//-------------------------------------------------------//
bool regra1Valida_linha(unsigned i){
	for(unsigned j=0; j < QTD_COLUNAS; ++j){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr || *curr == CELULA_INDEFINIDA) continue;

		if( tabuleiro.celulasIguais(i,j , i,j+1)
		&&  tabuleiro.celulasIguais(i,j , i,j+2) )
			return false;
	}

	return true;
}
bool regra1Valida_coluna(unsigned j){
	for(unsigned i=0; i < QTD_LINHAS; ++i){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr || *curr == CELULA_INDEFINIDA) continue;

		if( tabuleiro.celulasIguais(i,j , i+1,j)
		&&  tabuleiro.celulasIguais(i,j , i+2,j) ){
			return false;
		}
	}

	return true;
}
//-------------------------------------------------------//


//{REGRA 2} não deve ter mais que 3 ocorrências de 0s e 1s
//-------------------------------------------------------//
bool regra2Valida_linha(unsigned i){
	unsigned ocorrencias[2] = {0,0};

	for(unsigned j=0; j < QTD_COLUNAS; ++j){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr || *curr == CELULA_INDEFINIDA) continue;

		ocorrencias[ *curr ]++;
		if(ocorrencias[ *curr ] > OCORRENCIA_MAX) return false;
	}

	return true;
}
bool regra2Valida_coluna(unsigned j){
	unsigned ocorrencias[2] = {0,0};

	for(unsigned i=0; i < QTD_LINHAS; ++i){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr || *curr == CELULA_INDEFINIDA) continue;

		ocorrencias[ *curr ]++;
		if(ocorrencias[ *curr ] > OCORRENCIA_MAX) return false;
	}

	return true;
}
//-------------------------------------------------------//


//{REGRA 3} linhas e colunas únicas
//-------------------------------------------------------//
bool linhaRepetidaComInicial(short valor, unsigned i){
	vector<unsigned> linhas = tabuleiro.getLinhasComecamCom(valor,i);
	for(const unsigned linha : linhas){
		unsigned j=0;
		do{
			if( !tabuleiro.celulasIguais(i,j , linha,j) ) break;
			++j;
		}while(j < QTD_COLUNAS);
		if(j==QTD_COLUNAS) return true;
	}
	return false;
}
bool colunaRepetidaComInicial(short valor, unsigned j){
	vector<unsigned> colunas = tabuleiro.getColunasComecamCom(valor,j);
	for(const unsigned coluna : colunas){
		unsigned i=0;
		do{
			if( !tabuleiro.celulasIguais(i,j , i,coluna) ) break;
			++i;
		}while(i < QTD_LINHAS);
		if(i==QTD_LINHAS) return true;
	}
	return false;
}

bool linhaCompleta(unsigned i){
	for(unsigned j=0; j < QTD_COLUNAS; ++j){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr) continue;
		if(*curr == CELULA_INDEFINIDA) return false;
	}
	return true;
}
bool colunaCompleta(unsigned j){
	for(unsigned i=0; i < QTD_LINHAS; ++i){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr) continue;
		if(*curr == CELULA_INDEFINIDA) return false;
	}
	return true;
}

bool regra3Valida_linha(unsigned i){
	return !linhaCompleta(i)
	||    (!linhaRepetidaComInicial(0,i) && !linhaRepetidaComInicial(1,i));
}
bool regra3Valida_coluna(unsigned j){
	return !colunaCompleta(j)
	||    (!colunaRepetidaComInicial(0,j) && !colunaRepetidaComInicial(1,j));
}
//-------------------------------------------------------//



bool regrasValidasPara(unsigned i, unsigned j){
	return
		   regra1Valida_linha(i) && regra1Valida_coluna(j)///regra 1
		&& regra2Valida_linha(i) && regra2Valida_coluna(j)///regra 2
		&& regra3Valida_linha(i) && regra3Valida_coluna(j)///regra 3
	;
}


bool definirEValidar(unsigned i, unsigned j, short value){
	tabuleiro.setElemento(i,j, value);
	return regrasValidasPara(i,j);
}

bool freedomAtRow(unsigned i, unsigned j){
	if(i == QTD_LINHAS) return true;///fim
	if(j == QTD_COLUNAS) return freedomAtRow(i+1, 0);///próxima linha

	short* curr = tabuleiro.getElemento(i,j);
	if(!curr) return true;///não deve ocorrer
	if(*curr != CELULA_INDEFINIDA) return freedomAtRow(i,j+1);///chamar próxima

	if( (definirEValidar(i,j, 0) && freedomAtRow(i,j+1))///tentando com 0
	||  (definirEValidar(i,j, 1) && freedomAtRow(i,j+1))///falhou com 0, tenta com 1
	) return true;

	tabuleiro.setElemento(i,j, CELULA_INDEFINIDA);///falhou, apaga a célula
	return false;
}



//##################################################################################//
main()
{
	tabuleiro.lerValoresFormatados();

	freedomAtRow(0,0);

	tabuleiro.imprimirValores();
}



//========================================================================================//
template<class T> Matriz<T>::Matriz(unsigned l, unsigned c) : qtdLinhas(l), qtdColunas(c) {
	if(!qtdLinhas) return;
	matriz = new (nothrow) T*[qtdLinhas];
	if(matriz == NULL)
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
			cout << matriz[i][j] << ' ';
		cout << '\n';
	}
}

template<class T> void Matriz<T>::setElemento(unsigned i, unsigned j, const T newValue){
	if(posicaoValida(i,j))
		matriz[i][j] = newValue;
}

template<class T> T* Matriz<T>::getElemento(unsigned i, unsigned j){
	return posicaoValida(i,j) ? &matriz[i][j] : NULL;
}

template<class T> bool Matriz<T>::celulasIguais(unsigned ai, unsigned aj, unsigned bi, unsigned bj){
	T* A = getElemento(ai,aj);
	T* B = getElemento(bi,bj);
	return (A && B) && (*A == *B);
}

template<class T> vector<unsigned> Matriz<T>::getLinhasComecamCom(T x, unsigned exceto){
	vector<unsigned> linhas;
	for(unsigned i=0; i < qtdLinhas; ++i){
		T* curr = getElemento(i,0);
		if(!curr || i==exceto) continue;
		if(*curr == x) linhas.push_back(i);
	}
	return linhas;
}

template<class T> vector<unsigned> Matriz<T>::getColunasComecamCom(T x, unsigned exceto){
	vector<unsigned> colunas;
	for(unsigned j=0; j < qtdColunas; ++j){
		T* curr = getElemento(0,j);
		if(!curr || j==exceto) continue;
		if(*curr == x) colunas.push_back(j);
	}
	return colunas;
}
