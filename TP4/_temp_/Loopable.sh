#!/bin/bash
# //
# //	v0.13-4
# //	Loopable - Loop Executable
# //	Run commands N times.
# //	Created by Micael Levi on 04/13/2017
# //	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
# //

declare -ri QTD_ARGS=2

[ $# -lt $QTD_ARGS ] && {
	echo -e "USAGE: \033[40;31;1m$0\033[0m \033[40;32;1m<N>\033[0m \033[40;35;1m<command>\033[0m"
	echo -e 'To run \033[40;35mcommand\033[0m \033[40;32mN\033[0m times.'
	exit 1
}

declare -i qtdExec="${1}"
shift
declare -r comando="${*:1}"

for i in $(seq 1 1 $qtdExec)
do
	echo "$comando" | sh
done
