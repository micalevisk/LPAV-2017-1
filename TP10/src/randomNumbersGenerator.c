#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
	char* filename;
	int valuesAmount;
	FILE* outputFile;

	srand(time(NULL));

	if(argc != 3){
		fprintf(stdout, "USAGE: ");
		fprintf(stdout, "%s <output_text_file> <amount>\n", argv[0]);
		return 1;
	}

	filename = argv[1];
	valuesAmount = atoi(argv[2]);

	outputFile = fopen(filename, "w");
	if(!outputFile){
		perror("ERROR: On Create File");
		return 2;
	}

	fprintf(outputFile, "%d\n", valuesAmount);
	fprintf(stdout, "%d\n", valuesAmount);

	///Gera, insere e imprime os N números aleatórios
	for(unsigned i=0; i < valuesAmount; ++i){
		int randomNumber = rand();
		fprintf(outputFile, "%d\n", randomNumber);
		fprintf(stdout, "%d\n", randomNumber);
	}

	fclose(outputFile);

	return 0;
}
