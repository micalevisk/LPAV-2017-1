#!/bin/bash
g++ -std=c++11 -D ORDEM_MATRIZ=6  ../exercicio2.cc -o main
[[ $? -eq 0 ]] && {

	for i in entrada*
	do
		[[ $i =~ [0-9]$ ]] && {
			echo "==== TESTANDO $i ===="
			diff -w <(tail -n6 $i) <(./main < $i 2> /dev/null)
		}
	done

	rm main*
}
