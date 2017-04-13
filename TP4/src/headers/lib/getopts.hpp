//
//	[getopts.hpp]
//	Created by Micael Levi on 04/11/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef GETOPTS_HPP
#define GETOPTS_HPP



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

///dependencies
#include "extras.hpp"
#include "optionparser.h"
#include "arg.hpp"

//============================================================================//
struct Parameters {//lidos das opções (com valores default)
	///Quantidade de valores aletórios que serão gerados
	size_t qtdElementos;
	///Quantidade de casas que o tempo de execução terá
	unsigned short precisao;
	///A chave é a inicial (minúscula) do nome do algoritmo (ou 'a' de 'all') => booleano que indica se ele será executado
	unordered_map<char, bool> algoritmosUtilizados;

	Parameters() :
		qtdElementos(10)
		,precisao(2)
		,algoritmosUtilizados({{'a', true}, {'h', false}, {'i', false}, {'s', false}, {'m', false}, {'q', false}, {'b', false}}) {}
};
//============================================================================//

class GetOpts {
	static Parameters readOptions(option::Parser, vector<option::Option>&, vector<option::Option>&);
	public:
		static Parameters getParameters(int argc, char* argv[]);
};



Parameters GetOpts::readOptions(option::Parser parse, vector<option::Option>& options, vector<option::Option>& buffer){
	Parameters params;

	bool opcaoDesconhecida=false;///flag caso haja um (ou mais) opção inválida
	///Exibe as opções inválidas detectadas
	for(option::Option* opt=options[UNKNOWN]; opt; opt=opt->next()){
		cout << "Unknown Option '" << string(opt->name,opt->namelen) << "'" << '\n';
		opcaoDesconhecida=true;
	}
	if(opcaoDesconhecida) exit(2);

	///Leitura das opções & denifição dos parâmetros
	for(unsigned i=0; i < parse.optionsCount(); ++i){
		option::Option& opt = buffer[i];
		// fprintf(stdout, "Argument #%d is ", i);
		switch (opt.index()){
			case _VERBOSE://**
				// fprintf(stdout, "--verbose definido\n");
				break;

			case SIZE:
				// fprintf(stdout, "--size=<%d>\n", Arg::toInteger(opt.arg));
				params.qtdElementos = Arg::toInteger(opt.arg);
				break;

			case _PRECISION:
				// fprintf(stdout, "--precision=<%d>\n", Arg::toInteger(opt.arg));
				params.precisao = Arg::toInteger(opt.arg);
				break;

			case _DESCENDING://**
				// fprintf(stdout, "--descending definido\n");
				break;

			case TYPE://**
				// fprintf(stdout, "--type=<%s>\n", Arg::toString(opt.arg));
				break;

			case ALGORITHMS: {
				// fprintf(stdout, "--algorithms=[<%s>]\n", Arg::toString(opt.arg));
				vector<string> strAlgoritmos = Extras::splitString(opt.arg);
				params.algoritmosUtilizados.at('a') = false;
				for(auto s : strAlgoritmos) params.algoritmosUtilizados.at( tolower(s[0]) ) = true;
				break;
			}

			case UNKNOWN: break;
		}
	}

	return params;
}

Parameters GetOpts::getParameters(int argc, char* argv[]){
	//////////////////////[ INIT OPTIONPARSER ]//////////////////////
	argc-=(argc>0); argv+=(argc>0);///Skip program name
	option::Stats  stats(usage, argc, argv);
	vector<option::Option> options(stats.options_max);
	vector<option::Option> buffer(stats.buffer_max);
	option::Parser parse(usage, argc, argv, &options[0], &buffer[0]);
	/////////////////////////////////////////////////////////////////

	if(parse.error()) exit(1);
	if(options[HELP]){ option::printUsage(cout, usage); exit(1); }

	return GetOpts::readOptions(parse, options, buffer);
}



#endif
