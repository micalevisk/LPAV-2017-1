// $('#block_result_' + 1827)
/**
 * Exercício 2: Parênteses e Colchetes usando Pilhas
 * @author Micael Levi
 * @date 03/31/2017
 */

#include <stdio.h>
#include <stdlib.h>

///////////////
char* pilha;
int posUltimo;
///////////////

bool isValid(char open){
	if(posUltimo == -1 || pilha[posUltimo]!=open) return false;
	posUltimo--;
	return true;
}

bool isBalanced(char* expr){
	for(posUltimo=-1; *expr; ++expr){
		char simbolo = *expr;

		if(simbolo == '(' || simbolo == '[') pilha[++posUltimo] = simbolo;//empilhar o caractere aberto
		else if(simbolo == ')'){
			if( !isValid('(') ) return false;
		}
		else if(simbolo == ']'){
			if( !isValid('[') ) return false;
		}
	}

	return posUltimo < 0;//a pilha deve estar vazia
}

main()
{
	pilha = (char*)malloc(sizeof(char)*100);
	char* expr = (char*)malloc(sizeof(char)*101);

	while((scanf("%s", expr)) && (expr[0] != '#'))
		printf("%s\n", isBalanced(expr) ? "SIM" : "NAO");
}
