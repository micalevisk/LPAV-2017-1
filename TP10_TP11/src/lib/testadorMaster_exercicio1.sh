#!/bin/bash

INFO="\e[31;1m[ATENÇÃO]\e[0m Este Script fará:\n
\e[37;1m1. Criar dados aleatórios para a entrada\e[0m
   \e[36m./gerarEntradas.sh\e[0m \e[35m-v\e[0m \e[35;1m-g\e[0m

\e[37;1m2. Compilar e executar (uma vez) o código do exercício 1 para as entradas criadas anteriormente\e[0m
   \e[36m./executarExercicio.sh\e[0m \e[35m-v\e[0m \e[35;1m-e1 -r\e[0m\e[35m1\e[0m

\e[37;1m3. Extrair médias das execuções anteriores\e[0m
   \e[36m./calcularMediasExercicio.sh\e[0m \e[35;1m1\e[0m

\e[37;1m4. Gerar gráficos das médias extraídas\e[0m
   \e[36m./plotMediasExercicio.sh\e[0m \e[35;1m1\e[0m

\e[37;1m5. Apagar arquivos intermediários (gerados) para deixar somente os gráficos\e[0m
   \e[36m./manterSomenteGraficosExercicio.sh\e[0m \e[35m1\e[0m
"
echo -e "$INFO"
sleep 3 # para ler a mensagem acima
read -n1 -p ">> Deseja Prosseguir? (Yy): "
[[ "${REPLY,,}" == "y" ]] || exit 1
echo

##1
./gerarEntradas.sh -v -g
##2
./executarExercicio.sh -v -e1 -r1
##3
./calcularMediasExercicio.sh 2
##4
./plotMediasExercicio.sh 2
##5
./manterSomenteGraficosExercicio.sh 1
