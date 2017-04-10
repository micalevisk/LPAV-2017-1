# Trabalho 4: 07/04 + 13/04

<!-- http://fnal.gov/docs/products/gcc/libg++/libg++_toc.html -->
<!-- LEGENDAS DA TREE DIRECTORY:
{pasta}
@executavel
-->
```
.
├── {algoritmos}
│   ├── bubblesort.cc
│   └── selectionsort.cc
├── {headers}
│   ├── analytics.hpp
│   ├── extras.hpp
│   ├── {lib}
│   │   ├── arg.hpp
│   │   ├── optionparser.h
│   │   └── stringparser.hpp
│   └── ordenacaoAnalytics.hpp
├── main.cc
├── @Makefile
└── ordenacaoAnalytics.cc

```

## make {MACROS}

| macro	| default | descrição |
|:-----:|:-------:|:---------:|
| VERBOSE | false | mostrar o estado dos vetores/arrays & significado do CSV `Analytics`
| PRECISION | 2 | quantidade de casas do tempo de execução
| DECRESCENTE | false | se `true` então ordena em ordem decrescente
| TIPO | int | tipo (`C++`) dos elementos lidos
| MILLISECONDS | false | se `true` então o tempo de execução será dado em milissegundos


PARTE 1
=======
- [ ] calcular quantidade (médio) de comparações
- [ ] calcular quantidade (média) de trocas
- [ ] calcular tempo (médio) de execução

+ Planilha com a tabela para o relatório e cada massa de dados gerada (aleatoriamente)

+ Código com opções para definir a quantidade de valores que serão gerados para o teste e um handler para direncionar qual algoritmo será utilizado


PARTE 2
=======
- [ ] gerar três gráficos com as medições anteriores (comparando os 6 algoritmos)



PARTE 3
=======
> responder perguntas:

- [ ] Considerando somente a métrica "tempo de execução", qual foi o seu melhor e o pior caso observado para cada método?

- [ ] Considerando somente a métrica "quantidade de comparações

- [ ] Considerando as métricas "quantidade de trocas" e "quantidade de comparações" faça uma relação entre essas duas métricas e diga uma função que representa tal relação.
