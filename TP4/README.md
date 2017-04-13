# Trabalho 4: 07/04/2017 ⇒ 13/04/2017

<!-- http://fnal.gov/docs/products/gcc/libg++/libg++_toc.html -->
<!-- LEGENDAS DA TREE DIRECTORY:
{pasta}
@executavel
-->
```
.
├── {algoritmos}
│   ├── bubblesort.cc
│   ├── heapsort.cc
│   ├── insertionsort.cc
│   ├── mergesort.cc
│   ├── quicksort.cc
│   └── selectionsort.cc
├── {headers}
│   ├── analytics.hpp
│   ├── extras.hpp
│   ├── {lib}
│   │   ├── arg.hpp
│   │   ├── getopts.hpp
│   │   ├── optionparser.h
│   │   └── unittest.hpp
│   └── ordenacaoAnalytics.hpp
├── main.cc
├── @Makefile
└── ordenacaoAnalytics.cc
```

## MACROS

| macro	      | default | descrição |
|:-----------:|:-------------:|:---------:|
| VERBOSE     | `false` 	  | se `true`, mostra o estado dos arrays antes e depois da execução
| PRECISION   | `2`     	  | quantidade de casas decimais do tempo de execução
| MILLISECONDS| `false` 	  | se `true`, então o tempo de execução será dado em milissegundos
| DEBUG       | `false` 	  | se `true`, então executa operações do teste unitário

## Compilar com o Makefile (comando `make`)
```bash
make [<MACRO>=<valor>]
make mostlyclean # apaga os objetos gerados
make clean # apaga os objetos e o executável gerados
```

## Compilar sem o Makefile
```bash
g++ -std=c++11 -o tp4_sort -I./headers -I./headers/lib -I./ *.cc algoritmos/*.cc
```

## Help
```
USAGE: ./tp4_sort [OPTIONS]

OPTIONS:
	-h, --help          Exibe esta mensagem e finaliza.
	-s <S>,--size=<S>   Define o tamanho da instância gerada (default: 10).
	--algorithms=ALG    Algoritmos que serão executados (default: all).

ALG (CSV):
	all bubble selection insertion heap merge quick

Examples:
	./tp4_sort -s5 --algortimos=quick,insertion
	./tp4_sort --size 3 --algorithms 'heap,selection'
```

<!-- last code changes: 13/04/2017 15:30 -->
