/**
 * Exercício 10: Senha
 * @author Micael Levi
 * @date 12/05/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>

// ^[A-Z]+[a-z]+[0-9]+([!@#$%^&*)(_+=}{\|?<>/\\-]|]|\[)+$
#define EXPRESSAO "^[A-Z]+[a-z]+[0-9]+([!@#$%^&*)(_+=}{\\|?<>/-]|]|\\[)+$"


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
