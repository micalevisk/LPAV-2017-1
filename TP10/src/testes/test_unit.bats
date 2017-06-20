#!/usr/bin/env bats

load test_helper

##################
ARQUIVO="test_input"
EXEC_NUMBERGENERATOR="numberGenerator"
EXEC_MAIN="main"
##################


#################################### TESTES ####################################

@test "[TC01] numberGenerator sem os 2 argumentos" {
	executable_exists "$EXEC_NUMBERGENERATOR" || skip "'$EXEC_NUMBERGENERATOR' não encontrado!"
	run ./$EXEC_NUMBERGENERATOR
	assert_fail

	assert_equal "${lines[0]}" "USAGE: ./$EXEC_NUMBERGENERATOR <output_text_file> <amount>"
}

@test "[TC02] numberGenerator saída esperada" {
	executable_exists "$EXEC_NUMBERGENERATOR" || skip "'$EXEC_NUMBERGENERATOR' não encontrado!"
	run ./$EXEC_NUMBERGENERATOR "____tmpfile" 2
	assert_success

	rm -f "____tmpfile"
	assert_equal "${#lines[@]}" "3"
}

@test "[TC03] Entrada e saída arquivo '${ARQUIVO}'" {
	executable_exists "$EXEC_MAIN" || skip "'$EXEC_MAIN' não encontrado!"

	run ./$EXEC_MAIN $ARQUIVO
	assert_success

	assert_equal "${lines[0]}" "105707361,348517155,388677745,671071951,1097177981,1429220927"
}
