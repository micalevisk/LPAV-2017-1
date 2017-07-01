<!-- GNUPLOT
http://gnuplot.sourceforge.net/docs_4.2/
http://gnuplot.sourceforge.net/demo/fit.html
http://gnuplot.sourceforge.net/demo_5.0/lines_arrows.html
http://www.gnuplotting.org/tag/linespoints/
http://alvinalexander.com/technology/gnuplot-charts-graphs-examples
http://linux.byexamples.com/archives/487/plot-your-graphs-with-command-line-gnuplot/
-->

<!-- ESPECIFICAÇÃO
Os exercícios requerem a execução e medição de tempo sob diferentes configurações
de quantidade de threads e de quantidade dos dados. Estes resultados deversão ser
colocados em uma tabela. Com o intuito de minimizar efeitos locais, é exigido que
os dados contenham os valores médios de pelo menos três execuções em cada configuração,

Como este trabalho visa medir o tempo de execução para diversas configurações.
Para o cálculo do tempo de execução pode ser usado tanto o gettimeofday ou clock_gettime

DIA DA ENTREGA: 22/06 até 23:59
O relatório deve incluir também a arquitetura da máquina em que foram feito os testes.
-->

# Trabalho Prático 10: Threads
> 16/06/2017 ⇒ 27/06/2017

- **exercício 1**
	- [x] código: `exercicio1.cpp`
	- [x] dados para o relatório
	- [x] gráficos para o relatório
	- [ ] relatório dos resultados obtidos
- **exercício 2**
	- [x] código: `exercicio2.cpp`
	- [x] dados para o relatório
	- [ ] gráficos para o relatório
	- [ ] relatório dos resultados obtidos
- **exercício 3**
	- [x] código: `exercicio3.cpp`
	- [x] dados para o relatório
	- [x] gráficos para o relatório
	- [ ] relatório dos resultados obtidos
- **exercício 4**
	- [ ] relatório de comparação dos exercícios

# Trabalho Prático 11: Threads
> 16/06/2017 ⇒ 27/06/2017

- **exercício 5**
	- [x] código: `algoritmos/quiksort_sequencial`
	- [ ] dados para o relatório
	- [ ] gráficos para o relatório
	- [ ] relatório dos resultados obtidos
- **exercício 6**
	- [ ] código: `algoritmos/quiksort_paralelo`
	- [ ] dados para o relatório
	- [ ] gráficos para o relatório
	- [ ] relatório dos resultados obtidos

---

### Para fazer o exercício 1 _(TP10)_
> - Os passos a seguir foram realizados também para os exercícios 2 e 3
> - para verificar se o diretório contém todos os arquivos necessários (e programas), use o **[BATS](https://github.com/sstephenson/bats)** no arquivo `src/test_checarAmbiente.bats`
> - A pasta **lib/** contém os scripts (`.sh`) que serão utilizados abaixo






1. Criar dados aleatórios para a entrada: `./gerarEntradas.sh -v -g`
2. Compilar e executar (uma vez) o código do exercício 1 para as entradas criadas anteriormente: `./executarExercicio.sh -v -e1 -r1`
3. Extrair médias das execuções anteriores: `./calcularMediasExercicio.sh 1`
4. Gerar gráficos das médias extraídas: `./plotMediasExercicio.sh 1`
5. Apagar arquivos intermediários (gerados) para deixar somente os gráficos: `./manterSomenteGraficosExercicio.sh 1`

[![asciicast demo](https://asciinema.org/a/yiM7LNc8uojkJoS1am3ypBLFc.png)](https://asciinema.org/a/yiM7LNc8uojkJoS1am3ypBLFc)
