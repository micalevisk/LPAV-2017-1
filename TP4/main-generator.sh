#!/bin/bash
# //
# //	v0.13-4
# //	Usado para excutar o 'Loopable.sh' e salvar dados coletados.
# //	Created by Micael Levi on 04/13/2017
# //	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
# //


# ----------------------------------- [ HELP ] ----------------------------------- #
[ $# -lt 1 ] && {
	echo -e "USO: \033[40;31;1m$0\033[0m \033[40;32;1m<N>\033[0m \033[40;35m[M]\033[0m"
	echo -e 'Para executar o teste \033[40;35mM\033[0m (default 10) vezes com \033[40;32mN\033[0m elementos (pode usar "k" como 1000).'
	exit 1
}
# ------------------------------------------------------------------------------- #

# ------------------------------ [ CONFIGURAÇÕES ] ------------------------------ #
readonly LOOPABLE="./Loopable.sh"
readonly TP4_SORT="./src/tp4_sort"
readonly PATH_DADOS=${3:-"dadoscoletados/"}

declare -ri QTD_ELEMENTOS=${1//k/000} QTD_VEZES=${2:-10}
declare -a ARR_ALGORITMOS=("merge" "quick" "heap" "insertion" "selection" "bubble")
# ------------------------------------------------------------------------------- #

## Verifica se o caminho alvo (onde serão armazenados os testes) existe
# [ -d "$PATH_DADOS" ] || { echo "Crie o diretório '${PATH_DADOS}'" ; exit 1 ; }
[ -x "$TP4_SORT" ] || { echo "Compile o código para gerar o '${TP4_SORT}'" ; exit 2 ; }
mkdir -p "${PATH_DADOS}"

## Executa
for algoritmo in "${ARR_ALGORITMOS[@]}"
do
	arquivoSaida="$PATH_DADOS${QTD_ELEMENTOS}_${algoritmo}.tsv"
	echo -e "comparações\ttrocas\ttempo" > "$arquivoSaida"

	comando="${TP4_SORT} --size=${QTD_ELEMENTOS} --algorithms=${algoritmo}"
	comando="${comando} | sed '1d ; y/,./\t,/' | cut --fields=3- >> ${arquivoSaida}"

	echo "${LOOPABLE} ${QTD_VEZES} \"${comando}\"" | sh

done
