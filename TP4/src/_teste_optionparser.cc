/*
g++ std=c++11 _teste_optionparser.cc -I ./headers -I ./headers/lib  && ./a --help
./a --verbose --decrescente -t=int -s102 -p3 --algoritmos='bubble,selection'
*/

/*******************************************************************************
λ ./a --verbose --decrescente --tipo=int --size=123 --precisao=4 --algoritmos='bubble, selection, insertion, heap, merge, quick'
Argument #0 is --verbose definido
Argument #1 is --decrescente definido
Argument #2 is --tipo=<int>
Argument #3 is --size=<123>
Argument #4 is --precisao=<4>
Argument #5 is --algortimos=[<bubble, selection, insertion, heap, merge, quick>]
bubble-selection-insertion-heap-merge-quick-
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

///dependencies
#include "optionparser.h"
#include "arg.hpp"
#include "stringparser.hpp"

using namespace std;



enum  optionIndex { UNKNOWN, HELP, VERBOSE, PRECISAO, DECRESCENTE, TIPO, SIZE, ALGORITMOS };
const option::Descriptor usage[] = {
	{UNKNOWN, 0, "", "",option::Arg::None, "USAGE: example [OPTIONS]\n\n"
															"OPTIONS:" },
	{VERBOSE,      0,"","verbose", option::Arg::None,		"  --verbose*  \tMostra o estado dos arrays (default: false)." },
	{HELP,         0,"h","help",   option::Arg::None,		"  -h, --help   \tPrint usage and exit." },
	{DECRESCENTE,  0,"","decrescente", option::Arg::None,	"  --decrescente*  \tOrdena em ordem decrescente." },
	{TIPO,         0,"t","tipo",   Arg::Required,			"  -t <T>,--tipo=<T>*  \tTipo dos valores gerados (default: int)." },
	{SIZE,         0,"s","size",   Arg::Numeric,  			"  -s <S>,--size=<S>   \tDefine o tamanho da instância gerada (default: 10)." },
	{PRECISAO,     0,"p","precisao",Arg::Numeric,			"  -p <P>,--precisao=<P>*  \tNúmero de casas do tempo de execução (default: 2)." },
	{ALGORITMOS,   0,"","algoritmos",Arg::Required,			"  --algoritmos=ALG   \tAlgoritmos que serão executados (default: all)." },

	{UNKNOWN, 0, "", "",option::Arg::None, "\nALG:\n  bubble selection insertion heap merge quick\n" },
	{UNKNOWN, 0, "", "",option::Arg::None, "Examples:\n"
	"  example --verbose --tipo float -s5 -p0 --algortimos quick,insertion \n"
	"  example --decrescente -t=int --algoritmos 'heap,selection'\n" },
	{0,0,0,0,0,0}
};



int main(int argc, char* argv[])
{
	argc-=(argc>0); argv+=(argc>0); // skip program name argv[0] if present
	option::Stats  stats(usage, argc, argv);
	vector<option::Option> options(stats.options_max);
	vector<option::Option> buffer(stats.buffer_max);
	option::Parser parse(usage, argc, argv, &options[0], &buffer[0]);

	if(parse.error()) return 1;
	if(options[HELP]){ option::printUsage(cout, usage); return 0; }

	///Exibe as opções inválidas detectadas
	for(option::Option* opt = options[UNKNOWN]; opt; opt = opt->next())
		cout << "Unknown Option: " << string(opt->name,opt->namelen) << '\n';

	for(unsigned i = 0; i < parse.optionsCount(); ++i){
		option::Option& opt = buffer[i];
		fprintf(stdout, "Argument #%d is ", i);
		switch (opt.index()){
			case HELP:
				// not possible, because handled further above and exits the program
			case VERBOSE:
				fprintf(stdout, "--verbose definido\n");
				break;

			case PRECISAO:
				fprintf(stdout, "--precisao=<%d>\n", Arg::toInteger(opt.arg));
				break;

			case DECRESCENTE:
				fprintf(stdout, "--decrescente definido\n");
				break;

			case TIPO:
				fprintf(stdout, "--tipo=<%s>\n", Arg::toString(opt.arg));
				break;

			case SIZE:
				fprintf(stdout, "--size=<%d>\n", Arg::toInteger(opt.arg));
				break;

			case ALGORITMOS:{
				fprintf(stdout, "--algortimos=[<%s>]\n", Arg::toString(opt.arg));
				vector<string> strAlgoritmos = StringParser::splitString(opt.arg);//
				for(auto s : strAlgoritmos) cout << s << '-';//
				cout << '\n';//
				break;
			}

			case UNKNOWN: break;
		}
	}


}
