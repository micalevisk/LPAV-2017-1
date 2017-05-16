/**
 * Exercício 2: CEP
 * @author Micael Levi
 * @date 12/05/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>

// ^\d{5}-\d{3}$
#define EXPRESSAO "^[[:digit:]]{5}-[[:digit:]]{3}$"

bool er_match(char* input){
	regex_t expr;

	/* Compile regular expression */
	int reti = regcomp(&expr, EXPRESSAO, REG_EXTENDED|REG_NOSUB);

	if(reti){
		fprintf(stderr, "Could not compile regex\n");
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

	while((scanf("%s", entrada)) && (entrada[0] != '#'))
		printf("%s\n", er_match(entrada) ? "SIM" : "NAO");
}
