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
declare -a INSTANCIAS=("32k" "64k" "128k" "256k" "512k" "1024k" "2048k")
declare -a THREADS=(4 16 32 64 128 256 512 1024 2048 4096)
declare -i numExercicio

readonly PATH_INPUT="../__dados__"
# ----------------------------------------------------------------------- #


[ -d "$PATH_INPUT" ] || {
	imprimir "Erro ao procurar por '$PATH_INPUT'"
	exit 2
}

function imprimir(){
	echo "$1" 1>&3
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
	imprimir "Apagando arquivos gerados"
	rm -f "$PATH_EXEC"
	rm -rf "$PATH_OUTPUT"
}

function executarExercicio(){
	[[ -x $PATH_EXEC  ]] || compilar
	[[ -d "$PATH_OUTPUT" ]] || mkdir -p "$PATH_OUTPUT"

	for N in "${INSTANCIAS[@]}"
	do
		instancia="${N//k/000}"
		caminhoSaidaInstancia="$PATH_OUTPUT/${N}"
		entradaInstancia="$PATH_INPUT/${N}.txt"

		[ -r "$entradaInstancia" ] || {
			imprimir "Arquivo '$entradaInstancia' não encontrado/legível!"
			exit 5
		}

		mkdir -p "$caminhoSaidaInstancia"

		imprimir "Executar para instância $N"
		for nthreads in "${THREADS[@]}"
		do
			saidaExec="$caminhoSaidaInstancia/${nthreads}_threads.txt"
			sleep 1
			imprimir "Executando $N com $nthreads threads"
			( ./"$PATH_EXEC" $nthreads < $entradaInstancia ) 2>> "$saidaExec"
		done
	done
}


# ----------------------------------------------------------- #
exec 3>/dev/null # sem verbose

realizarExecucao=false
realizarRemocao=false
declare -i qtdExecucoes=1

while getopts :ve:r:d opt
do	case $opt in
	v)	exec 3>&2 ;;
	e)	numExercicio=$OPTARG ;;
	r)
		$realizarRemocao && die
		realizarExecucao=true
		qtdExecucoes=$OPTARG
		;;

	d)
		$realizarExecucao && die
		realizarRemocao=true
		;;
	\?) echo -e "USO: \e[40;36m$0\e[m \e[40;33m[-v]\e[40;33;1m -e<EXERCÍCIO> < -r<qtdExecucoes> , -d > \e[m"; exit 1;;
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
