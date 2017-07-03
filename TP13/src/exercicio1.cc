/**
 * Exercício 1: Jogo Sudoku
 * @author Micael Levi
 * @date 01/07/2017
 */

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



//{REGRA 1 & 2} 'val' não está presente na 'linha' ou na 'coluna'
//---------------------------------------------------------------//
bool linhaOuColunaValidaParaValor(const unsigned val, unsigned linha, unsigned coluna,
                                  const unsigned incrLinha, const unsigned incrColuna)
{
	unsigned curr;
	return
		!tabuleiro.posicaoValida(linha, coluna)
	|| (
			(	(curr = * tabuleiro.getElemento(linha, coluna)) || true )
			&&	(curr != val)
			&& linhaOuColunaValidaParaValor(val, linha+incrLinha, coluna+incrColuna, incrLinha, incrColuna)
		);
}
//---------------------------------------------------------------//

//{REGRA 3} 'val' não está presente no seu quadrante 3x3
//-------------------------------------------------------//
CoordenadasPlus getPosicaoNaGrade(const unsigned i, const unsigned j){
	unsigned colunaMod3=(j+1)%3, linhaMod3=(i+1)%3;
	CoordenadasPlus cords;

	//borda lateral esquerda
	if(colunaMod3 == 1) cords.setColuna(j,j+2);
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

bool gradeValidaParaValor(const unsigned val, const unsigned i, const unsigned j){
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


bool regrasValidasPara(const unsigned val, const unsigned i, const unsigned j)
{
	return
		tabuleiro.posicaoValida(i, j)
	&&	linhaOuColunaValidaParaValor(val, i, 0, 0, 1)//linha
	&&	linhaOuColunaValidaParaValor(val, 0, j, 1, 0)//coluna
	&&	gradeValidaParaValor(val, i,j);
}

bool validarEDefinir(const unsigned val, const unsigned i, const unsigned j){
	return (regrasValidasPara(val, i,j) && tabuleiro.setElemento(val, i,j));
}


bool freedomAtRow(const unsigned i, const unsigned j)
{
	return (i == tabuleiro.qtdLinhas)
	||(
		(j == tabuleiro.qtdColunas) ? freedomAtRow(i+1,0)
		:	!tabuleiro.celulaIgualA(0, i,j) ? freedomAtRow(i,j+1)
		:	(validarEDefinir(1, i,j) && freedomAtRow(i,j+1))
		||	(validarEDefinir(2, i,j) && freedomAtRow(i,j+1))
		||	(validarEDefinir(3, i,j) && freedomAtRow(i,j+1))
		||	(validarEDefinir(4, i,j) && freedomAtRow(i,j+1))
		||	(validarEDefinir(5, i,j) && freedomAtRow(i,j+1))
		||	(validarEDefinir(6, i,j) && freedomAtRow(i,j+1))
		||	(validarEDefinir(7, i,j) && freedomAtRow(i,j+1))
		||	(validarEDefinir(8, i,j) && freedomAtRow(i,j+1))
		||	(validarEDefinir(9, i,j) && freedomAtRow(i,j+1))
		|| !tabuleiro.setElemento(0, i,j)
	);
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
	return (posicaoValida(i,j) && ((matriz[i][j] = newValue) || true));
}

template<class T> T* Matriz<T>::getElemento(unsigned i, unsigned j){
	return posicaoValida(i,j) ? &matriz[i][j] : NULL;
}

template<class T> bool Matriz<T>::celulaIgualA(const T value, unsigned i, unsigned j){
	return posicaoValida(i,j) && (matriz[i][j] == value);
}
