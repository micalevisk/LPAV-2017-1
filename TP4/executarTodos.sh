#!/bin/bash

declare -a aleatorios=("1k" "5k" "10k" "20k" "50k" "100k")

for N in "${aleatorios[@]}"
do
	read -p "Executar para $N elementos? (y) " -n1 -r
	[[ $REPLY =~ ^[Yy]$ ]] || continue
	echo
	echo "./main-generator.sh $N '' __dadoscoletados/" | sh

done

: '
for N in "${aleatorios[@]}"
do
	mkdir -p "__dadoscoletados/$N"
	mv "__dadoscoletados/${N//k/000}_*" "__dadoscoletados/$N"
done
'
