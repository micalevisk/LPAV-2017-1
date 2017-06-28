#!/bin/bash



# -------------------------- [ CONFIGURAÇÕES ] -------------------------- #
declare -ri MAIOR_NUMERO=1000000
declare -a INSTANCIAS=("32k" "64k" "128k" "256k" "512k" "1024k" "2048k")
# declare -a THREADS=(4 16 32 64 128 256 512 1024 2048 4096)

readonly PATH_CSV="__dados__"
readonly PATH_CODE="randomNumbersGenerator.c"
readonly PATH_EXEC="${PATH_CODE/.c}"

apagarTudoAoSair=0
# ----------------------------------------------------------------------- #


[ -r "$PATH_CODE" ] || {
	echo -e "\033[40;31m>> Arquivo '${PATH_CODE}' não encontrado/legível\033[0m"
	exit 2
}


function compilar(){
	echo "Compilando '$PATH_CODE'" 1>&3
	gcc "$PATH_CODE" -o "$PATH_EXEC"
	[ ! $? ] && exit 3
}

function apagarArquivosGerados(){
	echo "Apagando arquivos gerados" 1>&3
	rm -f "$PATH_EXEC"
	echo "rm -f $PATH_CSV/*" | sh
}

function gerarEntradas(){
	[ -x $PATH_EXEC  ] || compilar
	[ -d "$PATH_CSV" ] || mkdir -p "$PATH_CSV"

	for N in "${INSTANCIAS[@]}"
	do
		instancia="${N//k/000}"
		saidaCSV="$PATH_CSV/${N}.csv"

		echo "Executando para $N (salvando em '$saidaCSV')" 1>&3
		./$PATH_EXEC "$saidaCSV" $instancia $MAIOR_NUMERO 1>/dev/null
		sleep 3
	done
}


# ----------------------------------------------------------- #
exec 3>/dev/null # sem verbose

while getopts :vgd opt
do	case $opt in
	v) exec 3>&2 ;;
	g) gerarEntradas ;;
	d) apagarArquivosGerados ;;
	\?) echo -e "USO: \e[40;36m$0\e[m \e[40;33m[-v]\e[40;33;1m <-g, -d>\e[m"; exit 1;;
	esac
done
# ----------------------------------------------------------- #