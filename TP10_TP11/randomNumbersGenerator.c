//
//	[randomNumbersGenerator]
//	Created by Micael Levi on 06/21/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char* argv[])
{
	char* filename;
	int valuesAmount;
	FILE* outputFile;

	srand(time(NULL));

	if(argc < 3){
		fprintf(stdout, "USAGE: ");
		fprintf(stdout, "%s <output_text_file> <amount> [max_value]\n", argv[0]);
		return 1;
	}

	filename = argv[1];
	valuesAmount = atoi(argv[2]);
	if(valuesAmount < 0) return 2;

	outputFile = fopen(filename, "w");
	if(!outputFile){
		perror("ERROR: On Create File");
		return 3;
	}

	fprintf(outputFile, "%u\n", valuesAmount);

	unsigned long long int maxValue = ULLONG_MAX - 1;
	if(argc == 4) maxValue = strtoull(argv[3], (char **)NULL, 10);
	///Gera, insere e imprime os N números aleatórios
	for(unsigned i=0; i < valuesAmount; ++i){
		unsigned long long int randomNumber = rand() % (maxValue+1);
		fprintf(outputFile, "%llu\n", randomNumber);
		fprintf(stdout, "%llu%s", randomNumber, i!=valuesAmount-1 ? "\n" : "");
	}

	fclose(outputFile);

	return 0;
}
