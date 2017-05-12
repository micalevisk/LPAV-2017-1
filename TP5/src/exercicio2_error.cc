/**
 * Exercício 2: Quebra-cabeça Binário
 * @author Micael Levi
 * @date 11/05/2017
 */

#include <iostream>
using namespace std;

#define ORDEM_MATRIZ 6

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
};

Matriz<short> tabuleiro = Matriz<short>(QTD_LINHAS, QTD_COLUNAS);
//----------------------------------------------------------------------------------------//



/**
 * LINHA
 * buscar pares (células iguais consecutivos) na linha dada
 * e definir as células das laterais
 */
void findPairsOnRow(unsigned i){
	for(unsigned j=0; j < QTD_COLUNAS; ++j){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr || *curr == CELULA_INDEFINIDA) continue;

		if( tabuleiro.celulasIguais(i,j , i,j+1) ){///PAR ENCONTRADO
			short valorInverso = !(*curr);
			tabuleiro.setElemento(i,j-1, valorInverso);
			tabuleiro.setElemento(i,j+2, valorInverso);
			j++;
		}
	}
}

/**
 * COLUNA
 * buscar pares (células iguais consecutivos) na coluna dada
 * e definir as células das laterais
 */
void findPairsOnColumn(unsigned j){
	for(unsigned i=0; i < QTD_LINHAS; ++i){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr || *curr == CELULA_INDEFINIDA) continue;

		if( tabuleiro.celulasIguais(i,j , i+1,j) ){///PAR ENCONTRADO
			short valorInverso = !(*curr);
			tabuleiro.setElemento(i-1,j, valorInverso);
			tabuleiro.setElemento(i+2,j, valorInverso);
			i++;
		}
	}
}


/**
 * LINHA
 * buscar "trios", i.e., pares que estão "separados" por
 * uma célula vazia
 */
void findTriosOnRow(unsigned i){
	for(unsigned j=0; j < QTD_COLUNAS; ++j){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr || *curr == CELULA_INDEFINIDA) continue;

		if( tabuleiro.celulasIguais(i,j , i,j+2) ){///TRIO ENCONTRADO (tipo X 2 X)
			short valorInverso = !(*curr);
			tabuleiro.setElemento(i,j+1, valorInverso);
			j++;
		}
	}
}

/**
 * COLUNA
 * buscar "trios", i.e., pares que estão "separados" por
 * uma célula vazia
 */
void findTriosOnColumn(unsigned j){
	for(unsigned i=0; i < QTD_LINHAS; ++i){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr || *curr == CELULA_INDEFINIDA) continue;

		if( tabuleiro.celulasIguais(i,j , i+2,j) ){///TRIO ENCONTRADO (tipo X 2 X)
			short valorInverso = !(*curr);
			tabuleiro.setElemento(i+1,j, valorInverso);
			i++;
		}
	}
}


/**
 * LINHA
 * conta a quantidade de 0/1 e caso algum tenha 3 ocorrências
 * procurar as células vazias na linha dada e preencher com o seu inverso
 */
void completeRow(unsigned i){
	unsigned ocorrencias[2] = {0 , 0};///[0] é a quantidade de 0s, [1] a quantidade de 1s
	///contar a quantidade de 0s e 1s na linha 'i'
	for(unsigned j=0; j < QTD_COLUNAS; ++j){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr || *curr == CELULA_INDEFINIDA) continue;
		ocorrencias[ *curr ]++;
	}

	for(short k=0; k < 2; ++k){
		unsigned qtd = ocorrencias[k];
		if(qtd == OCORRENCIA_MAX){
			// cout << "MAXIMO DE " << k << " NA LINHA " << i << endl;
			short valorInverso = !k;

			///alterar células indefinidas (buscar por "2" nessa linha)
			for(unsigned j=0; j < QTD_COLUNAS; ++j){
				short* curr = tabuleiro.getElemento(i,j);
				if(!curr) continue;///não deve ocorrer
				if(*curr == CELULA_INDEFINIDA) tabuleiro.setElemento(i,j, valorInverso);
			}

			break;
		}
	}
}

/**
 * COLUNA
 * conta a quantidade de 0/1 e caso algum tenha 3 ocorrências
 * procurar as células vazias na coluna dada e preencher com o seu inverso
 */
void completeColumn(unsigned j){
	unsigned ocorrencias[2] = {0 , 0};///[0] é a quantidade de 0s, [1] a quantidade de 1s
	///contar a quantidade de 0s e 1s na linha 'i'
	for(unsigned i=0; i < QTD_LINHAS; ++i){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr || *curr == CELULA_INDEFINIDA) continue;
		ocorrencias[ *curr ]++;
	}

	for(short k=0; k < 2; ++k){
		unsigned qtd = ocorrencias[k];
		if(qtd == OCORRENCIA_MAX){
			// cout << "MAXIMO DE " << k << " NA LINHA " << i << endl;
			short valorInverso = !k;

			///alterar células indefinidas (buscar por "2" nessa linha)
			for(unsigned i=0; i < QTD_LINHAS; ++i){
				short* curr = tabuleiro.getElemento(i,j);
				if(!curr) continue;///não deve ocorrer
				if(*curr == CELULA_INDEFINIDA) tabuleiro.setElemento(i,j, valorInverso);
			}

			break;
		}
	}
}


/* REGRAS:
{1} não deve ter 3 células consecutivas iguais
{2} não deve ter mais que 3 ocorrências de 0s e 1s
{3} linhas e colunas únicas
*/
bool regra1Valida_linha(unsigned i){
	for(unsigned j=0; j < QTD_COLUNAS; ++j){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr || *curr == CELULA_INDEFINIDA) continue;

		if( tabuleiro.celulasIguais(i,j , i,j+1) &&
			tabuleiro.celulasIguais(i,j , i,j+2) ) return false;
	}

	return true;
}

bool regra1Valida_coluna(unsigned j){
	for(unsigned i=0; i < QTD_LINHAS; ++i){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr || *curr == CELULA_INDEFINIDA) continue;
		if( tabuleiro.celulasIguais(i,j , i+1,j) &&
			tabuleiro.celulasIguais(i,j , i+2,j) ) return false;
	}

	return true;
}


bool ocorrenciasInvalida(unsigned* ocorrencias){ return ocorrencias[0] > OCORRENCIA_MAX || ocorrencias[1] > OCORRENCIA_MAX; }

bool regra2Valida_linha(unsigned i){
	unsigned ocorrencias[2] = {0,0};

	for(unsigned j=0; j < QTD_COLUNAS; ++j){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr || *curr == CELULA_INDEFINIDA) continue;

		ocorrencias[ *curr ]++;
		if( ocorrenciasInvalida(ocorrencias) ) return false;
	}

	return true;
}

bool regra2Valida_coluna(unsigned j){
	unsigned ocorrencias[2] = {0,0};

	for(unsigned i=0; i < QTD_LINHAS; ++i){
		short* curr = tabuleiro.getElemento(i,j);
		if(!curr || *curr == CELULA_INDEFINIDA) continue;

		ocorrencias[ *curr ]++;
		if( ocorrenciasInvalida(ocorrencias) ) return false;
	}

	return true;
}




bool regrasValidasPara(unsigned i, unsigned j){//admite coordenada (i,j) válida
	short curr = * tabuleiro.getElemento(i,j);

	///regra 1
	if( !regra1Valida_linha(i) || !regra1Valida_coluna(j) ) return false;

	///regra 2
	if( !regra2Valida_linha(i) || !regra2Valida_coluna(j) ) return false;

	///regra 3

	return true;
}

/**
 * A partir da linha 'i' e coluna 'j', buscar o primeiro '2'
 * Ao encontrá-lo, setar para 'valor'
 * Se houver quebra de alguma regra, retornar false, senão true
 */
bool freedomAtRow(unsigned i, unsigned j, short valor){
	if(i == QTD_LINHAS) return true;
	if(j == QTD_COLUNAS) return freedomAtRow(i+1, 0, valor);//vai pra próxima linha

	short* curr = tabuleiro.getElemento(i,j);
	if(!curr) return true;///não deve ocorrer

	if(*curr == CELULA_INDEFINIDA){
		tabuleiro.setElemento(i,j, valor);
		if( !regrasValidasPara(i,j) )
			tabuleiro.setElemento(i,j, !valor);
			if( !regrasValidasPara(i,j) ) return false;
	}

	return freedomAtRow(i,j+1, valor);
}






//##################################################################################//
main()
{
	tabuleiro.lerValoresFormatados();


	{///PROCESSO QUE PREENCHE ALGUMAS CÉLULAS USANDO MACETES VÁLIDOS
		for(unsigned i=0; i < QTD_LINHAS; ++i)  findPairsOnRow(i);
		for(unsigned j=0; j < QTD_COLUNAS; ++j) findPairsOnColumn(j);

		for(unsigned i=0; i < QTD_LINHAS; ++i)  findTriosOnRow(i);
		for(unsigned j=0; j < QTD_COLUNAS; ++j) findTriosOnColumn(j);

		for(unsigned i=0; i < QTD_LINHAS; ++i)  completeRow(i);
		for(unsigned j=0; j < QTD_COLUNAS; ++j) completeColumn(j);
	}


	freedomAtRow(0,0, 0);


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
