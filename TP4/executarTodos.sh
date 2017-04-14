#!/bin/bash

declare -a ALEATORIOS=("1k" "5k" "10k" "20k" "50k" "100k")
declare -a ARR_ALGORITMOS=("merge" "quick" "heap" "insertion" "selection" "bubble")
declare -a COLUNAS=("comparações" "trocas" "tempo (ms)")


function gerarDados()
{
	for N in "${ALEATORIOS[@]}"
	do
		read -p "Executar para $N elementos? (y) " -n1 -r
		[[ $REPLY =~ ^[Yy]$ ]] || continue
		echo
		echo "./main-generator.sh $N '' __dadoscoletados/" | sh
	done
}

: '
for N in "${ALEATORIOS[@]}"
do
	mkdir -p "__dadoscoletados/$N"
	mv "__dadoscoletados/${N//k/000}_*" "__dadoscoletados/$N"
done
'

function gerarComandosExcel()
{
	for algoritmo in "${ARR_ALGORITMOS[@]}";do
		for col in "${COLUNAS[@]}"; do
			for N in "${ALEATORIOS[@]}"; do
				echo -n -e "=SUBTOTAL(101;${algoritmo}${N%k}[${col}])\n"
			done
			echo
		done
		echo "---------"
	done
}

# ----------------------------------------------------------- #
while getopts :de opt
do	case $opt in
	d)	gerarDados ;;
	e)	gerarComandosExcel;;
	\?) echo "Usage: $0 <-d, -e>"; exit 1;;
	esac
done
