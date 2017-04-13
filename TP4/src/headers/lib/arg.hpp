//
//	[arg.hpp]
//	Created by Micael Levi on 04/09/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//

#ifndef ARG_HPP
#define ARG_HPP



struct Arg: public option::Arg {
	static const char* toString(const char* arg){ return ( arg + (arg[0]=='=') ); }
	static int toInteger(const char* arg){ return atoi(arg); }

	static void printError(const char* msg1, const option::Option& opt, const char* msg2){
		fprintf(stderr, "%s", msg1);
		fwrite(opt.name, opt.namelen, 1, stderr);
		fprintf(stderr, "%s", msg2);
	}

	static option::ArgStatus Required(const option::Option& option, bool msg){
		if (option.arg != 0) return option::ARG_OK;
		if (msg) printError("Option '", option, "' requires an argument\n");
		return option::ARG_ILLEGAL;
	}

	static option::ArgStatus Numeric(const option::Option& option, bool msg){
		char* endptr = 0;
		if (option.arg != 0 && strtol(option.arg, &endptr, 10));
		if (endptr != option.arg && *endptr == 0) return option::ARG_OK;
		if (msg) printError("Option '", option, "' requires a numeric argument\n");
		return option::ARG_ILLEGAL;
	}
};


enum  optionIndex { UNKNOWN, HELP, _VERBOSE, _PRECISION, _DESCENDING, SIZE, ALGORITHMS };
const option::Descriptor usage[] = {
	{UNKNOWN, 0, "", "",option::Arg::None, "USAGE: example [OPTIONS]\n\n"
															"OPTIONS:" },
	{_VERBOSE,      0,"","verbose", option::Arg::None,		"  --verbose*  \tMostra o estado dos arrays (default: false)." },
	{HELP,         0,"h","help",   option::Arg::None,		"  -h, --help   \tPrint usage and exit." },
	{SIZE,         0,"s","size",    Arg::Numeric,  			"  -s <S>,--size=<S>   \tDefine o tamanho da instância gerada (default: 10)." },
	{_PRECISION,    0,"p","precision",Arg::Numeric,			"  -p <P>,--precision=<P>*  \tNúmero de casas do tempo de execução (default: 2)." },
	{_DESCENDING,   0,"d","descending", option::Arg::None,	"  -d, --descending*  \tOrdena em ordem decrescente." },
	{ALGORITHMS,   0,"","algorithms",Arg::Required,			"  --algorithms=ALG   \tAlgoritmos que serão executados (default: all)." },

	{UNKNOWN, 0, "", "",option::Arg::None, "\nALG (CSV):\n  all bubble selection insertion heap merge quick\n" },
	{UNKNOWN, 0, "", "",option::Arg::None,	"Examples:\n"
											"  example --verbose -s5 -p0 --algortimos=quick,insertion \n"
											"  example --descending --size 3 --algorithms 'heap,selection'\n" },
	{0,0,0,0,0,0}
};



#endif
