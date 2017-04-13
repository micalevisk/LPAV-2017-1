#!/bin/bash
# //
# //	v0.13-4
# //	Usado para compilar e excutar o 'Loopable.sh'
# //	Created by Micael Levi on 04/13/2017
# //	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
# //


# ----------------------------------- [ HELP ] ----------------------------------- #
[ $# -lt 1 ] && {
	echo -e "USO: \033[40;31;1m./main-generator.sh\033[0m \033[40;32;1m<N>\033[0m \033[40;35m[M]\033[0m"
	echo -e 'Para executar o teste \033[40;35mM\033[0m (default 10) vezes com \033[40;32mN\033[0m elementos.'
	exit 1
}
# ------------------------------------------------------------------------------- #

# ------------------------------ [ CONFIGURAÇÕES ] ------------------------------ #
readonly LOOPABLE="./Loopable.sh"
readonly TP4_SORT="./src/tp4_sort"
readonly PATH_DADOS=${3:-"dadoscoletados/"}

declare -ri QTD_ELEMENTOS=$1 QTD_VEZES=${2:-10}
declare -a ARR_ALGORITMOS=("merge" "quick" "heap" "insertion" "selection" "bubble")
# ------------------------------------------------------------------------------- #

## Verifica se o caminho alvo (onde serão armazenados os testes) existe
[ -d "$PATH_DADOS" ] || { echo "Crie o diretório '${PATH_DADOS}'" ; exit 1 ; }

## Executa
for algoritmo in "${ARR_ALGORITMOS[@]}"
do
	arquivoSaida="${algoritmo}_${QTD_ELEMENTOS}.tsv"
	echo -e "comparações\ttrocas\ttempo" > "$PATH_DADOS$arquivoSaida"

	comando="${TP4_SORT} --size=${QTD_ELEMENTOS} --algorithms=${algoritmo}"
	comando="${comando} | sed '1d ; y/,./\t,/' | cut --fields=3- >> ${arquivoSaida}"

	echo "${LOOPABLE} ${QTD_VEZES} \"${comando}\""

done
