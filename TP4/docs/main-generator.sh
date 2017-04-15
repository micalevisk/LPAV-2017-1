#!/bin/bash
# //
# //	v0.15-4
# //	Para gerar os dados para o relatório.
# //	O programa ../src/tp4_sort será executado 10 vezes
# //	Os dados serão armazenados em ../__dadoscoletados
# //
# //	Created by Micael Levi on 04/15/2017
# //	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
# //



# ------------------------------ [ CONFIGURAÇÕES ] ------------------------------ #
readonly TP4_SORT="../src/tp4_sort"
readonly PATH_DADOS="../__dadoscoletados"
declare -ri QTD_VEZES=10
declare -a INSTANCIAS=("1k" "5k" "10k" "20k" "50k" "100k")

readonly PATH_CSV="${PATH_DADOS}/CSV"
readonly PATH_TSV="${PATH_DADOS}/TSV"
declare -a ALGORITMOS=("merge" "quick" "heap" "insertion" "selection" "bubble")
# ------------------------------------------------------------------------------- #

[ -x "$TP4_SORT" ] || {
	echo -e "\033[40;31;1m>> Gere o executável em ${TP4_SORT}\033[0m"
	exit 1
}


function handlerDiretorios()
{
	command="${1}" ## "mkdir -p" OU "rm -rf"
	$command "${PATH_DADOS}"
	$command "${PATH_CSV}"
	$command "${PATH_TSV}"
}


function gerarDados()
{
	handlerDiretorios "mkdir -p"
	for N in "${INSTANCIAS[@]}"
	do
		instancia="${N//k/000}"
		saidaCSV="${PATH_CSV}/${N}.csv"


		## Executando 'QTD_VEZES' vezes todos os algoritmos e salvando num único CSV
		echo "algoritmo,instância,comparações,trocas,tempo" > $saidaCSV

		for i in `seq 1 $QTD_VEZES`
		do
			echo "${i}:[Executando Instância de ${instancia} valores]" >&3

			$TP4_SORT --quiet -s${instancia} >> $saidaCSV
			sleep 0.2
		done

		## Separando cada algoritmo em seu diretório
		for algoritmo in "${ALGORITMOS[@]}"
		do
			echo "[Filtrando valores do ${algoritmo}]" >&3

			diretorioAlgoritmo="${PATH_TSV}/${algoritmo}"
			mkdir -p "$diretorioAlgoritmo"
			saidaTSV="${diretorioAlgoritmo}/${N}.tsv"

			sed -n "/^${algoritmo,,}/p" $saidaCSV | sed 'y/,./\t,/' | sed "1i${algoritmo}" | cut --fields=3- > $saidaTSV
		done

		echo >&3

	done
}


# ----------------------------------------------------------- #
exec 3>/dev/null # sem verbose

while getopts :vgd opt
do	case $opt in
	v) exec 3>&2 ;;
	g) gerarDados ;;
	d) handlerDiretorios "rm -rf .dadosarray.bin" ;;
	\?) echo -e "USO: \e[40;36m$0\e[m \e[40;33m[-v]\e[40;33;1m<-g, -d>\e[m"; exit 1;;
	esac
done
# ----------------------------------------------------------- #
