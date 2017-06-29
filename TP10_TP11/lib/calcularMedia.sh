#!/bin/bash
# //
# //	[calcularMedia.sh]
# //	Created by Micael Levi on 06/28/2017
# //	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
# //
# //	Após a execução do 'executarExercicio.sh',
# //	este script usará os dados obtidos das N execuções de cada instância
# //	e criará um arquivo CSV contendo somente as médias obtidas de cada.
# //


[[ $# -ne 1 ]] && {
	echo -e "USO: \e[40;36m$0\e[0m\e[40;33;1m <número do exercicio>\e[0m"
	exit 1
}

declare -ir NUM_EXERCICIO="$1"
readonly SEP=','
readonly PATH_RESULTADOS="../exercicio ${NUM_EXERCICIO}/__resultados__"
readonly PATH_MEDIAS="${PATH_RESULTADOS}/__medias__"
readonly HEADER_CSV="threads,instância,tempo(ms)"


mkdir -p "$PATH_MEDIAS"

for pastaInstancia in "${PATH_RESULTADOS}"/*k
do
	echo -e "\n---------- '${pastaInstancia}' ----------"
	for arquivoResultados in "${pastaInstancia}"/*
	do
		arquivoMediaInstancia=$(dirname "$arquivoResultados")
		arquivoMediaInstancia="${PATH_MEDIAS}${arquivoMediaInstancia#${PATH_RESULTADOS}}.csv"

		echo "Gerando '$arquivoMediaInstancia'"
		awk -F$SEP '{ soma+=$3 ; ++n  } END { print $1 "," $2 "," soma/n }' "$arquivoResultados" 1>> "$arquivoMediaInstancia"
	done

	sed -i "1i\ $HEADER_CSV" "$arquivoMediaInstancia"
	sort -n "$arquivoMediaInstancia" -o "$arquivoMediaInstancia"
done
