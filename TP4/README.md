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
├── main-getopt.cc
├── @Makefile
└── ordenacaoAnalytics.cc
```

##  make {MACROS}

| macro	      | default | descrição |
|:-----------:|:-------:|:---------:|
| VERBOSE     | `false` | mostrar o estado dos vetores/arrays & significado do CSV `Analytics`
| PRECISION   | `2`     | quantidade de casas do tempo de execução
| MILLISECONDS| `false` | se definido, então o tempo de execução será dado em milissegundos
| DEBUG       | `false` | se definido, então executa operações do teste unitário


***

PARTE 1
=======
- [x] calcular quantidade (médio) de comparações
- [x] calcular quantidade (média) de trocas
- [x] calcular tempo (médio) de execução
- [ ] Planilha com a tabela para o relatório e cada massa de dados gerada (aleatoriamente)
- [ ] Código com opções para definir a quantidade de valores que serão gerados para o teste e um handler para direncionar qual algoritmo será utilizado


PARTE 2
=======
- [ ] gerar três gráficos com as medições anteriores (comparando os 6 algoritmos)


PARTE 3
=======
> responder três perguntas:

- [ ] Considerando somente a métrica **tempo de execução**, qual foi o seu melhor e o pior caso observado para cada método?
- [ ] Considerando somente a métrica **quantidade de comparações**
- [ ] Considerando as métricas **quantidade de trocas** e **quantidade de comparações** faça uma relação entre essas duas métricas e diga uma função que representa tal relação.
