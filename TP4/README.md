# Trabalho Prático 4: Comparação de Métodos de Ordenação
> 07/04/2017 ⇒ 13/04/2017

<details>
<summary>Tópicos</summary>
<!-- TOC depthFrom:1 depthTo:6 withLinks:1 updateOnSave:0 orderedList:0 -->

* [MACROS](#macros)
* [Compilar com o Makefile (comando `make`)](#compilar-com-o-makefile-comando-make)
* [Compilar sem o Makefile (`g++`)](#compilar-sem-o-makefile-g)
* [Exemplo de Execução](#exemplo-de-execução)

<!-- /TOC -->
</details>

<!-- http://fnal.gov/docs/products/gcc/libg++/libg++_toc.html -->
<!-- LEGENDAS DA TREE DIRECTORY:
{pasta}
@executavel
-->
<details>
	<summary>Árvore do Diretório <b>src</b></summary>

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
	├── Makefile
	└── ordenacaoAnalytics.cc
</details>

## MACROS
| macro	      | default | descrição |
|:------------|:-------:|-----------|
| PRECISION   | `2`     | quantidade de casas decimais do tempo de execução
| MILLISECONDS| `false` | se `true`, então o tempo de execução será dado em milissegundos
| VERBOSE     | `false` | se `true`, mostra o estado dos arrays antes e depois da execução _[developer mode]_
| DEBUG       | `false` | se `true`, então verifica se os dados foram ordenados _[developer mode]_


## Compilar com o Makefile (comando `make`)
```bash
make [<MACRO>=<valor>]
make mostlyclean # apaga os objetos gerados
make clean # apaga os objetos e o executável gerados
```
[![preview_compilando_com_o_makefile](https://asciinema.org/a/0teeiivsyn27hp1ou4tqqofmx.png)](https://asciinema.org/a/0teeiivsyn27hp1ou4tqqofmx)


## Compilar sem o Makefile (`g++`)
```bash
g++ -std=c++11 -o tp4_sort -I./headers -I./headers/lib *.cc algoritmos/*.cc [<MACRO>=<valor>]
```
[![preview_compilando_com_o_g++](https://asciinema.org/a/09sbv3nsmny9lwvpjux68ocko.png)](https://asciinema.org/a/09sbv3nsmny9lwvpjux68ocko)


## Exemplo de Execução
[![exemplo de execução](https://asciinema.org/a/eyrhu27j373abvsrz149hy2co.png)](https://asciinema.org/a/eyrhu27j373abvsrz149hy2co)
