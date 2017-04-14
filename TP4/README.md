# Trabalho Prático 4: Comparação de Métodos de Ordenação
> 07/04/2017 ⇒ 13/04/2017

<!-- http://fnal.gov/docs/products/gcc/libg++/libg++_toc.html -->
<!-- LEGENDAS DA TREE DIRECTORY:
{pasta}
@executavel
-->
```
{src}
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
  ├── Makefile
  └── ordenacaoAnalytics.cc
```

## MACROS

| macro	      | default | descrição |
|:-----------:|:-------:|:---------:|
| VERBOSE     | `false` | se `true`, mostra o estado dos arrays antes e depois da execução
| PRECISION   | `2`     | quantidade de casas decimais do tempo de execução
| MILLISECONDS| `false` | se `true`, então o tempo de execução será dado em milissegundos
| DEBUG       | `false` | se `true`, então executa operações do teste unitário

## Compilar com o Makefile (comando `make`)
```bash
make [<MACRO>=<valor>]
make mostlyclean # apaga os objetos gerados
make clean # apaga os objetos e o executável gerados
```
[![compilando com o make](https://asciinema.org/a/0poussalil84jyjlclwg48gta.png)](https://asciinema.org/a/0poussalil84jyjlclwg48gta)


## Compilar sem o Makefile
```bash
g++ -std=c++11 -o tp4_sort -I./headers -I./headers/lib *.cc algoritmos/*.cc [<MACRO>=<valor>]
```
[![compilando com o g++](https://asciinema.org/a/8l6i3emn36p6cy9toet2duh4q.png)](https://asciinema.org/a/8l6i3emn36p6cy9toet2duh4q)


## Help
![help](http://i.imgur.com/8MrwV28.png)


## Exemplo de Execução
[![executando](https://asciinema.org/a/405gydk5n9k97zd0xj7v945aw.png)](https://asciinema.org/a/405gydk5n9k97zd0xj7v945aw)

<!-- last code changes: 14/04/2017 14:45 -->
