#!/usr/bin/env bats

load ../../lib/test_helper

##########################################################
CODE_EXERCICIOS56_1="../main.cc"
CODE_EXERCICIOS56_2="../ordenacaoAnalytics.cc"
CODE_EXERCICIOS56_3="../algoritmos/quicksort_sequencial.cpp"
CODE_EXERCICIOS56_4="../algoritmos/quicksort_paralelo.cpp"

EXEC_EXERCICIOS56=${CODE_EXERCICIOS56_1#../}
EXEC_EXERCICIOS56=${EXEC_EXERCICIOS56%.cc}

ARQUIVO_ENTRADA="test_input"
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



##================== TESTANDO EXECUTÁVEL ==================##

@test "[TC034] Saída Esperada Para '$ARQUIVO_ENTRADA' Usando o Sequencial" {
	executable_exists "$EXEC_EXERCICIOS56" || skip "'$EXEC_EXERCICIOS56' não encontrado!"

	run bash -c "./$EXEC_EXERCICIOS56 $ARQUIVO_ENTRADA | grep  -Po '(?<=ORDENADO:).+'"
	assert_success

	assert_equal "1057,3485,3886,6710,10971,14292" "${lines[0]}"
}

@test "[TC034] Saída Esperada Para '$ARQUIVO_ENTRADA' Usando o Paralelo" {
	executable_exists "$EXEC_EXERCICIOS56" || skip "'$EXEC_EXERCICIOS56' não encontrado!"

	run bash -c "./$EXEC_EXERCICIOS56 $ARQUIVO_ENTRADA --paralelo | grep  -Po '(?<=ORDENADO:).+'"
	assert_success

	assert_equal "1057,3485,3886,6710,10971,14292" "${lines[0]}"
}




##================== FIM DOS TESTES ==================##

@test "[TC036] Apagar Executável" {
	rm -rf "$EXEC_EXERCICIOS56"
	assert_success
}
