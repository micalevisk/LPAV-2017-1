/**
 * Exercício 9: Preço do produto
 * @author Micael Levi
 * @date 12/05/2017
 */

// http://regexr.com/3fv68
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>

// ^RS\d{1,3}(\.\d{3})?,\d{2}$
// ^RS[1-9]{0,2}[0-9](\.\d{3})?,\d{2}$
#define EXPRESSAO "^RS[[:digit:]]{1,3}(\\.[[:digit:]]{3})?,[[:digit:]]{2}$"

bool er_match(char* input){
	regex_t expr;
	if( regcomp(&expr, EXPRESSAO, REG_EXTENDED|REG_NOSUB) ){
		fprintf(stderr, "Could not compile regex\n");
		exit(1);
	}

	return !regexec(&expr, input, 0, NULL, 0);
}



int main()
{
	char* entrada = malloc(sizeof(char)*51);

	while((scanf("%s", entrada)) && strcmp(entrada, "####"))
		printf("%s\n", er_match(entrada) ? "SIM" : "NAO");
}
