#!/bin/bash
# //
# //	[manterSomenteGraficosExercicio.sh]
# //	Created by Micael Levi on 06/30/2017
# //	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
# //
# //	Após a execução do 'plotMediasExercicio.sh',
# //	este script APAGARÁ todos os dados gerados e coletados (da execução dos exercícios)
# //	que foram automaticamente gerados pela a execução dos seguintes scripts:
# //	'gerarEntradas.sh'
# //	'executarExercicio.sh'
# //	'calcularMediasExercicio.sh'
# //


# -------------------------- [ CONFIGURAÇÕES ] -------------------------- #
declare -ir NUM_EXERCICIO=${1:-0}

readonly PATH_DADOS="../__dados__"
readonly PATH_RESULTADOS="../exercicio ${NUM_EXERCICIO}/__resultados__"
readonly PATH_MEDIAS="${PATH_RESULTADOS}/__medias__"
# ----------------------------------------------------------------------- #

[[ $# -ne 1 ]] && {
	echo -e "USO: \e[36m$0\e[0m \e[35m[NÚMERO_DO_EXERCICIO]\e[0m"

	## Apagar diretório que contém os dados de entrada para os exercícios, gerados por 'gerarEntradas.sh'
	[[ -d "$PATH_DADOS" ]] &&{
		echo "Apagando diretório '$PATH_DADOS'"
		rm -I -r -v "$PATH_DADOS"
	}

	exit 1
}
[[ $NUM_EXERCICIO -ge 1 && $NUM_EXERCICIO -le 3 ]] || exit 2



## Apagar pastas que contém os dados gerados por 'executarExercicio.sh'
[[ -d "$PATH_RESULTADOS" ]] || {
	echo "'$PATH_RESULTADOS' não é um diretório"
	exit 3
}
for pastaInstancia in "$PATH_RESULTADOS"/*k
do
	[[ -d "$pastaInstancia" ]] || exit 4

	echo "Apagando diretório '$pastaInstancia'"
	rm -I -r -v "$pastaInstancia"
	echo
done

## Apagar arquivos CSV que contém as médias, gerados por 'calcularMediasExercicio.sh'
[[ -d "$PATH_MEDIAS" ]] || {
	echo "'$PATH_MEDIAS' não é um diretório"
	exit 3
}
for arquivoCSV in "$PATH_MEDIAS"/*k.csv
do
	[[ -r "$arquivoCSV" ]] || exit 4

	echo "Apagando arquivo '$arquivoCSV'"
	rm -v "$arquivoCSV"
	echo
done
