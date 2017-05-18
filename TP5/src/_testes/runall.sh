#!/bin/bash
g++ -std=c++11 -D ORDEM_MATRIZ=6  ../exercicio2.cc -o main

for i in entrada*
do
	[[ $i =~ [0-9]$ ]] && {
		echo "==== TESTANDO $i ===="
		diff -w $i-saida <(./main < $i 2> /dev/null)
	}
done

rm main*
