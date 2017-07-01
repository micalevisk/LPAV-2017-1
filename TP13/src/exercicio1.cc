/**
 * Exercício 1: Jogo Sudoku
 * @author Micael Levi
 * @date 01/07/2017
 */

/******************************
Preencher todas as células sem:
- repetir números numa mesma linha
- repetir números numa mesa coluna
- repetir números numa mesma grade 3x3
******************************/

#include <iostream>
#include <cstdio>
using namespace std;

//----------------------------------------------------------------------------------------//
template<class T> class Matriz {
	T** matriz;
	bool naoEstaAlocado(){return (matriz == NULL) || (!qtdLinhas) || (!qtdColunas);}

	public:
		unsigned qtdLinhas, qtdColunas;
		Matriz(unsigned l, unsigned c);
		~Matriz();
		bool posicaoValida(unsigned i, unsigned j){return (i < qtdLinhas) && (j < qtdColunas);}
		void lerValoresFormatados();
		void imprimirValores();
		bool setElemento(const T newValue, unsigned i, unsigned j);
		T* getElemento(unsigned i, unsigned j);
		bool celulaIgualA(const T value, unsigned i, unsigned j);
};


class CoordenadasPlus {
	struct ParLimites {
		unsigned min, max;
		ParLimites(unsigned _min, unsigned _max) : min(_min) , max(_max) {}
	};

	public:
		ParLimites linha, coluna;
		CoordenadasPlus() : linha(0,0) , coluna(0,0) {}
		void setLinha(unsigned mi, unsigned ma) { linha.min=mi;  linha.max=ma;  }
		void setColuna(unsigned mi, unsigned ma){ coluna.min=mi; coluna.max=ma; }
};

Matriz<unsigned> tabuleiro = Matriz<unsigned>(9, 9);
//----------------------------------------------------------------------------------------//


//{REGRA 1} 'val' não está presente na 'linha'
//-------------------------------------------------------//
bool linhaValidaParaValor(unsigned val, unsigned linha){
	for(unsigned j=0; j < tabuleiro.qtdColunas; ++j){
		unsigned curr = * tabuleiro.getElemento(linha,j);
		if(curr == val) return false;
	}
	return true;
}
//-------------------------------------------------------//

//{REGRA 2} 'val' não está presente na 'coluna'
//-------------------------------------------------------//
bool colunaValidaParaValor(unsigned val, unsigned coluna){
	for(unsigned i=0; i < tabuleiro.qtdLinhas; ++i){
		unsigned curr = * tabuleiro.getElemento(i,coluna);
		if(curr == val) return false;
	}
	return true;
}
//-------------------------------------------------------//

//{REGRA 3} 'val' não está presente no seu quadrante 3x3
//-------------------------------------------------------//
CoordenadasPlus getPosicaoNaGrade(unsigned i, unsigned j){
	unsigned colunaMod3=(j+1)%3, linhaMod3=(i+1)%3;
	CoordenadasPlus cords;

	//borda lateral esquerda
	if(colunaMod3 == 1)	cords.setColuna(j,j+2);
	//centro
	else if(colunaMod3 == 2) cords.setColuna(j-1,j+1);
	//borda lateral direita
	else cords.setColuna(j-2,j);

	//superior
	if(linhaMod3 == 1) cords.setLinha(i,i+2);
	//meio
	else if(linhaMod3 == 2) cords.setLinha(i-1,i+1);
	//inferior
	else cords.setLinha(i-2,i);

	return cords;
}

bool gradeValidaParaValor(unsigned val, unsigned i, unsigned j){
	CoordenadasPlus cords = getPosicaoNaGrade(i,j);

	for(unsigned linhaCurr = cords.linha.min; linhaCurr <= cords.linha.max; ++linhaCurr){
		for(unsigned colunaCurr = cords.coluna.min; colunaCurr <= cords.coluna.max; ++colunaCurr){
			unsigned valCurr = * tabuleiro.getElemento(linhaCurr, colunaCurr);//coordenadas sempre válidas
			if(valCurr == val) return false;
		}
	}
	return true;
}
//-------------------------------------------------------//

bool celulaVazia(unsigned i, unsigned j){
	unsigned* valptr = tabuleiro.getElemento(i,j);
	if(!valptr) return false;
	return (*valptr == 0);
}

bool regrasValidasPara(unsigned val, unsigned i, unsigned j){
	return
		tabuleiro.posicaoValida(i, j)
	&&	linhaValidaParaValor(val, i)
	&&	colunaValidaParaValor(val, j)
	&&	gradeValidaParaValor(val, i,j);
}

bool validarEDefinir(unsigned val, const unsigned i, const unsigned j){
	return (regrasValidasPara(val, i,j) && tabuleiro.setElemento(val, i,j));
}


bool freedomAtRow(const unsigned i, const unsigned j){
	if(i == tabuleiro.qtdLinhas) return true;//fim
	if(j == tabuleiro.qtdColunas) return freedomAtRow(i+1, 0);//próxima linha
	if(!tabuleiro.celulaIgualA(0, i,j)) return freedomAtRow(i,j+1);//chamar próxima

	if( (validarEDefinir(1, i,j) && freedomAtRow(i,j+1))
	||  (validarEDefinir(2, i,j) && freedomAtRow(i,j+1))
	||  (validarEDefinir(3, i,j) && freedomAtRow(i,j+1))
	||  (validarEDefinir(4, i,j) && freedomAtRow(i,j+1))
	||  (validarEDefinir(5, i,j) && freedomAtRow(i,j+1))
	||  (validarEDefinir(6, i,j) && freedomAtRow(i,j+1))
	||  (validarEDefinir(7, i,j) && freedomAtRow(i,j+1))
	||  (validarEDefinir(8, i,j) && freedomAtRow(i,j+1))
	||  (validarEDefinir(9, i,j) && freedomAtRow(i,j+1))
	) return true;

	tabuleiro.setElemento(0, i,j);//apagar a célula
	return false;
}


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

template<class T> bool Matriz<T>::setElemento(const T newValue, unsigned i, unsigned j){
	return (posicaoValida(i,j) && (matriz[i][j] = newValue));
}

template<class T> T* Matriz<T>::getElemento(unsigned i, unsigned j){
	return posicaoValida(i,j) ? &matriz[i][j] : NULL;
}

template<class T> bool Matriz<T>::celulaIgualA(const T value, unsigned i, unsigned j){
	return posicaoValida(i,j) ? (matriz[i][j] == value) : false;
}
