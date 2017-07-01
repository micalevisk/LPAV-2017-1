#!/usr/bin/env bats

load ../../lib/test_helper

##########################################################
CODE_RANDOMGEN="../../randomNumbersGenerator.c"
EXEC_RANDOMGEN="${CODE_RANDOMGEN#../../}"
EXEC_RANDOMGEN="${EXEC_RANDOMGEN%.c}"

CODE_EXERCICIOS56_1="../main.cc"
CODE_EXERCICIOS56_2="../ordenacaoAnalytics.cc"
CODE_EXERCICIOS56_3="../algoritmos/quicksort_sequencial.cpp"
CODE_EXERCICIOS56_4="../algoritmos/quicksort_paralelo.cpp"

EXEC_EXERCICIOS56=${CODE_EXERCICIOS56_1#../}
EXEC_EXERCICIOS56=${EXEC_EXERCICIOS56%.cc}

ARQUIVO_ENTRADA="__test_input"
ARQUIVO_SAIDA_ESPERADA="__test_expected_output"
##########################################################


##================== TESTANDO AMBIENTE ==================##

@test "[TC032] Encontrar Código '$CODE_EXERCICIOS56_1'" {
	file_exists "$CODE_EXERCICIOS56_1"
	assert_success
}

@test "[TC033] Compilar Código '$CODE_EXERCICIOS56_1'" {
	executable_exists "$EXEC_EXERCICIOS56" && skip "'$CODE_EXERCICIOS56_1' já compilado!"
	run g++ -std=c++11 -I../../lib -lpthread $CODE_EXERCICIOS56_1 $CODE_EXERCICIOS56_2 $CODE_EXERCICIOS56_3 $CODE_EXERCICIOS56_4 -o $EXEC_EXERCICIOS56 -D DEBUG -D MILLISECONDS -D VERBOSE
	assert_success
}

@test "[TC034] Encontrar Código '$CODE_RANDOMGEN'" {
	file_exists "$CODE_RANDOMGEN"
	assert_success
}

@test "[TC035] Compilar Código '$CODE_RANDOMGEN'" {
	executable_exists "$EXEC_RANDOMGEN" && skip "'$CODE_RANDOMGEN' já compilado!"
	run gcc $CODE_RANDOMGEN -o $EXEC_RANDOMGEN
	assert_success
}


##================== TESTANDO EXECUTÁVEL ==================##

@test "[TC036] Gerar Arquivo de Entrada com Nome '$ARQUIVO_ENTRADA'" {
	executable_exists "$EXEC_RANDOMGEN" || skip "'$EXEC_RANDOMGEN' não encontrado!"
	run bash -c "./$EXEC_RANDOMGEN $ARQUIVO_ENTRADA 100 1000000 | sort -n | tr '\n' ' ' > $ARQUIVO_SAIDA_ESPERADA"
	assert_success
}

@test "[TC037] Saída Esperada Para '$ARQUIVO_ENTRADA' Usando o Sequencial" {
	executable_exists "$EXEC_EXERCICIOS56" || skip "'$EXEC_EXERCICIOS56' não encontrado!"

	run bash -c "diff -w $ARQUIVO_SAIDA_ESPERADA <(./$EXEC_EXERCICIOS56 $ARQUIVO_ENTRADA | grep  -Po '(?<=ORDENADO:).+' | tr ',' ' ')"
	assert_success
}

@test "[TC038] Saída Esperada Para '$ARQUIVO_ENTRADA' Usando o Paralelo" {
	executable_exists "$EXEC_EXERCICIOS56" || skip "'$EXEC_EXERCICIOS56' não encontrado!"

	run bash -c "diff -w $ARQUIVO_SAIDA_ESPERADA <(./$EXEC_EXERCICIOS56 $ARQUIVO_ENTRADA --paralelo | grep  -Po '(?<=ORDENADO:).+' | tr ',' ' ')"
	assert_success
}




##================== FIM DOS TESTES ==================##

@test "[TC039] Apagar Arquivos Gerados" {
	rm -f "$ARQUIVO_ENTRADA"
	rm -f "$ARQUIVO_SAIDA_ESPERADA"
	rm -f "$EXEC_RANDOMGEN"
	rm -f "$EXEC_EXERCICIOS56"
	assert_success
}
