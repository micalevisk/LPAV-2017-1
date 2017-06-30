#!/bin/bash
# //
# //	[plotMediasExercicio.sh]
# //	Created by Micael Levi on 06/30/2017
# //	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
# //
# //	Após a execução do 'calcularMediasExercicio.sh',
# //	este script usará as médias calculadas e salvadas em '__medias__'
# //	na pasta de um exercício e criará uma pasta '__graficos__'
# //	que armazenará as sete imagens (png) dos gráficos obtidos das médias
# //	com o nome no formato '<instancia>.png'.
# //


[[ $# -ne 1 ]] && {
	echo -e "USO: \e[36m$0\e[0m \e[35;1m<NÚMERO_DO_EXERCICIO>\e[0m"
	exit 1
}

# ------------------------------------- [ CONFIGURAÇÕES ] ------------------------------------- #
declare -ir NUM_EXERCICIO=${1:-0}
declare -i i=0
declare -a CORES=("#7f8778" "#ba927b" "#414934" "#ff8847" "#e90e20" "#b56357" "#402158" "#7f9aff")

readonly PATH_INPUT_CSV="../exercicio ${NUM_EXERCICIO}/__resultados__/__medias__"
readonly PATH_GRAFICOS="${PATH_INPUT_CSV}/__graficos__"
# --------------------------------------------------------------------------------------------- #
[[ $NUM_EXERCICIO -ge 1 && $NUM_EXERCICIO -le 3 ]] || exit 2
[[ -d "$PATH_INPUT_CSV" ]] || {
	echo "'$PATH_INPUT_CSV' não é um diretório"
	exit 3
}

mkdir -p "$PATH_GRAFICOS"


for arquivoCSV in "${PATH_INPUT_CSV}"/*k.csv
do
	[[ -r "$arquivoCSV" ]] || exit 4
	echo "Executando para '$arquivoCSV'"

	## definição das variáveis (NÃO ALTERAR A SEQUÊNCIA ABAIXO!)
	instancia="${arquivoCSV%.csv}"
	datFile="${instancia}.dat"
	imageFile=$(basename "$datFile")
	instancia="${imageFile%.dat}"
	imageFile="${PATH_GRAFICOS}/${imageFile%.dat}.png"
	instancia="${instancia//k/.000}"

	echo -e "\tCriando arquivo '$datFile'"
	sed '1s/^./#/' "$arquivoCSV" | sed 'y/,/\t/' | cut -f1,3 > "$datFile"
	[[ $? ]] || exit 5

	echo -e "\tExecutando gnuplot salvando em '$imageFile'"
	gnuplot <<- EOF
		set style line 1 lc rgb "${CORES[i]}" lt 1 lw 2 pt 7 ps 1.5   # --- blue
		set title "Resultados Médios Para $instancia" center font "Menlo,14" textcolor lt 6
		set term png
		set output "$imageFile"
		set grid
		set border lw 2
		set logscale x 2

		set macros
			FONTE_TEXTOS = "font 'Monospace,10'"
			FONTE_EIXOS  = "font ',10'"

		# set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 pi -1 ps 1.5
		set xlabel "quantidade de threads"  @FONTE_TEXTOS
		set ylabel "tempo (ms)"  @FONTE_TEXTOS

		set xtics @FONTE_EIXOS
		set ytics @FONTE_EIXOS
		set xtics textcolor rgb "#621928"
		set ytics textcolor rgb "#2e2a5e"

		set style data linespoints
		plot "${datFile}" notitle ls 1
	EOF

	echo -e "\tApagando '$datFile'"
	rm -f "$datFile"

	echo -e "\tDONE!\n"
	(( i++ ))
done
echo "FIM!!"
