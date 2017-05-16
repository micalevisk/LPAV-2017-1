/**
 * Exercício 1: RG
 * @author Micael Levi
 * @date 12/05/2017
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>

// ^\d{7}-\d$
#define EXPRESSAO "^[[:digit:]]{7}-[[:digit:]]$"

bool er_match(char* input, char* regex){
	regex_t expr;

	/* Compile regular expression */
	int reti = regcomp(&expr, regex, REG_EXTENDED|REG_NOSUB);

	if(reti){
		fprintf(stderr, "Erro Ao Compilar a RegExp!\n");
		exit(1);
	}

	/* Execute regular expression */
	reti = regexec(&expr, input, 0, NULL, 0);

	/* Free memory allocated to the pattern buffer by regcomp() */
	regfree(&expr);

	return !reti;
}



int main()
{
	char* entrada = malloc(sizeof(char)*51);

	while((scanf("%s", entrada)) && strcmp(entrada, "####"))
		printf("%s\n", er_match(entrada, EXPRESSAO) ? "SIM" : "NAO");
}
