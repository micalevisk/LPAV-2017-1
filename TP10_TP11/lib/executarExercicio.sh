#!/bin/bash
# //
# //	[executarExercicio.sh]
# //	Created by Micael Levi on 06/28/2017
# //	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
# //
# //	Após a execução do 'gerarEntradas.sh',
# //	esse script executará um exercício escolhido (1..3)
# //	salvando a saída (obtida pela execução) na pasta '__resultados__'
# //	e dentro da pasta do sua respectiva instância
# //	com o nome no formato '<quantidadeThreads>_threads.txt'.
# //


# -------------------------- [ CONFIGURAÇÕES ] -------------------------- #
declare -a THREADS=(4 16 32 64 128 256 512 1024 2048 4096)
declare -i numExercicio

readonly PATH_INPUT="../__dados__"
# ----------------------------------------------------------------------- #


[ -d "$PATH_INPUT" ] || {
	echo "'$PATH_INPUT' não é um diretório"
	exit 2
}

function imprimir(){
	echo -e "$1" 1>&3
}

function die(){
	imprimir "Não deve -run e -delete ao mesmo tempo"
	exit 6
}


function compilar(){
	imprimir "Compilando '$PATH_CODE'"
	g++ -std=c++11 -I./ "$PATH_CODE" -o "$PATH_EXEC" -lpthread -D MILLISECONDS
	[ ! $? ] && exit 3
}

function apagarArquivosGerados(){
	read -n1 -p "Apagar '$PATH_EXEC' e '$PATH_OUTPUT'? (y) "
	[[ ${REPLY,,} == "y" ]] || exit

	imprimir "\nApagando arquivos gerados"
	rm -f "$PATH_EXEC"
	rm -rf "$PATH_OUTPUT"
}

function executarExercicio(){
	[[ -x $PATH_EXEC  ]] || compilar
	[[ -d "$PATH_OUTPUT" ]] || mkdir -p "$PATH_OUTPUT"

	for arquivoEntradaInstancia in "$PATH_INPUT"/*k.txt
	do
		[[ -r "$arquivoEntradaInstancia" ]] || exit 5

		## definição das variáveis (NÃO ALTERAR A SEQUÊNCIA ABAIXO!)
		local N=$(basename "$arquivoEntradaInstancia") ; N="${N%.txt}"
		instancia="${instancia//k/000}"
		caminhoSaidaInstancia="$PATH_OUTPUT/${N}"

		mkdir -p "$caminhoSaidaInstancia"

		imprimir "Executar para instância $N"
		for nthreads in "${THREADS[@]}"
		do
			saidaExec="$caminhoSaidaInstancia/${nthreads}_threads.csv"
			sleep 1
			imprimir "\tExecutando $N com $nthreads threads"
			( ./"$PATH_EXEC" $nthreads < "$arquivoEntradaInstancia" ) >> "$saidaExec"
			imprimir "\tSalvo em '$saidaExec'"
		done
		echo
	done
}


function showUsage(){
	echo -e "USO: \e[36m$0\e[0m \e[35m[-v]\e[0m \e[35;1m-e<NÚMERO_DO_EXERCICIO> < -r\e[0m\e[35m[QTD_EXECUÇÕES]\e[35;1m , -d >\e[0m"
	exit 1
}
# ----------------------------------------------------------- #
exec 3>/dev/null # sem verbose
[[ $# -lt 1 ]] && showUsage

realizarExecucao=false
realizarRemocao=false
declare -i qtdExecucoes

while getopts :ve:r:d opt
do	case $opt in
	v)	exec 3>&2 ;;
	e)	numExercicio=$OPTARG ;;
	r)
		$realizarRemocao && die
		realizarExecucao=true
		qtdExecucoes=${OPTARG:-1}
		;;

	d)
		$realizarExecucao && die
		realizarRemocao=true
		;;
	\?) showUsage ;;
	esac
done

[[ $numExercicio -ge 1 && $numExercicio -le 3 ]] || exit 4
PATH_EXERCICIO="../exercicio $numExercicio"
PATH_OUTPUT="${PATH_EXERCICIO}/__resultados__"
PATH_CODE="${PATH_EXERCICIO}/exercicio${numExercicio}.cpp"
PATH_EXEC="${PATH_CODE/.cpp}"

$realizarRemocao && apagarArquivosGerados
$realizarExecucao && {
	i=1
	while [[ $i -le qtdExecucoes ]]
	do
		imprimir "Execução $i"
		executarExercicio
		(( i++ ))
	done
}
# ----------------------------------------------------------- #
