#!/usr/bin/env bats
#TODO
load ../../lib/test_helper

#####################################
CODE_EXERCICIO56="../main.c"
EXEC_EXERCICIO56=${CODE_EXERCICIO56#../}
EXEC_EXERCICIO56=${EXEC_EXERCICIO56%.c}

ARQUIVO="test_input"
EXEC_NUMBERGENERATOR="numberGenerator"
EXEC_MAIN="main"
#####################################



@test "[] numberGenerator sem os 2 argumentos" {
	executable_exists "$EXEC_NUMBERGENERATOR" || skip "'$EXEC_NUMBERGENERATOR' não encontrado!"
	run ./$EXEC_NUMBERGENERATOR
	assert_fail

	assert_equal "${lines[0]}" "USAGE: ./$EXEC_NUMBERGENERATOR <output_text_file> <amount>"
}

@test "[] numberGenerator saída esperada" {
	executable_exists "$EXEC_NUMBERGENERATOR" || skip "'$EXEC_NUMBERGENERATOR' não encontrado!"
	run ./$EXEC_NUMBERGENERATOR "____tmpfile" 2
	assert_success

	rm -f "____tmpfile"
	assert_equal "${#lines[@]}" "3"
}

@test "[] Entrada e saída arquivo '${ARQUIVO}'" {
	executable_exists "$EXEC_MAIN" || skip "'$EXEC_MAIN' não encontrado!"

	run bash -c "./$EXEC_MAIN $ARQUIVO | grep  -Po '(?<=ORDENADO:).+'"
	assert_success

	assert_equal "${lines[0]}" "105707361,348517155,388677745,671071951,1097177981,1429220927"
}
