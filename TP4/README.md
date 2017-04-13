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

| macro	      | valor default | descrição |
|:-----------:|:-------------:|:---------:|
| VERBOSE     | `false` 	  | se `true`, mostrar o estado dos arrays antes e depois da execução
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

## Uso
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



***

PARTE 1
=======
- [x] calcular quantidade (médio) de comparações
- [x] calcular quantidade (média) de trocas
- [x] calcular tempo (médio) de execução
- [ ] Planilha com a tabela para o relatório e cada massa de dados gerada (aleatoriamente)


PARTE 2
=======
- [ ] gerar três gráficos com as medições anteriores (comparando os 6 algoritmos)


PARTE 3
=======
> responder três perguntas:

- [ ] Considerando somente a métrica **tempo de execução**, qual foi o seu melhor e o pior caso observado para cada método?
- [ ] Considerando somente a métrica **quantidade de comparações**
- [ ] Considerando as métricas **quantidade de trocas** e **quantidade de comparações** faça uma relação entre essas duas métricas e diga uma função que representa tal relação.
