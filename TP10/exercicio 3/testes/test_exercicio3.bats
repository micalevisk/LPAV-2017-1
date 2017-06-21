#!/usr/bin/env bats

load ../../lib/test_helper

#####################################################
CODE_EXERCICIO3="../exercicio3.cpp"
EXEC_EXERCICIO3=${CODE_EXERCICIO3#../}
EXEC_EXERCICIO3=${EXEC_EXERCICIO3%.cpp}

arrQtdThreads=(4 16 32 64 128 256 512 1024 2048 4096)
#####################################################



##================== TESTANDO AMBIENTE ==================##

@test "[TC000] Sistema Operacional Com Quantidade de Threads Suficientes" {
	run uname -s
	if [[ $SO == "Linux" || $SO == "Darwin" ]]; then
		run cat /proc/sys/kernel/threads-max
		assert_range "$output" ${arrQtdThreads[-1]}
	fi
}

@test "[TC001] Encontrar Código '$CODE_EXERCICIO3'" {
	file_exists "$CODE_EXERCICIO3"
	assert_success
}

@test "[TC002] Compilar Código '$CODE_EXERCICIO3'" {
	executable_exists "$EXEC_EXERCICIO3" && skip "'$CODE_EXERCICIO3' já compilado!"
	run g++ -std=c++11 -I../../lib $CODE_EXERCICIO3 -o $EXEC_EXERCICIO3 -lpthread -D MILLISECONDS -D DEBUG
	assert_success
}



##================== TESTANDO EXECUTÁVEL ==================##

@test "[TC003] Calcular Soma Para 32k" {
	executable_exists "$EXEC_EXERCICIO3" || skip "'$EXEC_EXERCICIO3' não encontrado!"

	entrada=$(echo 32000 ; echo {1..32000})
	somatorioEsperado=$(echo {1..32000} | tr ' ' '+' | bc)

	for i in ${arrQtdThreads[@]}
	do
		run ./$EXEC_EXERCICIO3 $i <<< "$entrada"
		assert_equal "$somatorioEsperado" "${lines[1]}"
		sleep 1
	done
}

@test "[TC004] Calcular Soma Para 64k" {
	executable_exists "$EXEC_EXERCICIO3" || skip "'$EXEC_EXERCICIO3' não encontrado!"

	entrada=$(echo 64000 ; echo {1..64000})
	somatorioEsperado=$(echo {1..64000} | tr ' ' '+' | bc)

	for i in ${arrQtdThreads[@]}
	do
		run ./$EXEC_EXERCICIO3 $i <<< "$entrada"
		assert_equal "$somatorioEsperado" "${lines[1]}"
		sleep 1
	done
}

@test "[TC005] Calcular Soma Para 128k" {
	executable_exists "$EXEC_EXERCICIO3" || skip "'$EXEC_EXERCICIO3' não encontrado!"

	entrada=$(echo 128000 ; echo {1..128000})
	somatorioEsperado=$(echo {1..128000} | tr ' ' '+' | bc)

	for i in ${arrQtdThreads[@]}
	do
		run ./$EXEC_EXERCICIO3 $i <<< "$entrada"
		assert_equal "$somatorioEsperado" "${lines[1]}"
		sleep 1
	done
}

@test "[TC006] Calcular Soma Para 256k" {
	executable_exists "$EXEC_EXERCICIO3" || skip "'$EXEC_EXERCICIO3' não encontrado!"

	entrada=$(echo 256000 ; echo {1..256000})
	somatorioEsperado=$(echo {1..256000} | tr ' ' '+' | bc)

	for i in ${arrQtdThreads[@]}
	do
		run ./$EXEC_EXERCICIO3 $i <<< "$entrada"
		assert_equal "$somatorioEsperado" "${lines[1]}"
		sleep 1
	done
}

@test "[TC007] Calcular Soma Para 512k" {
	executable_exists "$EXEC_EXERCICIO3" || skip "'$EXEC_EXERCICIO3' não encontrado!"

	entrada=$(echo 512000 ; echo {1..512000})
	somatorioEsperado=$(echo {1..512000} | tr ' ' '+' | bc)

	for i in ${arrQtdThreads[@]}
	do
		run ./$EXEC_EXERCICIO3 $i <<< "$entrada"
		assert_equal "$somatorioEsperado" "${lines[1]}"
		sleep 1
	done
}

@test "[TC008] Calcular Soma Para 1024k" {
	executable_exists "$EXEC_EXERCICIO3" || skip "'$EXEC_EXERCICIO3' não encontrado!"

	entrada=$(echo 1024000 ; echo {1..1024000})
	somatorioEsperado=$(echo {1..1024000} | tr ' ' '+' | bc)

	for i in ${arrQtdThreads[@]}
	do
		run ./$EXEC_EXERCICIO3 $i <<< "$entrada"
		assert_equal "$somatorioEsperado" "${lines[1]}"
		sleep 1
	done
}

@test "[TC009] Calcular Soma Para 2048k" {
	executable_exists "$EXEC_EXERCICIO3" || skip "'$EXEC_EXERCICIO3' não encontrado!"

	entrada=$(echo 2048000 ; echo {1..2048000})
	somatorioEsperado=$(echo {1..2048000} | tr ' ' '+' | bc)

	for i in ${arrQtdThreads[@]}
	do
		run ./$EXEC_EXERCICIO3 $i <<< "$entrada"
		assert_equal "$somatorioEsperado" "${lines[1]}"
		sleep 1
	done
}



##================== FIM DOS TESTES ==================##

@test "[TC010] Apagar Executável" {
	rm -rf "$EXEC_EXERCICIO3"
	assert_success
}
