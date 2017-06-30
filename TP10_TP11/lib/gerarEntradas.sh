#!/bin/bash
# //
# //	[gerarEntradas.sh]
# //	Created by Micael Levi on 06/28/2017
# //	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
# //
# //	Deve ser executado para a criação das entradas para os exercícios.
# //	Será criado uma pasta '__dados__' que armazenará os arquivos
# //	de entrada com o nome no formato '<instancia>.txt',
# //	Faz o uso do código gerador 'randomNumbersGenerator.c'.
# //


# -------------------------- [ CONFIGURAÇÕES ] -------------------------- #
declare -ri MAIOR_NUMERO=1000000
declare -a INSTANCIAS=("32k" "64k" "128k" "256k" "512k" "1024k" "2048k")

readonly PATH_OUTPUT="../__dados__"
readonly PATH_CODE="../randomNumbersGenerator.c"
readonly PATH_EXEC="${PATH_CODE/.c}"
# ----------------------------------------------------------------------- #


[ -r "$PATH_CODE" ] || {
	echo -e "Arquivo '${PATH_CODE}' não encontrado/legível"
	exit 2
}

function imprimir(){
	echo "$1" 1>&3
}

function compilar(){
	imprimir "Compilando '$PATH_CODE'"
	gcc "$PATH_CODE" -o "$PATH_EXEC"
	[ ! $? ] && exit 3
}

function apagarArquivosGerados(){
	imprimir "Apagando arquivos gerados"
	rm -f "$PATH_EXEC"
	echo "rm -f $PATH_OUTPUT/*" | sh
}

function gerarEntradas(){
	[ -x $PATH_EXEC  ] || compilar
	[ -d "$PATH_OUTPUT" ] || mkdir -p "$PATH_OUTPUT"

	for N in "${INSTANCIAS[@]}"
	do
		instancia="${N//k/000}"
		saidaExec="$PATH_OUTPUT/${N}.txt"

		imprimir "Executando para $N (salvando em '$saidaExec')"
		./$PATH_EXEC "$saidaExec" $instancia $MAIOR_NUMERO 1>/dev/null
		sleep 3
	done
}

function showUsage(){
	echo -e "USO: \e[40;36m$0\e[0m \e[40;33m[-v]\e[0m \e[40;33;1m< -g , -d >\e[0m"
	exit 1
}

# ----------------------------------------------------------- #
exec 3>/dev/null # sem verbose
[[ $# -lt 1 ]] && showUsage

while getopts :vgd opt
do	case $opt in
	v) exec 3>&2 ;;
	g) gerarEntradas ;;
	d) apagarArquivosGerados ;;
	\?) showUsage ;;
	esac
done
# ----------------------------------------------------------- #
