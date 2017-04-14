/**
 * Exercício 2: Professor ligado!
 * @author Micael Levi
 * @date 03/18/2017
 */

#include <bits/stdc++.h> // LIBS: iostream, string, vector, utility
using namespace std;

//struct Aluno {	string nome, assinatura; };
typedef pair<string,string> Aluno;// nome,assinatura

unsigned contarDiferencas(string a, string b){
	unsigned qtdDiferencas = 0;
	//admite que a e b possuem a mesma quantidade de caracteres
	for(string::size_type i=0; i < a.size(); ++i)
		qtdDiferencas += (a[i] - b[i] != 0);
	return qtdDiferencas;
}

unsigned buscarEContar(vector<Aluno> v, Aluno a){
	for(unsigned i=0; i<v.size(); ++i)
		if(!v[i].first.compare(a.first))//encontrou o aluno
			return contarDiferencas(v[i].second, a.second);
		/*
	for(vector<Aluno>::iterator it=v.begin(); it!=v.end(); ++it)
		if(!it->nome.compare(a.nome))//encontrou o aluno
			return contarDiferencas(it->assinatura,a.assinatura);
		*/
	return 0;
}

// ======================= MAIN ======================= //
main ()
{
	int qtdAlunos, qtdAssinaturas;// N e M, respectivamente
	vector<Aluno> originais;

	while((cin >> qtdAlunos) && (qtdAlunos > 0)){// início do caso de teste
		do{
			Aluno corrente;
			//cin >> corrente.nome >> corrente.assinatura;
			cin >> corrente.first >> corrente.second;
			originais.push_back(corrente);

			--qtdAlunos;
		}while(qtdAlunos > 0);

		unsigned qtdErros = 0;
		cin >> qtdAssinaturas;
		do{
			Aluno aluno;
			cin >> aluno.first >> aluno.second;
			qtdErros += buscarEContar(originais, aluno) > 1;

			--qtdAssinaturas;
		}while(qtdAssinaturas > 0);

		cout << qtdErros << endl;
		originais.clear();
	}
}
