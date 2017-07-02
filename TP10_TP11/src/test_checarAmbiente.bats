#!/usr/bin/env bats

load lib/test_helper

#########################################################################################
PATH_SCRIPTS="lib"

SCRIPT_GERAR_ENTRADAS="$PATH_SCRIPTS/gerarEntradas.sh"
SCRIPT_EXECUTAR_EXERCICIO="$PATH_SCRIPTS/executarExercicio.sh"
SCRIPT_CALCULAR_MEDIAS_EXERCICIO="$PATH_SCRIPTS/calcularMediasExercicio.sh"
SCRIPT_PLOT_MEDIAS_EXERCICIO="$PATH_SCRIPTS/plotMediasExercicio.sh"
SCRIPT_MANTER_SOMENTE_GRAFICOS_EXERCICIO="$PATH_SCRIPTS/manterSomenteGraficosExercicio.sh"

CODE_EXERCICIO1="exercicio 1/exercicio1.cpp"
CODE_EXERCICIO2="exercicio 2/exercicio2.cpp"
CODE_EXERCICIO3="exercicio 3/exercicio3.cpp"
#########################################################################################


##================== TESTANDO EXISTÊNCIAS DOS CÓDIGOS-FONTE DOS EXERCÍCIOS ==================##
@test "[TC01] O Código '$CODE_EXERCICIO1' Existe Como Leitura" {
	file_exists "$CODE_EXERCICIO1"
}

@test "[TC02] O Código '$CODE_EXERCICIO2' Existe Como Leitura" {
	file_exists "$CODE_EXERCICIO2"
}

@test "[TC03] O Código '$CODE_EXERCICIO3' Existe Como Leitura" {
	file_exists "$CODE_EXERCICIO3"
}


##================== TESTANDO EXISTÊNCIAS DOS SCRIPTS ==================##
@test "[TC04] O Script '$SCRIPT_GERAR_ENTRADAS' Existe Como Executável" {
	executable_exists "$SCRIPT_GERAR_ENTRADAS"
}

@test "[TC05] O Script '$SCRIPT_EXECUTAR_EXERCICIO' Existe Como Executável" {
	executable_exists "$SCRIPT_EXECUTAR_EXERCICIO"
}

@test "[TC06] O Script '$SCRIPT_CALCULAR_MEDIAS_EXERCICIO' Existe Como Executável" {
	executable_exists "$SCRIPT_CALCULAR_MEDIAS_EXERCICIO"
}

@test "[TC07] O Script '$SCRIPT_PLOT_MEDIAS_EXERCICIO' Existe Como Executável" {
	executable_exists "$SCRIPT_PLOT_MEDIAS_EXERCICIO"
}

@test "[TC08] O Script '$SCRIPT_MANTER_SOMENTE_GRAFICOS_EXERCICIO' Existe Como Executável" {
	executable_exists "$SCRIPT_MANTER_SOMENTE_GRAFICOS_EXERCICIO"
}


##================== TESTANDO OUTROS PROGRAMAS ==================##
@test "[TC09] O Programa 'gcc' Existe" {
	run command -v gcc
	assert_success
}

@test "[TC10] O Programa 'g++' Existe" {
	run command -v g++
	assert_success
}

@test "[TC11] O Programa 'awk' Existe" {
	run command -v awk
	assert_success
}

@test "[TC12] O Programa 'sed' Existe" {
	run command -v sed
	assert_success
}

@test "[TC13] O Programa 'gnuplot' Existe" {
	run command -v gnuplot
	assert_success
}


##================== TESTANDO PROGRAMAS BÁSICOS ==================##
@test "[TC14] O Programa 'cut' Existe" {
	run command -v cut
	assert_success
}

@test "[TC15] O Programa 'mkdir' Existe" {
	run command -v mkdir
	assert_success
}

@test "[TC16] O Programa 'rm' Existe" {
	run command -v rm
	assert_success
}

@test "[TC17] O Programa 'sleep' Existe" {
	run command -v sleep
	assert_success
}

@test "[TC18] O Programa 'sort' Existe" {
	run command -v sort
	assert_success
}
