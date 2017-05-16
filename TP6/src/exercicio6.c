/**
 * Exercício 6: Data de nascimento
 * @author Micael Levi
 * @date 12/05/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>

// ^([12][0-9]?|3[01]|[3-9])\/(0[1-9]|1[0-2])\/(19|20([0-9]{2}|1[0-7])$
#define EXPRESSAO "^([12][0-9]?|3[01]|[3-9])\\/(0[1-9]|1[0-2])\\/19|20([0-9]{2}|1[0-7])$"

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

	while((scanf("%s", entrada)) && (entrada[0] != '#'))
		printf("%s\n", er_match(entrada) ? "SIM" : "NAO");
}
