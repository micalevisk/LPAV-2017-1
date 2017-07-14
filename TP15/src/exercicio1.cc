/**
 * Exercício 1: Tabelas de Dispersão
 * @author Micael Levi
 * @date 14/07/2017
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;


//----------------------------------------------------------------------------------------//
struct Pessoa {
	bool existe;//gambs
	int matricula;
	string nome;

	Pessoa() : existe(false), matricula(0) {}
	int getChave(){ return matricula; }

	friend ostream& operator <<(ostream& out, const Pessoa& p){
		out << p.matricula << ' ' << p.nome;
		return out;
	}
	friend istream& operator >>(istream& in, Pessoa& p){
		in >> p.matricula >> p.nome;
		return in;
	}
};


template<class T> class TabelaHash {
	vector<T> tabela;
	unsigned tamanho;//quantidade de posições
	unsigned qtdChaves;//quantidade de elementos
	float alfa, limiteFatorCarga;

	unsigned hash(T dado){ return dado.getChave()%tamanho; }
	bool posicaoValida(unsigned i){ return (i < tamanho); }
	void atualizarAlfa(){ alfa = qtdChaves/(float)tamanho; }
	bool temElemento(unsigned pos){ return tabela[pos].existe; }
	void inserirSemComputar(T dado);

	public:
		TabelaHash(unsigned tamInicial, float percentualFatorCarga);
		void inserir(T dado);
		void mostrar();
		vector<T> getVector(){ return tabela; }
};
//----------------------------------------------------------------------------------------//


bool existe(TabelaHash<Pessoa> t, const int matricula){
	for(const Pessoa& p : t.getVector()){
		if(p.matricula == matricula) return true;
	}
	return false;
}

main()
{

	int tamanhoInicial, qtdChaves, qtdBuscas;// N, M, K
	unsigned percentualFatorCarga;// W

	//etapa 1
	cin >> tamanhoInicial >> qtdChaves >> percentualFatorCarga;
	TabelaHash<Pessoa> tabela = TabelaHash<Pessoa>(tamanhoInicial, percentualFatorCarga);

	//etapa 2
	while(qtdChaves-- > 0){
		Pessoa pessoaCurr; cin >> pessoaCurr;
		tabela.inserir(pessoaCurr);
	}

	tabela.mostrar();
	cout << endl;

	//etapa 3
	for(cin >> qtdBuscas; qtdBuscas > 0; --qtdBuscas){
		int matriculaCurr;
		cin >> matriculaCurr;

		if(existe(tabela, matriculaCurr)) cout << "SIM\n";
		else cout << "NAO\n";
	}

}



//========================================================================================//
template<class T> TabelaHash<T>::TabelaHash(unsigned tamInicial, float percentualFatorCarga)
	: tamanho(tamInicial), limiteFatorCarga(percentualFatorCarga/100.0), qtdChaves(0) {
	tabela.resize(tamInicial);
	atualizarAlfa();
}

template<class T> void TabelaHash<T>::inserirSemComputar(T dado){
	unsigned posInsercaoInicial;
	unsigned posInsercao;

	posInsercaoInicial = hash(dado);
	posInsercao = posInsercaoInicial;
	while( temElemento(posInsercao) ){//procurar a posição de inserção
		posInsercao = (posInsercao + 1) % tamanho;//incremento circular
		if(posInsercao == posInsercaoInicial) break;
	}

	tabela[posInsercao] = dado;
	tabela[posInsercao].existe = true;
}

template<class T> void TabelaHash<T>::inserir(T dado){
	inserirSemComputar(dado);
	qtdChaves++;//atualiza a quantidade de elementos
	atualizarAlfa();
	if(alfa < limiteFatorCarga) return;

	vector<T> tabelaAnterior; tabelaAnterior.swap(tabela);
	tamanho *= 2;
	tabela.resize(tamanho);

	for(const T dadoCurr : tabelaAnterior){
		if(dadoCurr.existe) inserirSemComputar(dadoCurr);
	}
}

template<class T> void TabelaHash<T>::mostrar(){
	cout << tamanho << endl;
	for(unsigned i=0; i < tamanho; ++i){
		cout << i << ' ';
		if(!temElemento(i)) cout << '\\';
		else cout << tabela[i];
		cout << endl;
	}
}
//========================================================================================//
